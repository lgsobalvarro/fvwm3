/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/****************************************************************************
 * This module is all new
 * by Rob Nation
 * A little of it is borrowed from ctwm.
 * Copyright 1993 Robert Nation. No restrictions are placed on this code,
 * as long as the copyright notice is preserved
 ****************************************************************************/
/***********************************************************************
 *
 * fvwm window-list popup code
 *
 ***********************************************************************/

#include "config.h"

#include <stdio.h>
#include <limits.h>

#include "libs/fvwmlib.h"
#include <libs/gravity.h>
#include <libs/FScreen.h>
#include "fvwm.h"
#include "externs.h"
#include "cursor.h"
#include "functions.h"
#include "bindings.h"
#include "misc.h"
#include "screen.h"
#include "fvwmlib.h"
#include "menus.h"
#include "conditional.h"
#include "stack.h"
#include "focus.h"
#include "virtual.h"
#include "geometry.h"

extern FvwmWindow *Fw;

#define SHOW_GEOMETRY		(1<<0)
#define SHOW_ALLDESKS		(1<<1)
#define SHOW_NORMAL		(1<<2)
#define SHOW_ICONIC		(1<<3)
#define SHOW_STICKY		(1<<4)
#define NO_DESK_SORT		(1<<6)
#define SHOW_ICONNAME		(1<<7)
#define SHOW_ALPHABETIC		(1<<8)
#define SORT_CLASSNAME		(1<<9)
#define SORT_REVERSE		(1<<10)
#define SHOW_INFONOTGEO		(1<<11)
#define NO_DESK_NUM		(1<<12)
#define NO_CURRENT_DESK_TITLE	(1<<13)
#define TITLE_FOR_ALL_DESKS	(1<<14)
#define NO_NUM_IN_DESK_TITLE	(1<<15)
#define SHOW_PAGE_X		(1<<16)
#define SHOW_PAGE_Y		(1<<17)
#define NO_LAYER		(1<<18)
#define SHOW_SCREEN		(1<<19)
#define SHOW_DEFAULT (SHOW_GEOMETRY | SHOW_ALLDESKS | SHOW_NORMAL | \
	SHOW_ICONIC | SHOW_STICKY)

static char *get_desk_title(int desk, unsigned long flags, Bool is_top_title)
{
	char *desk_name;
	char *tlabel;

	desk_name = GetDesktopName(desk);
	if (desk_name != NULL)
	{
		tlabel = (char *)safemalloc(strlen(desk_name)+50);
	}
	else
	{
		tlabel = (char *)safemalloc(50);
	}

	if (desk_name != NULL)
	{
		if (flags & NO_NUM_IN_DESK_TITLE)
		{
			sprintf(tlabel, "%s%s", desk_name,
				(is_top_title && (flags & SHOW_GEOMETRY)) ?
				"\tGeometry" : "");
		}
		else
		{
			sprintf(tlabel,"%d: %s%s", desk, desk_name,
				(is_top_title && (flags & SHOW_GEOMETRY)) ?
				"\tGeometry" : "");
		}
	}
	else
	{
		sprintf(tlabel,"Desk: %d%s",desk,
			(is_top_title && (flags & SHOW_GEOMETRY)) ?
			"\tGeometry" : "");
	}

	return tlabel;
}

/* Function to compare window title names */
static int visibleCompare(const  FvwmWindow **a, const FvwmWindow **b)
{
	return strcasecmp((*a)->visible_name, (*b)->visible_name);
}

static int iconCompare(const FvwmWindow **a, const FvwmWindow **b)
{
	return strcasecmp((*a)->visible_icon_name, (*b)->visible_icon_name);
}

/* Which of the compare functions to sort on. */
static int (*compare)(const FvwmWindow **a, const FvwmWindow **b);

static int classCompare(const FvwmWindow **a, const FvwmWindow **b)
{
	int result = strcasecmp((*a)->class.res_class, (*b)->class.res_class);

	if (result)
	{
		return result;
	}

	return strcasecmp((*a)->visible_name, (*b)->visible_name);
}

static int classIconCompare(const FvwmWindow **a, const FvwmWindow **b)
{
	int result = strcasecmp((*a)->class.res_class,
				(*b)->class.res_class);
	if (result)
	{
		return result;
	}

	return strcasecmp((*a)->visible_icon_name, (*b)->visible_icon_name);
}

static int compareReverse(const  FvwmWindow **a, const  FvwmWindow **b)
{
	return -compare(a, b);
}

/*
 * Change by PRB (pete@tecc.co.uk), 31/10/93.  Prepend a hot key
 * specifier to each item in the list.  This means allocating the
 * memory for each item (& freeing it) rather than just using the window
 * title directly. */
void CMD_WindowList(F_CMD_ARGS)
{
	MenuRoot *mr;
	MenuParameters mp;
	char* ret_action = NULL;
	FvwmWindow *t;
	FvwmWindow **windowList;
	FvwmWindow **iconifiedList = NULL;
	int numWindows;
	int ii;
	char tname[128];
	char loc[64];
	char *name=NULL;
	int dwidth;
	int dheight;
	char *tlabel;
	int last_desk_done = INT_MIN;
	int last_desk_displayed = INT_MIN;
	int next_desk = 0;
	char *t_hot=NULL;             /* Menu label with hotkey added */
	char scut = '0';              /* Current short cut key */
	char *opts=NULL;
	char *tok=NULL;
	int desk = Scr.CurrentDesk;
	unsigned long flags = SHOW_DEFAULT;
	char *func = NULL;
	char *tfunc = NULL;
	char *default_action = NULL;
	MenuReturn mret;
	const XEvent *teventp;
	MenuOptions mops;
	int low_layer = 0;  /* show all layers by default */
	int high_layer = INT_MAX;
	int max_label_width = 0;
	int tc;
	int show_listskip = 0; /* do not show listskip by default */
	Bool use_hotkey = True;
	KeyCode old_sor_keycode;
	char sor_default_keyname[8] = { 'M', 'e', 't', 'a', '_', 'L' };
	char *sor_keyname = sor_default_keyname;
	/* Condition vars. */
	Bool use_condition = False;
	Bool current_at_end = False;
	Bool iconified_at_end = False;
	int ic = 0;
	int ij;
	WindowConditionMask mask;
	char *cond_flags;
	Bool first_desk = True;
	Bool empty_menu = True;
	Bool was_get_menu_opts_called = False;

	memset(&mops, 0, sizeof(mops));
	memset(&mret, 0, sizeof(MenuReturn));
	/* parse postitioning args - must call this even if no action is given
	 * because it sets the xinerama screen origin */
	if (action && *action)
	{
		/* Look for condition - CreateFlagString returns NULL if no '('
		 * or '[' */
		cond_flags = CreateFlagString(action, &action);
		if (cond_flags)
		{
			/* Create window mask */
			use_condition = True;
			DefaultConditionMask(&mask);

			/* override for Current [] */
			mask.my_flags.use_circulate_hit = 1;
			mask.my_flags.use_circulate_hit_icon = 1;

			CreateConditionMask(cond_flags, &mask);
			free(cond_flags);
		}
		opts = get_menu_options(
			action, w, fw, NULL, NULL, NULL, &mops);
		was_get_menu_opts_called = True;

		/* parse options */
		while (opts && *opts)
		{
			opts = GetNextSimpleOption(opts, &tok);
			if (!tok)
			{
				break;
			}

			if (StrEquals(tok,"NoHotkeys"))
			{
				use_hotkey = False;
			}
			else if (StrEquals(tok,"Function"))
			{
				opts = GetNextSimpleOption(opts, &func);
			}
			else if (StrEquals(tok,"Desk"))
			{
				free(tok);
				opts = GetNextSimpleOption(opts, &tok);
				if (tok)
				{
					desk = atoi(tok);
					flags &= ~SHOW_ALLDESKS;
				}
			}
			else if (StrEquals(tok,"CurrentDesk"))
			{
				desk = Scr.CurrentDesk;
				flags &= ~SHOW_ALLDESKS;
			}
			else if (StrEquals(tok,"NotAlphabetic"))
			{
				flags &= ~SHOW_ALPHABETIC;
			}
			else if (StrEquals(tok,"Alphabetic"))
			{
				flags |= SHOW_ALPHABETIC;
			}
			else if (StrEquals(tok,"SortClassName"))
			{
				flags |= SORT_CLASSNAME;
			}
			else if (StrEquals(tok,"ReverseOrder"))
			{
				flags |= SORT_REVERSE;
			}
			else if (StrEquals(tok,"CurrentAtEnd"))
			{
				current_at_end = True;
			}
			else if (StrEquals(tok,"IconifiedAtEnd"))
			{
				iconified_at_end = True;
			}
			else if (StrEquals(tok,"NoDeskSort"))
			{
				flags |= NO_DESK_SORT;
			}
			else if (StrEquals(tok,"ShowPage"))
			{
				flags |= SHOW_PAGE_X | SHOW_PAGE_Y;
			}
			else if (StrEquals(tok,"ShowPageX"))
			{
				flags |= SHOW_PAGE_X;
			}
			else if (StrEquals(tok,"ShowPageY"))
			{
				flags |= SHOW_PAGE_Y;
			}
			else if (StrEquals(tok,"ShowScreen"))
			{
				flags |= SHOW_SCREEN;
			}
			else if (StrEquals(tok,"UseIconName"))
			{
				flags |= SHOW_ICONNAME;
			}
			else if (StrEquals(tok,"NoGeometry"))
			{
				flags &= ~SHOW_GEOMETRY;
				flags &= ~SHOW_INFONOTGEO;
			}
			else if (StrEquals(tok,"NoGeometryWithInfo"))
			{
				flags &= ~SHOW_GEOMETRY;
				flags |= SHOW_INFONOTGEO;
			}
			else if (StrEquals(tok,"Geometry"))
			{
				flags |= SHOW_GEOMETRY;
				flags &= ~SHOW_INFONOTGEO;
			}
			else if (StrEquals(tok,"NoIcons"))
			{
				flags &= ~SHOW_ICONIC;
			}
			else if (StrEquals(tok,"Icons"))
			{
				flags |= SHOW_ICONIC;
			}
			else if (StrEquals(tok,"OnlyIcons"))
			{
				flags = SHOW_ICONIC;
			}
			else if (StrEquals(tok,"NoNormal"))
			{
				flags &= ~SHOW_NORMAL;
			}
			else if (StrEquals(tok,"Normal"))
			{
				flags |= SHOW_NORMAL;
			}
			else if (StrEquals(tok,"OnlyNormal"))
			{
				flags = SHOW_NORMAL;
			}
			else if (StrEquals(tok,"NoSticky"))
			{
				flags &= ~SHOW_STICKY;
			}
			else if (StrEquals(tok,"Sticky"))
			{
				flags |= SHOW_STICKY;
			}
			else if (StrEquals(tok,"OnlySticky"))
			{
				flags = SHOW_STICKY;
			}
			else if (StrEquals(tok,"UseListSkip"))
			{
				show_listskip = 1;
			}
			else if (StrEquals(tok,"OnlyListSkip"))
			{
				show_listskip = 2;
			}
			else if (StrEquals(tok,"NoDeskNum"))
			{
				flags |= NO_DESK_NUM;
			}
			else if (StrEquals(tok,"NoLayer"))
			{
				flags |= NO_LAYER;
			}
			else if (StrEquals(tok,"NoCurrentDeskTitle"))
			{
				flags |= NO_CURRENT_DESK_TITLE;
			}
			else if (StrEquals(tok,"TitleForAllDesks"))
			{
				flags |= TITLE_FOR_ALL_DESKS;
			}
			else if (StrEquals(tok,"NoNumInDeskTitle"))
			{
				flags |= NO_NUM_IN_DESK_TITLE;
			}
			/* these are a bit dubious, but we should keep the
			 * OnTop options for compatibility */
			else if (StrEquals(tok, "NoOnTop"))
			{
				if (high_layer >= Scr.TopLayer)
				{
					high_layer = Scr.TopLayer - 1;
				}
			}
			else if (StrEquals(tok, "OnTop"))
			{
				if (high_layer < Scr.TopLayer)
				{
					high_layer = Scr.TopLayer;
				}
			}
			else if (StrEquals(tok, "OnlyOnTop"))
			{
				high_layer = low_layer = Scr.TopLayer;
			}
			else if (StrEquals(tok, "NoOnBottom"))
			{
				if (low_layer <= Scr.BottomLayer)
				{
					low_layer = Scr.BottomLayer - 1;
				}
			}
			else if (StrEquals(tok, "OnBottom"))
			{
				if (low_layer > Scr.BottomLayer)
				{
					low_layer = Scr.BottomLayer;
				}
			}
			else if (StrEquals(tok, "OnlyOnBottom"))
			{
				high_layer = low_layer = Scr.BottomLayer;
			}
			else if (StrEquals(tok, "Layer"))
			{
				free(tok);
				opts = GetNextSimpleOption(opts, &tok);
				if (tok)
				{
					low_layer = high_layer = atoi(tok);
					free(tok);
					opts = GetNextSimpleOption(opts, &tok);
					if (tok)
					{
						high_layer = atoi(tok);
					}
				}
			}
			else if (StrEquals(tok, "SelectOnRelease"))
			{
				if (sor_keyname != sor_default_keyname)
				{
					free(sor_keyname);
				}
				sor_keyname = NULL;
				opts = GetNextSimpleOption(opts, &sor_keyname);
			}
			else if (StrEquals(tok, "MaxLabelWidth"))
			{
				char *wid;

				opts = GetNextSimpleOption(opts, &wid);
				if (wid)
				{
					max_label_width = atoi(wid);
					if (max_label_width < 1)
					{
						max_label_width = 1;
					}
					free(wid);
				}
			}
			else if (!opts || !*opts)
			{
				default_action = safestrdup(tok);
			}
			else
			{
				fvwm_msg(
					ERR, "WindowList","Unknown option '%s'",
					tok);
			}
			if (tok)
			{
				free(tok);
			}
		}
	}
	if (was_get_menu_opts_called == False)
	{
		opts = get_menu_options(
			action, w, fw, NULL, NULL, NULL, &mops);
	}

	tlabel = get_desk_title(desk, flags, True);
	mr = NewMenuRoot(tlabel);
	if (!(flags & NO_CURRENT_DESK_TITLE))
	{
		AddToMenu(mr, tlabel, "TITLE", False, False, False);
		empty_menu = False;
	}
	free(tlabel);

	numWindows = 0;
	for (t = Scr.FvwmRoot.next; t != NULL; t = t->next)
	{
		numWindows++;
	}
	windowList = malloc(numWindows*sizeof(t));
	if (windowList == NULL)
	{
		return;
	}
	if (iconified_at_end)
	{
		iconifiedList = malloc(numWindows*sizeof(t));
		if (iconifiedList == NULL)
		{
			return;
		}
	}
	/* get the windowlist starting from the current window (if any)*/
	t = get_focus_window();
	if (t == NULL)
	{
		t = Scr.FvwmRoot.next;
	}
	else if (current_at_end)
	{
		if (t->next)
		{
			t = t->next;
		}
		else
		{
			t = Scr.FvwmRoot.next;
		}
	}
	for (ii = 0; ii < numWindows; ii++)
	{
		if (flags & SORT_REVERSE)
		{
			windowList[numWindows - ii - 1] = t;
		}
		else if (iconified_at_end && IS_ICONIFIED(t))
		{
			iconifiedList[ic++] = t;
		}
		else
		{
			windowList[ii - ic] = t;
		}
		if (t->next)
		{
			t = t->next;
		}
		else
		{
			t = Scr.FvwmRoot.next;
		}
	}
	if (iconified_at_end && ic > 0)
	{
		if (current_at_end)
		{
			windowList[numWindows - 1] = windowList[--ii - ic];
		}
		for (ij = 0; ij < ic; ij++)
		{
			windowList[ij + (ii - ic)] = iconifiedList[ij];
		}
	}

	/* Do alphabetic sort */
	if (flags & (SHOW_ALPHABETIC | SORT_CLASSNAME))
	{
		/* This will be compare or compareReverse if a reverse order
		 * is selected. */
		int (*sort)(const FvwmWindow **a, const FvwmWindow **b);

		switch(flags & (SHOW_ALPHABETIC|SHOW_ICONNAME|SORT_CLASSNAME))
		{
		case SHOW_ALPHABETIC:
			compare = visibleCompare;
			break;
		case SHOW_ALPHABETIC|SHOW_ICONNAME:
			compare = iconCompare;
			break;
			/* Sorting based on class name produces an alphabetic
			 * order so the keyword alphabetic is redundant. */
		case SORT_CLASSNAME:
		case SORT_CLASSNAME|SHOW_ALPHABETIC:
			compare = classCompare;
			break;
		case SORT_CLASSNAME|SHOW_ICONNAME:
		case SORT_CLASSNAME|SHOW_ALPHABETIC|SHOW_ICONNAME:
			compare = classIconCompare;
			break;
			/* All current cases are covered, but if something
			 * changes in the future we leave compare valid even if
			 * it isn't what is expected. */
		default:
			compare = visibleCompare;
			break;
		}

		if ( flags & SORT_REVERSE )
		{
			sort = compareReverse;
		}
		else
		{
			sort = compare;
		}
		qsort(windowList, numWindows, sizeof(t),
		      (int(*)(const void*, const void*))sort);
	}

	while(next_desk != INT_MAX)
	{
		/* Sort window list by desktop number */
		if ((flags & SHOW_ALLDESKS) && !(flags & NO_DESK_SORT))
		{
			/* run through the windowlist finding the first desk
			 * not already processed */
			next_desk = INT_MAX;
			for (ii = 0; ii < numWindows; ii++)
			{
				t = windowList[ii];
				if (t->Desk >last_desk_done &&
				    t->Desk < next_desk)
				{
					next_desk = t->Desk;
				}
			}
		}
		if (!(flags & SHOW_ALLDESKS))
		{
			/* if only doing one desk and it hasn't been done */
			if (last_desk_done  == INT_MIN)
				next_desk = desk; /* select the desk */
			else
				next_desk = INT_MAX; /* flag completion */
		}
		if (flags & NO_DESK_SORT)
			next_desk = INT_MAX; /* only go through loop once */

		last_desk_done = next_desk;
		for (ii = 0; ii < numWindows; ii++)
		{
			t = windowList[ii];
			if (((t->Desk == next_desk) || (flags & NO_DESK_SORT)))
			{
				if (!show_listskip && DO_SKIP_WINDOW_LIST(t))
				{
					/* don't want listskip windows - skip */
					continue;
				}
				if (show_listskip == 2 &&
				    !DO_SKIP_WINDOW_LIST(t))
				{
					/* don't want no listskip one - skip */
					continue;
				}
				if (use_condition &&
				    !MatchesConditionMask(t, &mask))
				{
					/* doesn't match specified condition */
					continue;
				}
				if (!(flags & SHOW_ICONIC) && (IS_ICONIFIED(t)))
				{
					/* don't want icons - skip */
					continue;
				}
				if (!(flags & SHOW_STICKY) && (IS_STICKY(t)))
				{
					/* don't want sticky ones - skip */
					continue;
				}
				if (!(flags & SHOW_NORMAL) &&
				    !((IS_ICONIFIED(t)) || (IS_STICKY(t))))
				{
					/* don't want "normal" ones - skip */
					continue;
				}
				if (get_layer(t) < low_layer ||
				    get_layer(t) > high_layer)
				{
					/* don't want this layer */
					continue;
				}

				empty_menu = False;
				/* add separator between desks when geometry
				 * shown but not at the top*/
				if (t->Desk != last_desk_displayed)
				{
					if (last_desk_displayed != INT_MIN)
					{
						if (((flags & SHOW_GEOMETRY) ||
						     (flags &
						      SHOW_INFONOTGEO)) &&
						    !(flags &
						      TITLE_FOR_ALL_DESKS))
						{
							AddToMenu(
								mr, NULL, NULL,
								False, False,
								False);
						}
						if (flags & TITLE_FOR_ALL_DESKS)
						{
							tlabel = get_desk_title(
								t->Desk, flags,
								False);
							AddToMenu(
								mr, tlabel,
								"TITLE", False,
								False, False);
							free(tlabel);
						}
					}
					last_desk_displayed = t->Desk;
				}
				if (first_desk && flags & TITLE_FOR_ALL_DESKS)
				{
					tlabel = get_desk_title(
						t->Desk, flags, False);
					AddToMenu(
						mr, tlabel, "TITLE", False,
						False, False);
					free(tlabel);
				}
				first_desk = False;

				if (flags & SHOW_ICONNAME)
				{
					name = t->visible_icon_name;
				}
				else
				{
					name = t->visible_name;
				}

				if (!name)
				{
					name = "NULL_NAME";
				}
				else if (max_label_width > 0 &&
					 strlen(name) > max_label_width)
				{
					name = strdup(name);
					name[max_label_width] = '\0';
				}

				t_hot = safemalloc(strlen(name) + 80);
				if (use_hotkey)
				{
					/* Generate label */
					sprintf(t_hot, "&%c. ", scut);
				}
				else
				{
					*t_hot = 0;
				}
				if (!(flags & SHOW_INFONOTGEO))
				{
					strcat(t_hot, name);
				}
				if (*t_hot == 0)
				{
					strcpy(t_hot, " ");
				}

				/* Next shortcut key */
				if (scut == '9')
				{
					scut = 'A';
				}
				else if (scut == 'Z')
				{
					scut = '0';
				}
				else
				{
					scut++;
				}

				if (flags & SHOW_INFONOTGEO)
				{
					tname[0]=0;
					if (!IS_ICONIFIED(t) &&
					    !(flags & NO_DESK_NUM))
					{
						sprintf(loc,"%d:", t->Desk);
						strcat(tname,loc);
					}
					if (IS_ICONIFIED(t))
					{
						strcat(tname, "(");
					}
					strcat(t_hot,"\t");
					strcat(t_hot,tname);
					strcat(t_hot, name);
					if (IS_ICONIFIED(t))
					{
						strcat(t_hot, ")");
					}
				}
				else if (flags & SHOW_GEOMETRY)
				{
					size_borders b;

					tname[0]=0;
					if (IS_ICONIFIED(t))
					{
						strcpy(tname, "(");
						strcat(tname, loc);
					}
					if (!(flags & NO_DESK_NUM))
					{
						sprintf(loc, "%d", t->Desk);
						strcat(tname, loc);
					}
					if (flags & SHOW_SCREEN)
					{
						fscreen_scr_arg fscr;
						int scr;

						fscr.xypos.x =
							Scr.Vx + t->frame_g.x +
							t->frame_g.width / 2;
						fscr.xypos.y =
							Scr.Vy + t->frame_g.y +
							t->frame_g.height / 2;
						scr = FScreenGetScrId(
							&fscr, FSCREEN_XYPOS);
						sprintf(loc, "@%d", scr);
						strcat(tname, loc);
					}
					if (flags & SHOW_PAGE_X)
					{
						sprintf(loc, "+%d",
							(Scr.Vx + t->frame_g.x +
							 t->frame_g.width / 2) /
							Scr.MyDisplayWidth);
						strcat(tname, loc);
					}
					if (flags & SHOW_PAGE_Y)
					{
						sprintf(loc, "+%d",
							(Scr.Vy + t->frame_g.y +
							 t->frame_g.height/2) /
							Scr.MyDisplayHeight);
						strcat(tname, loc);
					}
					if (!(flags & NO_LAYER))
					{
						sprintf(loc, "(%d)",
							(get_layer(t)));
						strcat(tname, loc);
					}
					strcat(tname, ":");
					get_window_borders(t, &b);
					dheight = t->frame_g.height -
						b.total_size.height;
					dwidth = t->frame_g.width -
						b.total_size.width;
					dwidth -= t->hints.base_width;
					dheight -= t->hints.base_height;
					dwidth /= t->hints.width_inc;
					dheight /= t->hints.height_inc;

					sprintf(loc,"%d",dwidth);
					strcat(tname, loc);
					sprintf(loc,"x%d",dheight);
					strcat(tname, loc);
					if (t->frame_g.x >=0)
					{
						sprintf(loc,"+%d",t->frame_g.x);
					}
					else
					{
						sprintf(loc,"%d",t->frame_g.x);
					}
					strcat(tname, loc);
					if (t->frame_g.y >=0)
					{
						sprintf(loc,"+%d",t->frame_g.y);
					}
					else
					{
						sprintf(loc,"%d",t->frame_g.y);
					}
					strcat(tname, loc);

					if (IS_STICKY(t))
					{
						strcat(tname, " S");
					}
					if (IS_ICONIFIED(t))
					{
						strcat(tname, ")");
					}
					strcat(t_hot,"\t");
					strcat(t_hot,tname);
				}
				if (!func)
				{
					tfunc = safemalloc(40);
					sprintf(tfunc, "WindowListFunc %lu",
						FW_W(t));
				}
				else
				{
					tfunc = safemalloc(strlen(func) + 32);
					sprintf(tfunc,"%s %lu", func, FW_W(t));
				}
				AddToMenu(
					mr, t_hot, tfunc, False, False, False);
				free(tfunc);
				/* Add the title pixmap */
				if (FMiniIconsSupported && t->mini_icon)
				{
					MI_MINI_ICON(MR_LAST_ITEM(mr))[0] =
						t->mini_icon;
					/* increase the cache count. Otherwise
					 * the pixmap will be eventually
					 * removed from the cache by
					 * DestroyMenu */
					t->mini_icon->count++;
				}
				if (t_hot)
				{
					free(t_hot);
				}
			}
		}
	}

	if (empty_menu)
	{
		/* force current desk title */
		tlabel = get_desk_title(desk, flags, True);
		AddToMenu(mr, tlabel, "TITLE", False, False, False);
		free(tlabel);
	}

	if (func)
	{
		free(func);
	}
	free(windowList);
	if (iconified_at_end)
	{
		free(iconifiedList);
	}
	if (!default_action && eventp && eventp->type == KeyPress)
	{
		teventp = (XEvent *)1;
	}
	else
	{
		teventp = eventp;
	}

	/* Use the WindowList menu style is there is one */
	change_mr_menu_style(mr, "WindowList");

	/* Activate select_on_release style */
	old_sor_keycode = MST_SELECT_ON_RELEASE_KEY(mr);
	if (sor_keyname &&
	    (!MST_SELECT_ON_RELEASE_KEY(mr) ||
	     sor_keyname != sor_default_keyname))
	{
		KeyCode keycode = 0;

		if (sor_keyname)
		{
			keycode = XKeysymToKeycode(
				dpy, FvwmStringToKeysym(dpy, sor_keyname));
		}
		MST_SELECT_ON_RELEASE_KEY(mr) =
			XKeysymToKeycode(
				dpy, FvwmStringToKeysym(dpy, sor_keyname));
	}

	memset(&mp, 0, sizeof(mp));
	mp.menu = mr;
	t = Fw;
	mp.pfw = &t;
	tc = context;
	mp.pcontext = &tc;
	mp.flags.has_default_action = (default_action && *default_action != 0);
	mp.flags.is_sticky = True;
	mp.flags.is_submenu = False;
	mp.flags.is_already_mapped = False;
	mp.eventp = teventp;
	mp.pops = &mops;
	mp.ret_paction = &ret_action;

	do_menu(&mp, &mret);
	/* Restore old menu style */
	MST_SELECT_ON_RELEASE_KEY(mr) = old_sor_keycode;
	if (ret_action)
	{
		free(ret_action);
	}
	DestroyMenu(mr, False, False);
	if (mret.rc == MENU_DOUBLE_CLICKED && default_action && *default_action)
	{
		old_execute_function(
			cond_rc, default_action, fw, eventp, context, *Module,
			0, NULL);
	}
	if (default_action != NULL)
	{
		free(default_action);
	}
	if (use_condition)
	{
		FreeConditionMask(&mask);
	}

	return;
}
