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

#ifndef _STYLE_
#define _STYLE_

/* access to the special flags of a style */
/* call these with a pointer to a style_flags struct */
#define SDO_DECORATE_TRANSIENT(sf) \
	((sf)->do_decorate_transient)
#define SDO_SAVE_UNDER(sf) \
	((sf)->do_save_under)
#define SDO_START_LOWERED(sf) \
	((sf)->do_start_lowered)
#define SHAS_BORDER_WIDTH(sf) \
	((sf)->has_border_width)
#define SHAS_COLOR_BACK(sf) \
	((sf)->has_color_back)
#define SHAS_COLOR_FORE(sf) \
	((sf)->has_color_fore)
#define SHAS_HANDLE_WIDTH(sf) \
	((sf)->has_handle_width)
#define SHAS_ICON(sf) \
	((sf)->has_icon)
#define SHAS_ICON_BOXES(sf) \
	((sf)->has_icon_boxes)
#define SHAS_ICON_SIZE_LIMITS(sf) \
	((sf)->has_icon_size_limits)
#define SHAS_MAX_WINDOW_SIZE(sf) \
	((sf)->has_max_window_size)
#define SHAS_WINDOW_SHADE_STEPS(sf) \
	((sf)->has_window_shade_steps)
#define SHAS_MINI_ICON(sf) \
	((sf)->has_mini_icon)
#define SHAS_MWM_DECOR(sf) \
	((sf)->has_mwm_decor)
#define SHAS_MWM_FUNCTIONS(sf) \
	((sf)->has_mwm_functions)
#define SHAS_NO_HANDLES(sf) \
	((sf)->has_no_handles)
#define SHAS_NO_TITLE(sf) \
	((sf)->has_no_title)
#define SHAS_OL_DECOR(sf) \
	((sf)->has_ol_decor)
#define SIS_BUTTON_DISABLED(sf) \
	((sf)->is_button_disabled)
#define SPLACEMENT_MODE(sf) \
	((sf)->placement_mode)
#define SEWMH_PLACEMENT_MODE(sf) \
	((sf)->ewmh_placement_mode)
#define SUSE_BACKING_STORE(sf) \
	((sf)->use_backing_store)
#define SUSE_PARENT_RELATIVE(sf) \
	((sf)->use_parent_relative)
#define SUSE_COLORSET(sf) \
	((sf)->use_colorset)
#define SUSE_COLORSET_HI(sf) \
	((sf)->use_colorset_hi)
#define SUSE_BORDER_COLORSET(sf) \
	((sf)->use_border_colorset)
#define SUSE_BORDER_COLORSET_HI(sf) \
	((sf)->use_border_colorset_hi)
#define SUSE_LAYER(sf) \
	((sf)->use_layer)
#define SUSE_NO_PPOSITION(sf) \
	((sf)->use_no_pposition)
#define SUSE_NO_USPOSITION(sf) \
	((sf)->use_no_usposition)
#define SUSE_NO_TRANSIENT_PPOSITION(sf) \
	((sf)->use_no_transient_pposition)
#define SUSE_NO_TRANSIENT_USPOSITION(sf) \
	((sf)->use_no_transient_usposition)
#define SUSE_START_ON_DESK(sf) \
	((sf)->use_start_on_desk)
#define SUSE_START_ON_PAGE_FOR_TRANSIENT(sf) \
	((sf)->use_start_on_page_for_transient)
#define SUSE_START_ON_SCREEN(sf) \
	((sf)->use_start_on_screen)
#define SMANUAL_PLACEMENT_HONORS_STARTS_ON_PAGE(sf) \
	((sf)->manual_placement_honors_starts_on_page)
#define SCAPTURE_HONORS_STARTS_ON_PAGE(sf) \
	((sf)->capture_honors_starts_on_page)
#define SRECAPTURE_HONORS_STARTS_ON_PAGE(sf) \
	((sf)->recapture_honors_starts_on_page)
#define SHAS_PLACEMENT_PENALTY(sf) \
	((sf)->has_placement_penalty)
#define SHAS_PLACEMENT_PERCENTAGE_PENALTY(sf) \
	((sf)->has_placement_percentage_penalty)

/* access to common flags */
#define SFGET_COMMON_FLAGS(st) \
	((st).flags.common)
#define SFGET_COMMON_STATIC_FLAGS(st) \
	((st).flags.common.s)
#define SMGET_COMMON_FLAGS(st) \
	((st).flag_mask.common)
#define SMGET_COMMON_STATIC_FLAGS(st) \
	((st).flag_mask.common.s)
#define SCGET_COMMON_FLAGS(st) \
	((st).change_mask.common)
#define SCGET_COMMON_STATIC_FLAGS(st) \
	((st).change_mask.common.s)
#define SF_FOCUS_POLICY(st) \
	((st).flags.common.s.focus_policy)
#define SM_FOCUS_POLICY(st) \
	((st).flag_mask.common.s.focus_policy)
#define SC_FOCUS_POLICY(st) \
	((st).change_mask.common.s.focus_policy)
#define STITLE_DIR(sf) \
	((sf).common.title_dir)
#define SFTITLE_DIR(st) \
	((st).flags.common.title_dir)
#define SMTITLE_DIR(st) \
	((st).flag_mask.common.title_dir)
#define SCTITLE_DIR(st) \
	((st).change_mask.common.title_dir)
#define SFSET_TITLE_DIR(st,x) \
	((st).flags.common.title_dir = x)
#define SMSET_TITLE_DIR(st,x) \
	((st).flag_mask.common.title_dir = DIR_MAJOR_MASK * !!(x))
#define SCSET_TITLE_DIR(st,x) \
	((st).change_mask.common.title_dir = DIR_MAJOR_MASK * !!(x))
#define SIS_STICKY(sf) \
	((sf).common.is_sticky)
#define SFIS_STICKY(st) \
	((st).flags.common.is_sticky)
#define SMIS_STICKY(st) \
	((st).flag_mask.common.is_sticky)
#define SCIS_STICKY(st) \
	((st).change_mask.common.is_sticky)
#define SFSET_IS_STICKY(st,x) \
	((st).flags.common.is_sticky = !!(x))
#define SMSET_IS_STICKY(st,x) \
	((st).flag_mask.common.is_sticky = !!(x))
#define SCSET_IS_STICKY(st,x) \
	((st).change_mask.common.is_sticky = !!(x))
#define SDO_CIRCULATE_SKIP(sf) \
	((sf).common.s.do_circulate_skip)
#define SFDO_CIRCULATE_SKIP(st) \
	((st).flags.common.s.do_circulate_skip)
#define SMDO_CIRCULATE_SKIP(st) \
	((st).flag_mask.common.s.do_circulate_skip)
#define SCDO_CIRCULATE_SKIP(st) \
	((st).change_mask.common.s.do_circulate_skip)
#define SFSET_DO_CIRCULATE_SKIP(st,x) \
	((st).flags.common.s.do_circulate_skip = !!(x))
#define SMSET_DO_CIRCULATE_SKIP(st,x) \
	((st).flag_mask.common.s.do_circulate_skip = !!(x))
#define SCSET_DO_CIRCULATE_SKIP(st,x) \
	((st).change_mask.common.s.do_circulate_skip = !!(x))
#define SDO_CIRCULATE_SKIP_ICON(sf) \
	((sf).common.s.do_circulate_skip_icon)
#define SFDO_CIRCULATE_SKIP_ICON(st) \
	((st).flags.common.s.do_circulate_skip_icon)
#define SMDO_CIRCULATE_SKIP_ICON(st) \
	((st).flag_mask.common.s.do_circulate_skip_icon)
#define SCDO_CIRCULATE_SKIP_ICON(st) \
	((st).change_mask.common.s.do_circulate_skip_icon)
#define SFSET_DO_CIRCULATE_SKIP_ICON(st,x) \
	((st).flags.common.s.do_circulate_skip_icon = !!(x))
#define SMSET_DO_CIRCULATE_SKIP_ICON(st,x) \
	((st).flag_mask.common.s.do_circulate_skip_icon = !!(x))
#define SCSET_DO_CIRCULATE_SKIP_ICON(st,x) \
	((st).change_mask.common.s.do_circulate_skip_icon = !!(x))
#define SDO_CIRCULATE_SKIP_SHADED(sf) \
	((sf).common.s.do_circulate_skip_shaded)
#define SFDO_CIRCULATE_SKIP_SHADED(st) \
	((st).flags.common.s.do_circulate_skip_shaded)
#define SMDO_CIRCULATE_SKIP_SHADED(st) \
	((st).flag_mask.common.s.do_circulate_skip_shaded)
#define SCDO_CIRCULATE_SKIP_SHADED(st) \
	((st).change_mask.common.s.do_circulate_skip_shaded)
#define SFSET_DO_CIRCULATE_SKIP_SHADED(st,x) \
	((st).flags.common.s.do_circulate_skip_shaded = !!(x))
#define SMSET_DO_CIRCULATE_SKIP_SHADED(st,x) \
	((st).flag_mask.common.s.do_circulate_skip_shaded = !!(x))
#define SCSET_DO_CIRCULATE_SKIP_SHADED(st,x) \
	((st).change_mask.common.s.do_circulate_skip_shaded = !!(x))
#define SDO_GRAB_FOCUS_WHEN_CREATED(sf) \
	((sf).common.s.do_grab_focus_when_created)
#define SFDO_GRAB_FOCUS_WHEN_CREATED(st) \
	((st).flags.common.s.do_grab_focus_when_created)
#define SMDO_GRAB_FOCUS_WHEN_CREATED(st) \
	((st).flag_mask.common.s.do_grab_focus_when_created)
#define SCDO_GRAB_FOCUS_WHEN_CREATED(st) \
	((st).change_mask.common.s.do_grab_focus_when_created)
#define SFSET_DO_GRAB_FOCUS_WHEN_CREATED(st,x) \
	((st).flags.common.s.do_grab_focus_when_created = !!(x))
#define SMSET_DO_GRAB_FOCUS_WHEN_CREATED(st,x) \
	((st).flag_mask.common.s.do_grab_focus_when_created = !!(x))
#define SCSET_DO_GRAB_FOCUS_WHEN_CREATED(st,x) \
	((st).change_mask.common.s.do_grab_focus_when_created = !!(x))
#define SDO_GRAB_FOCUS_WHEN_TRANSIENT_CREATED(sf) \
	((sf).common.s.do_grab_focus_when_transient_created)
#define SFDO_GRAB_FOCUS_WHEN_TRANSIENT_CREATED(st) \
	((st).flags.common.s.do_grab_focus_when_transient_created)
#define SMDO_GRAB_FOCUS_WHEN_TRANSIENT_CREATED(st) \
	((st).flag_mask.common.s.do_grab_focus_when_transient_created)
#define SCDO_GRAB_FOCUS_WHEN_TRANSIENT_CREATED(st) \
	((st).change_mask.common.s.do_grab_focus_when_transient_created)
#define SFSET_DO_GRAB_FOCUS_WHEN_TRANSIENT_CREATED(st,x) \
	((st).flags.common.s.do_grab_focus_when_transient_created = !!(x))
#define SMSET_DO_GRAB_FOCUS_WHEN_TRANSIENT_CREATED(st,x) \
	((st).flag_mask.common.s.do_grab_focus_when_transient_created = !!(x))
#define SCSET_DO_GRAB_FOCUS_WHEN_TRANSIENT_CREATED(st,x) \
	((st).change_mask.common.s.do_grab_focus_when_transient_created = !!(x))
#define SDO_ICONIFY_WINDOW_GROUPS(sf) \
	((sf).common.s.do_iconify_window_groups)
#define SFDO_ICONIFY_WINDOW_GROUPS(st) \
	((st).flags.common.s.do_iconify_window_groups)
#define SMDO_ICONIFY_WINDOW_GROUPS(st) \
	((st).flag_mask.common.s.do_iconify_window_groups)
#define SCDO_ICONIFY_WINDOW_GROUPS(st) \
	((st).change_mask.common.s.do_iconify_window_groups)
#define SFSET_DO_ICONIFY_WINDOW_GROUPS(st,x) \
	((st).flags.common.s.do_iconify_window_groups = !!(x))
#define SMSET_DO_ICONIFY_WINDOW_GROUPS(st,x) \
	((st).flag_mask.common.s.do_iconify_window_groups = !!(x))
#define SCSET_DO_ICONIFY_WINDOW_GROUPS(st,x) \
	((st).change_mask.common.s.do_iconify_window_groups = !!(x))
#define SDO_IGNORE_GNOME_HINTS(sf) \
	((sf).common.s.do_ignore_gnome_hints)
#define SFDO_IGNORE_GNOME_HINTS(st) \
	((st).flags.common.s.do_ignore_gnome_hints)
#define SMDO_IGNORE_GNOME_HINTS(st) \
	((st).flag_mask.common.s.do_ignore_gnome_hints)
#define SCDO_IGNORE_GNOME_HINTS(st) \
	((st).change_mask.common.s.do_ignore_gnome_hints)
#define SFSET_DO_IGNORE_GNOME_HINTS(st,x) \
	((st).flags.common.s.do_ignore_gnome_hints = !!(x))
#define SMSET_DO_IGNORE_GNOME_HINTS(st,x) \
	((st).flag_mask.common.s.do_ignore_gnome_hints = !!(x))
#define SCSET_DO_IGNORE_GNOME_HINTS(st,x) \
	((st).change_mask.common.s.do_ignore_gnome_hints = !!(x))
#define SDO_IGNORE_ICON_BOXES(sf) \
	((sf).common.s.do_ignore_icon_boxes)
#define SFDO_IGNORE_ICON_BOXES(st) \
	((st).flags.common.s.do_ignore_icon_boxes)
#define SMDO_IGNORE_ICON_BOXES(st) \
	((st).flag_mask.common.s.do_ignore_icon_boxes)
#define SCDO_IGNORE_ICON_BOXES(st) \
	((st).change_mask.common.s.do_ignore_icon_boxes)
#define SFSET_DO_IGNORE_ICON_BOXES(st,x) \
	((st).flags.common.s.do_ignore_icon_boxes = !!(x))
#define SMSET_DO_IGNORE_ICON_BOXES(st,x) \
	((st).flag_mask.common.s.do_ignore_icon_boxes = !!(x))
#define SCSET_DO_IGNORE_ICON_BOXES(st,x) \
	((st).change_mask.common.s.do_ignore_icon_boxes = !!(x))
#define SDO_IGNORE_RESTACK(sf) \
	((sf).common.s.do_ignore_restack)
#define SFDO_IGNORE_RESTACK(st) \
	((st).flags.common.s.do_ignore_restack)
#define SMDO_IGNORE_RESTACK(st) \
	((st).flag_mask.common.s.do_ignore_restack)
#define SCDO_IGNORE_RESTACK(st) \
	((st).change_mask.common.s.do_ignore_restack)
#define SFSET_DO_IGNORE_RESTACK(st,x) \
	((st).flags.common.s.do_ignore_restack = !!(x))
#define SMSET_DO_IGNORE_RESTACK(st,x) \
	((st).flag_mask.common.s.do_ignore_restack = !!(x))
#define SCSET_DO_IGNORE_RESTACK(st,x) \
	((st).change_mask.common.s.do_ignore_restack = !!(x))
#define SDO_USE_WINDOW_GROUP_HINT(sf) \
	((sf).common.s.do_use_window_group_hint)
#define SFDO_USE_WINDOW_GROUP_HINT(st) \
	((st).flags.common.s.do_use_window_group_hint)
#define SMDO_USE_WINDOW_GROUP_HINT(st) \
	((st).flag_mask.common.s.do_use_window_group_hint)
#define SCDO_USE_WINDOW_GROUP_HINT(st) \
	((st).change_mask.common.s.do_use_window_group_hint)
#define SFSET_DO_USE_WINDOW_GROUP_HINT(st,x) \
	((st).flags.common.s.do_use_window_group_hint = !!(x))
#define SMSET_DO_USE_WINDOW_GROUP_HINT(st,x) \
	((st).flag_mask.common.s.do_use_window_group_hint = !!(x))
#define SCSET_DO_USE_WINDOW_GROUP_HINT(st,x) \
	((st).change_mask.common.s.do_use_window_group_hint = !!(x))
#define SDO_LOWER_TRANSIENT(sf) \
	((sf).common.s.do_lower_transient)
#define SFDO_LOWER_TRANSIENT(st) \
	((st).flags.common.s.do_lower_transient)
#define SMDO_LOWER_TRANSIENT(st) \
	((st).flag_mask.common.s.do_lower_transient)
#define SCDO_LOWER_TRANSIENT(st) \
	((st).change_mask.common.s.do_lower_transient)
#define SFSET_DO_LOWER_TRANSIENT(st,x) \
	((st).flags.common.s.do_lower_transient = !!(x))
#define SMSET_DO_LOWER_TRANSIENT(st,x) \
	((st).flag_mask.common.s.do_lower_transient = !!(x))
#define SCSET_DO_LOWER_TRANSIENT(st,x) \
	((st).change_mask.common.s.do_lower_transient = !!(x))
#define SDO_NOT_SHOW_ON_MAP(sf) \
	((sf).common.s.do_not_show_on_map)
#define SFDO_NOT_SHOW_ON_MAP(st) \
	((st).flags.common.s.do_not_show_on_map)
#define SMDO_NOT_SHOW_ON_MAP(st) \
	((st).flag_mask.common.s.do_not_show_on_map)
#define SCDO_NOT_SHOW_ON_MAP(st) \
	((st).change_mask.common.s.do_not_show_on_map)
#define SFSET_DO_NOT_SHOW_ON_MAP(st,x) \
	((st).flags.common.s.do_not_show_on_map = !!(x))
#define SMSET_DO_NOT_SHOW_ON_MAP(st,x) \
	((st).flag_mask.common.s.do_not_show_on_map = !!(x))
#define SCSET_DO_NOT_SHOW_ON_MAP(st,x) \
	((st).change_mask.common.s.do_not_show_on_map = !!(x))
#define SDO_NOT_PASS_CLICK_FOCUS_CLICK(sf) \
	((sf).common.s.do_not_pass_click_focus_click)
#define SFDO_NOT_PASS_CLICK_FOCUS_CLICK(st) \
	((st).flags.common.s.do_not_pass_click_focus_click)
#define SMDO_NOT_PASS_CLICK_FOCUS_CLICK(st) \
	((st).flag_mask.common.s.do_not_pass_click_focus_click)
#define SCDO_NOT_PASS_CLICK_FOCUS_CLICK(st) \
	((st).change_mask.common.s.do_not_pass_click_focus_click)
#define SFSET_DO_NOT_PASS_CLICK_FOCUS_CLICK(st,x) \
	((st).flags.common.s.do_not_pass_click_focus_click = !!(x))
#define SMSET_DO_NOT_PASS_CLICK_FOCUS_CLICK(st,x) \
	((st).flag_mask.common.s.do_not_pass_click_focus_click = !!(x))
#define SCSET_DO_NOT_PASS_CLICK_FOCUS_CLICK(st,x) \
	((st).change_mask.common.s.do_not_pass_click_focus_click = !!(x))
#define SDO_NOT_RAISE_CLICK_FOCUS_CLICK(sf) \
	((sf).common.s.do_not_raise_click_focus_click)
#define SFDO_NOT_RAISE_CLICK_FOCUS_CLICK(st) \
	((st).flags.common.s.do_not_raise_click_focus_click)
#define SMDO_NOT_RAISE_CLICK_FOCUS_CLICK(st) \
	((st).flag_mask.common.s.do_not_raise_click_focus_click)
#define SCDO_NOT_RAISE_CLICK_FOCUS_CLICK(st) \
	((st).change_mask.common.s.do_not_raise_click_focus_click)
#define SFSET_DO_NOT_RAISE_CLICK_FOCUS_CLICK(st,x) \
	((st).flags.common.s.do_not_raise_click_focus_click = !!(x))
#define SMSET_DO_NOT_RAISE_CLICK_FOCUS_CLICK(st,x) \
	((st).flag_mask.common.s.do_not_raise_click_focus_click = !!(x))
#define SCSET_DO_NOT_RAISE_CLICK_FOCUS_CLICK(st,x) \
	((st).change_mask.common.s.do_not_raise_click_focus_click = !!(x))
#define SDO_IGNORE_MOUSE_FOCUS_CLICK_MOTION(sf) \
	((sf).common.s.do_ignore_mouse_focus_click_motion)
#define SFDO_IGNORE_MOUSE_FOCUS_CLICK_MOTION(st) \
	((st).flags.common.s.do_ignore_mouse_focus_click_motion)
#define SMDO_IGNORE_MOUSE_FOCUS_CLICK_MOTION(st) \
	((st).flag_mask.common.s.do_ignore_mouse_focus_click_motion)
#define SCDO_IGNORE_MOUSE_FOCUS_CLICK_MOTION(st) \
	((st).change_mask.common.s.do_ignore_mouse_focus_click_motion)
#define SFSET_DO_IGNORE_MOUSE_FOCUS_CLICK_MOTION(st,x) \
	((st).flags.common.s.do_ignore_mouse_focus_click_motion = !!(x))
#define SMSET_DO_IGNORE_MOUSE_FOCUS_CLICK_MOTION(st,x) \
	((st).flag_mask.common.s.do_ignore_mouse_focus_click_motion = !!(x))
#define SCSET_DO_IGNORE_MOUSE_FOCUS_CLICK_MOTION(st,x) \
	((st).change_mask.common.s.do_ignore_mouse_focus_click_motion = !!(x))
#define SDO_RAISE_MOUSE_FOCUS_CLICK(sf) \
	((sf).common.s.do_raise_mouse_focus_click)
#define SFDO_RAISE_MOUSE_FOCUS_CLICK(st) \
	((st).flags.common.s.do_raise_mouse_focus_click)
#define SMDO_RAISE_MOUSE_FOCUS_CLICK(st) \
	((st).flag_mask.common.s.do_raise_mouse_focus_click)
#define SCDO_RAISE_MOUSE_FOCUS_CLICK(st) \
	((st).change_mask.common.s.do_raise_mouse_focus_click)
#define SFSET_DO_RAISE_MOUSE_FOCUS_CLICK(st,x) \
	((st).flags.common.s.do_raise_mouse_focus_click = !!(x))
#define SMSET_DO_RAISE_MOUSE_FOCUS_CLICK(st,x) \
	((st).flag_mask.common.s.do_raise_mouse_focus_click = !!(x))
#define SCSET_DO_RAISE_MOUSE_FOCUS_CLICK(st,x) \
	((st).change_mask.common.s.do_raise_mouse_focus_click = !!(x))
#define SDO_RAISE_TRANSIENT(sf) \
	((sf).common.s.do_raise_transient)
#define SFDO_RAISE_TRANSIENT(st) \
	((st).flags.common.s.do_raise_transient)
#define SMDO_RAISE_TRANSIENT(st) \
	((st).flag_mask.common.s.do_raise_transient)
#define SCDO_RAISE_TRANSIENT(st) \
	((st).change_mask.common.s.do_raise_transient)
#define SFSET_DO_RAISE_TRANSIENT(st,x) \
	((st).flags.common.s.do_raise_transient = !!(x))
#define SMSET_DO_RAISE_TRANSIENT(st,x) \
	((st).flag_mask.common.s.do_raise_transient = !!(x))
#define SCSET_DO_RAISE_TRANSIENT(st,x) \
	((st).change_mask.common.s.do_raise_transient = !!(x))
#define SDO_RESIZE_OPAQUE(sf) \
	((sf).common.s.do_resize_opaque)
#define SFDO_RESIZE_OPAQUE(st) \
	((st).flags.common.s.do_resize_opaque)
#define SMDO_RESIZE_OPAQUE(st) \
	((st).flag_mask.common.s.do_resize_opaque)
#define SCDO_RESIZE_OPAQUE(st) \
	((st).change_mask.common.s.do_resize_opaque)
#define SFSET_DO_RESIZE_OPAQUE(st,x) \
	((st).flags.common.s.do_resize_opaque = !!(x))
#define SMSET_DO_RESIZE_OPAQUE(st,x) \
	((st).flag_mask.common.s.do_resize_opaque = !!(x))
#define SCSET_DO_RESIZE_OPAQUE(st,x) \
	((st).change_mask.common.s.do_resize_opaque = !!(x))
#define SDO_SHRINK_WINDOWSHADE(sf ) \
	((sf).common.s.do_shrink_windowshade)
#define SFDO_SHRINK_WINDOWSHADE(st) \
	((st).flags.common.s.do_shrink_windowshade)
#define SMDO_SHRINK_WINDOWSHADE(st) \
	((st).flag_mask.common.s.do_shrink_windowshade)
#define SCDO_SHRINK_WINDOWSHADE(st) \
	((st).change_mask.common.s.do_shrink_windowshade)
#define SFSET_DO_SHRINK_WINDOWSHADE(st,x) \
	((st).flags.common.s.do_shrink_windowshade = !!(x))
#define SMSET_DO_SHRINK_WINDOWSHADE(st,x) \
	((st).flag_mask.common.s.do_shrink_windowshade = !!(x))
#define SCSET_DO_SHRINK_WINDOWSHADE(st,x) \
	((st).change_mask.common.s.do_shrink_windowshade = !!(x))
#define SDO_STACK_TRANSIENT_PARENT(sf) \
	((sf).common.s.do_stack_transient_parent)
#define SFDO_STACK_TRANSIENT_PARENT(st) \
	((st).flags.common.s.do_stack_transient_parent)
#define SMDO_STACK_TRANSIENT_PARENT(st) \
	((st).flag_mask.common.s.do_stack_transient_parent)
#define SCDO_STACK_TRANSIENT_PARENT(st) \
	((st).change_mask.common.s.do_stack_transient_parent)
#define SFSET_DO_STACK_TRANSIENT_PARENT(st,x) \
	((st).flags.common.s.do_stack_transient_parent = !!(x))
#define SMSET_DO_STACK_TRANSIENT_PARENT(st,x) \
	((st).flag_mask.common.s.do_stack_transient_parent = !!(x))
#define SCSET_DO_STACK_TRANSIENT_PARENT(st,x) \
	((st).change_mask.common.s.do_stack_transient_parent = !!(x))
#define SDO_WINDOW_LIST_SKIP(sf) \
	((sf).common.s.do_window_list_skip)
#define SFDO_WINDOW_LIST_SKIP(st) \
	((st).flags.common.s.do_window_list_skip)
#define SMDO_WINDOW_LIST_SKIP(st) \
	((st).flag_mask.common.s.do_window_list_skip)
#define SCDO_WINDOW_LIST_SKIP(st) \
	((st).change_mask.common.s.do_window_list_skip)
#define SFSET_DO_WINDOW_LIST_SKIP(st,x) \
	((st).flags.common.s.do_window_list_skip = !!(x))
#define SMSET_DO_WINDOW_LIST_SKIP(st,x) \
	((st).flag_mask.common.s.do_window_list_skip = !!(x))
#define SCSET_DO_WINDOW_LIST_SKIP(st,x) \
	((st).change_mask.common.s.do_window_list_skip = !!(x))
#define SFOCUS_MODE(sf) \
	((sf).common.s.focus_mode)
#define SFFOCUS_MODE(st) \
	((st).flags.common.s.focus_mode)
#define SMFOCUS_MODE(st) \
	((st).flag_mask.common.s.focus_mode)
#define SCFOCUS_MODE(st) \
	((st).change_mask.common.s.focus_mode)
#define SFSET_FOCUS_MODE(st,x) \
	((st).flags.common.s.focus_mode = (x))
#define SMSET_FOCUS_MODE(st,x) \
	((st).flag_mask.common.s.focus_mode = (x))
#define SCSET_FOCUS_MODE(st,x) \
	((st).change_mask.common.s.focus_mode = (x))
#define SHAS_NO_BORDER(sf) \
	((sf).common.s.has_no_border)
#define SFHAS_NO_BORDER(st) \
	((st).flags.common.s.has_no_border)
#define SMHAS_NO_BORDER(st) \
	((st).flag_mask.common.s.has_no_border)
#define SCHAS_NO_BORDER(st) \
	((st).change_mask.common.s.has_no_border)
#define SFSET_HAS_NO_BORDER(st,x) \
	((st).flags.common.s.has_no_border = !!(x))
#define SMSET_HAS_NO_BORDER(st,x) \
	((st).flag_mask.common.s.has_no_border = !!(x))
#define SCSET_HAS_NO_BORDER(st,x) \
	((st).change_mask.common.s.has_no_border = !!(x))
#define SHAS_DEPRESSABLE_BORDER(sf) \
	((sf).common.s.has_depressable_border)
#define SFHAS_DEPRESSABLE_BORDER(st) \
	((st).flags.common.s.has_depressable_border)
#define SMHAS_DEPRESSABLE_BORDER(st) \
	((st).flag_mask.common.s.has_depressable_border)
#define SCHAS_DEPRESSABLE_BORDER(st) \
	((st).change_mask.common.s.has_depressable_border)
#define SFSET_HAS_DEPRESSABLE_BORDER(st,x) \
	((st).flags.common.s.has_depressable_border = !!(x))
#define SMSET_HAS_DEPRESSABLE_BORDER(st,x) \
	((st).flag_mask.common.s.has_depressable_border = !!(x))
#define SCSET_HAS_DEPRESSABLE_BORDER(st,x) \
	((st).change_mask.common.s.has_depressable_border = !!(x))
#define SHAS_ICON_FONT(sf) \
	((sf).common.has_icon_font)
#define SFHAS_ICON_FONT(st) \
	((st).flags.common.has_icon_font)
#define SMHAS_ICON_FONT(st) \
	((st).flag_mask.common.has_icon_font)
#define SCHAS_ICON_FONT(st) \
	((st).change_mask.common.has_icon_font)
#define SFSET_HAS_ICON_FONT(st,x) \
	((st).flags.common.has_icon_font = !!(x))
#define SMSET_HAS_ICON_FONT(st,x) \
	((st).flag_mask.common.has_icon_font = !!(x))
#define SCSET_HAS_ICON_FONT(st,x) \
	((st).change_mask.common.has_icon_font = !!(x))
#define SHAS_MWM_BORDER(sf) \
	((sf).common.s.has_mwm_border)
#define SFHAS_MWM_BORDER(st) \
	((st).flags.common.s.has_mwm_border)
#define SMHAS_MWM_BORDER(st) \
	((st).flag_mask.common.s.has_mwm_border)
#define SCHAS_MWM_BORDER(st) \
	((st).change_mask.common.s.has_mwm_border)
#define SFSET_HAS_MWM_BORDER(st,x) \
	((st).flags.common.s.has_mwm_border = !!(x))
#define SMSET_HAS_MWM_BORDER(st,x) \
	((st).flag_mask.common.s.has_mwm_border = !!(x))
#define SCSET_HAS_MWM_BORDER(st,x) \
	((st).change_mask.common.s.has_mwm_border = !!(x))
#define SHAS_MWM_BUTTONS(sf) \
	((sf).common.s.has_mwm_buttons)
#define SFHAS_MWM_BUTTONS(st) \
	((st).flags.common.s.has_mwm_buttons)
#define SMHAS_MWM_BUTTONS(st) \
	((st).flag_mask.common.s.has_mwm_buttons)
#define SCHAS_MWM_BUTTONS(st) \
	((st).change_mask.common.s.has_mwm_buttons)
#define SFSET_HAS_MWM_BUTTONS(st,x) \
	((st).flags.common.s.has_mwm_buttons = !!(x))
#define SMSET_HAS_MWM_BUTTONS(st,x) \
	((st).flag_mask.common.s.has_mwm_buttons = !!(x))
#define SCSET_HAS_MWM_BUTTONS(st,x) \
	((st).change_mask.common.s.has_mwm_buttons = !!(x))
#define SHAS_MWM_OVERRIDE(sf) \
	((sf).common.s.has_mwm_override)
#define SFHAS_MWM_OVERRIDE(st) \
	((st).flags.common.s.has_mwm_override)
#define SMHAS_MWM_OVERRIDE(st) \
	((st).flag_mask.common.s.has_mwm_override)
#define SCHAS_MWM_OVERRIDE(st) \
	((st).change_mask.common.s.has_mwm_override)
#define SFSET_HAS_MWM_OVERRIDE(st,x) \
	((st).flags.common.s.has_mwm_override = !!(x))
#define SMSET_HAS_MWM_OVERRIDE(st,x) \
	((st).flag_mask.common.s.has_mwm_override = !!(x))
#define SCSET_HAS_MWM_OVERRIDE(st,x) \
	((st).change_mask.common.s.has_mwm_override = !!(x))
#define SHAS_NO_ICON_TITLE(sf) \
	((sf).common.s.has_no_icon_title)
#define SFHAS_NO_ICON_TITLE(st) \
	((st).flags.common.s.has_no_icon_title)
#define SMHAS_NO_ICON_TITLE(st) \
	((st).flag_mask.common.s.has_no_icon_title)
#define SCHAS_NO_ICON_TITLE(st) \
	((st).change_mask.common.s.has_no_icon_title)
#define SFSET_HAS_NO_ICON_TITLE(st,x) \
	((st).flags.common.s.has_no_icon_title = !!(x))
#define SMSET_HAS_NO_ICON_TITLE(st,x) \
	((st).flag_mask.common.s.has_no_icon_title = !!(x))
#define SCSET_HAS_NO_ICON_TITLE(st,x) \
	((st).change_mask.common.s.has_no_icon_title = !!(x))
#define SHAS_OVERRIDE_SIZE(sf) \
	((sf).common.s.has_override_size)
#define SFHAS_OVERRIDE_SIZE(st) \
	((st).flags.common.s.has_override_size)
#define SMHAS_OVERRIDE_SIZE(st) \
	((st).flag_mask.common.s.has_override_size)
#define SCHAS_OVERRIDE_SIZE(st) \
	((st).change_mask.common.s.has_override_size)
#define SFSET_HAS_OVERRIDE_SIZE(st,x) \
	((st).flags.common.s.has_override_size = !!(x))
#define SMSET_HAS_OVERRIDE_SIZE(st,x) \
	((st).flag_mask.common.s.has_override_size = !!(x))
#define SCSET_HAS_OVERRIDE_SIZE(st,x) \
	((st).change_mask.common.s.has_override_size = !!(x))
#define SHAS_STIPPLED_TITLE(sf) \
	((sf).common.s.has_stippled_title)
#define SFHAS_STIPPLED_TITLE(st) \
	((st).flags.common.s.has_stippled_title)
#define SMHAS_STIPPLED_TITLE(st) \
	((st).flag_mask.common.s.has_stippled_title)
#define SCHAS_STIPPLED_TITLE(st) \
	((st).change_mask.common.s.has_stippled_title)
#define SFSET_HAS_STIPPLED_TITLE(st,x) \
	((st).flags.common.s.has_stippled_title = !!(x))
#define SMSET_HAS_STIPPLED_TITLE(st,x) \
	((st).flag_mask.common.s.has_stippled_title = !!(x))
#define SCSET_HAS_STIPPLED_TITLE(st,x) \
	((st).change_mask.common.s.has_stippled_title = !!(x))
#define SHAS_WINDOW_FONT(sf) \
	((sf).common.has_window_font)
#define SFHAS_WINDOW_FONT(st) \
	((st).flags.common.has_window_font)
#define SMHAS_WINDOW_FONT(st) \
	((st).flag_mask.common.has_window_font)
#define SCHAS_WINDOW_FONT(st) \
	((st).change_mask.common.has_window_font)
#define SFSET_HAS_WINDOW_FONT(st,x) \
	((st).flags.common.has_window_font = !!(x))
#define SMSET_HAS_WINDOW_FONT(st,x) \
	((st).flag_mask.common.has_window_font = !!(x))
#define SCSET_HAS_WINDOW_FONT(st,x) \
	((st).change_mask.common.has_window_font = !!(x))
#define SICON_OVERRIDE(sf) \
	((sf).common.s.icon_override)
#define SFICON_OVERRIDE(st) \
	((st).flags.common.s.icon_override)
#define SMICON_OVERRIDE(st) \
	((st).flag_mask.common.s.icon_override)
#define SCICON_OVERRIDE(st) \
	((st).change_mask.common.s.icon_override)
#define SFSET_ICON_OVERRIDE(st,x) \
	((st).flags.common.s.icon_override = (x))
#define SMSET_ICON_OVERRIDE(st,x) \
	((st).flag_mask.common.s.icon_override = (x))
#define SCSET_ICON_OVERRIDE(st,x) \
	((st).change_mask.common.s.icon_override = (x))
#define SIS_BOTTOM_TITLE_ROTATED(sf) \
	((sf).common.s.is_bottom_title_rotated)
#define SFIS_BOTTOM_TITLE_ROTATED(st) \
	((st).flags.common.s.is_bottom_title_rotated)
#define SMIS_BOTTOM_TITLE_ROTATED(st) \
	((st).flag_mask.common.s.is_bottom_title_rotated)
#define SCIS_BOTTOM_TITLE_ROTATED(st) \
	((st).change_mask.common.s.is_bottom_title_rotated)
#define SFSET_IS_BOTTOM_TITLE_ROTATED(st,x) \
	((st).flags.common.s.is_bottom_title_rotated = !!(x))
#define SMSET_IS_BOTTOM_TITLE_ROTATED(st,x) \
	((st).flag_mask.common.s.is_bottom_title_rotated = !!(x))
#define SCSET_IS_BOTTOM_TITLE_ROTATED(st,x) \
	((st).change_mask.common.s.is_bottom_title_rotated = !!(x))
#define SIS_FIXED(sf) \
	((sf).common.s.is_fixed)
#define SFIS_FIXED(st) \
	((st).flags.common.s.is_fixed)
#define SMIS_FIXED(st) \
	((st).flag_mask.common.s.is_fixed)
#define SCIS_FIXED(st) \
	((st).change_mask.common.s.is_fixed)
#define SFSET_IS_FIXED(st,x) \
	((st).flags.common.s.is_fixed = !!(x))
#define SMSET_IS_FIXED(st,x) \
	((st).flag_mask.common.s.is_fixed = !!(x))
#define SCSET_IS_FIXED(st,x) \
	((st).change_mask.common.s.is_fixed = !!(x))
#define SIS_FIXED_PPOS(sf) \
	((sf).common.s.is_fixed_ppos)
#define SFIS_FIXED_PPOS(st) \
	((st).flags.common.s.is_fixed_ppos)
#define SMIS_FIXED_PPOS(st) \
	((st).flag_mask.common.s.is_fixed_ppos)
#define SCIS_FIXED_PPOS(st) \
	((st).change_mask.common.s.is_fixed_ppos)
#define SFSET_IS_FIXED_PPOS(st,x) \
	((st).flags.common.s.is_fixed_ppos = !!(x))
#define SMSET_IS_FIXED_PPOS(st,x) \
	((st).flag_mask.common.s.is_fixed_ppos = !!(x))
#define SCSET_IS_FIXED_PPOS(st,x) \
	((st).change_mask.common.s.is_fixed_ppos = !!(x))
#define SIS_ICON_STICKY(sf) \
	((sf).common.s.is_icon_sticky)
#define SFIS_ICON_STICKY(st) \
	((st).flags.common.s.is_icon_sticky)
#define SMIS_ICON_STICKY(st) \
	((st).flag_mask.common.s.is_icon_sticky)
#define SCIS_ICON_STICKY(st) \
	((st).change_mask.common.s.is_icon_sticky)
#define SFSET_IS_ICON_STICKY(st,x) \
	((st).flags.common.s.is_icon_sticky = !!(x))
#define SMSET_IS_ICON_STICKY(st,x) \
	((st).flag_mask.common.s.is_icon_sticky = !!(x))
#define SCSET_IS_ICON_STICKY(st,x) \
	((st).change_mask.common.s.is_icon_sticky = !!(x))
#define SIS_ICON_SUPPRESSED(sf) \
	((sf).common.s.is_icon_suppressed)
#define SFIS_ICON_SUPPRESSED(st) \
	((st).flags.common.s.is_icon_suppressed)
#define SMIS_ICON_SUPPRESSED(st) \
	((st).flag_mask.common.s.is_icon_suppressed)
#define SCIS_ICON_SUPPRESSED(st) \
	((st).change_mask.common.s.is_icon_suppressed)
#define SFSET_IS_ICON_SUPPRESSED(st,x) \
	((st).flags.common.s.is_icon_suppressed = !!(x))
#define SMSET_IS_ICON_SUPPRESSED(st,x) \
	((st).flag_mask.common.s.is_icon_suppressed = !!(x))
#define SCSET_IS_ICON_SUPPRESSED(st,x) \
	((st).change_mask.common.s.is_icon_suppressed = !!(x))
#define SIS_LEFT_TITLE_ROTATED_CW(sf) \
	((sf).common.s.is_left_title_rotated_cw)
#define SFIS_LEFT_TITLE_ROTATED_CW(st) \
	((st).flags.common.s.is_left_title_rotated_cw)
#define SMIS_LEFT_TITLE_ROTATED_CW(st) \
	((st).flag_mask.common.s.is_left_title_rotated_cw)
#define SCIS_LEFT_TITLE_ROTATED_CW(st) \
	((st).change_mask.common.s.is_left_title_rotated_cw)
#define SFSET_IS_LEFT_TITLE_ROTATED_CW(st,x) \
	((st).flags.common.s.is_left_title_rotated_cw = !!(x))
#define SMSET_IS_LEFT_TITLE_ROTATED_CW(st,x) \
	((st).flag_mask.common.s.is_left_title_rotated_cw = !!(x))
#define SCSET_IS_LEFT_TITLE_ROTATED_CW(st,x) \
	((st).change_mask.common.s.is_left_title_rotated_cw = !!(x))
#define SIS_SIZE_FIXED(sf) \
	((sf).common.s.is_size_fixed)
#define SFIS_SIZE_FIXED(st) \
	((st).flags.common.s.is_size_fixed)
#define SMIS_SIZE_FIXED(st) \
	((st).flag_mask.common.s.is_size_fixed)
#define SCIS_SIZE_FIXED(st) \
	((st).change_mask.common.s.is_size_fixed)
#define SFSET_IS_SIZE_FIXED(st,x) \
	((st).flags.common.s.is_size_fixed = !!(x))
#define SMSET_IS_SIZE_FIXED(st,x) \
	((st).flag_mask.common.s.is_size_fixed = !!(x))
#define SCSET_IS_SIZE_FIXED(st,x) \
	((st).change_mask.common.s.is_size_fixed = !!(x))
#define SIS_PSIZE_FIXED(sf) \
	((sf).common.s.is_psize_fixed)
#define SFIS_PSIZE_FIXED(st) \
	((st).flags.common.s.is_psize_fixed)
#define SMIS_PSIZE_FIXED(st) \
	((st).flag_mask.common.s.is_psize_fixed)
#define SCIS_PSIZE_FIXED(st) \
	((st).change_mask.common.s.is_psize_fixed)
#define SFSET_IS_PSIZE_FIXED(st,x) \
	((st).flags.common.s.is_psize_fixed = !!(x))
#define SMSET_IS_PSIZE_FIXED(st,x) \
	((st).flag_mask.common.s.is_psize_fixed = !!(x))
#define SCSET_IS_PSIZE_FIXED(st,x) \
	((st).change_mask.common.s.is_psize_fixed = !!(x))
#define SIS_RIGHT_TITLE_ROTATED_CW(sf) \
	((sf).common.s.is_right_title_rotated_cw)
#define SFIS_RIGHT_TITLE_ROTATED_CW(st) \
	((st).flags.common.s.is_right_title_rotated_cw)
#define SMIS_RIGHT_TITLE_ROTATED_CW(st) \
	((st).flag_mask.common.s.is_right_title_rotated_cw)
#define SCIS_RIGHT_TITLE_ROTATED_CW(st) \
	((st).change_mask.common.s.is_right_title_rotated_cw)
#define SFSET_IS_RIGHT_TITLE_ROTATED_CW(st,x) \
	((st).flags.common.s.is_right_title_rotated_cw = !!(x))
#define SMSET_IS_RIGHT_TITLE_ROTATED_CW(st,x) \
	((st).flag_mask.common.s.is_right_title_rotated_cw = !!(x))
#define SCSET_IS_RIGHT_TITLE_ROTATED_CW(st,x) \
	((st).change_mask.common.s.is_right_title_rotated_cw = !!(x))
#define SIS_TOP_TITLE_ROTATED(sf) \
	((sf).common.s.is_top_title_rotated)
#define SFIS_TOP_TITLE_ROTATED(st) \
	((st).flags.common.s.is_top_title_rotated)
#define SMIS_TOP_TITLE_ROTATED(st) \
	((st).flag_mask.common.s.is_top_title_rotated)
#define SCIS_TOP_TITLE_ROTATED(st) \
	((st).change_mask.common.s.is_top_title_rotated)
#define SFSET_IS_TOP_TITLE_ROTATED(st,x) \
	((st).flags.common.s.is_top_title_rotated = !!(x))
#define SMSET_IS_TOP_TITLE_ROTATED(st,x) \
	((st).flag_mask.common.s.is_top_title_rotated = !!(x))
#define SCSET_IS_TOP_TITLE_ROTATED(st,x) \
	((st).change_mask.common.s.is_top_title_rotated = !!(x))
#define SUSE_ICON_POSITION_HINT(sf) \
	((sf).common.s.use_icon_position_hint)
#define SFUSE_ICON_POSITION_HINT(st) \
	((st).flags.common.s.use_icon_position_hint)
#define SMUSE_ICON_POSITION_HINT(st) \
	((st).flag_mask.common.s.use_icon_position_hint)
#define SCUSE_ICON_POSITION_HINT(st) \
	((st).change_mask.common.s.use_icon_position_hint)
#define SFSET_USE_ICON_POSITION_HINT(st,x) \
	((st).flags.common.s.use_icon_position_hint = !!(x))
#define SMSET_USE_ICON_POSITION_HINT(st,x) \
	((st).flag_mask.common.s.use_icon_position_hint = !!(x))
#define SCSET_USE_ICON_POSITION_HINT(st,x) \
	((st).change_mask.common.s.use_icon_position_hint = !!(x))
#define SUSE_INDEXED_WINDOW_NAME(sf) \
	((sf).common.s.use_indexed_window_name)
#define SFUSE_INDEXED_WINDOW_NAME(st) \
	((st).flags.common.s.use_indexed_window_name)
#define SMUSE_INDEXED_WINDOW_NAME(st) \
	((st).flag_mask.common.s.use_indexed_window_name)
#define SCUSE_INDEXED_WINDOW_NAME(st) \
	((st).change_mask.common.s.use_indexed_window_name)
#define SFSET_USE_INDEXED_WINDOW_NAME(st,x) \
	((st).flags.common.s.use_indexed_window_name = !!(x))
#define SMSET_USE_INDEXED_WINDOW_NAME(st,x) \
	((st).flag_mask.common.s.use_indexed_window_name = !!(x))
#define SCSET_USE_INDEXED_WINDOW_NAME(st,x) \
	((st).change_mask.common.s.use_indexed_window_name = !!(x))
#define SUSE_INDEXED_ICON_NAME(sf) \
	((sf).common.s.use_indexed_icon_name)
#define SFUSE_INDEXED_ICON_NAME(st) \
	((st).flags.common.s.use_indexed_icon_name)
#define SMUSE_INDEXED_ICON_NAME(st) \
	((st).flag_mask.common.s.use_indexed_icon_name)
#define SCUSE_INDEXED_ICON_NAME(st) \
	((st).change_mask.common.s.use_indexed_icon_name)
#define SFSET_USE_INDEXED_ICON_NAME(st,x) \
	((st).flags.common.s.use_indexed_icon_name = !!(x))
#define SMSET_USE_INDEXED_ICON_NAME(st,x) \
	((st).flag_mask.common.s.use_indexed_icon_name = !!(x))
#define SCSET_USE_INDEXED_ICON_NAME(st,x) \
	((st).change_mask.common.s.use_indexed_icon_name = !!(x))
#define SWINDOWSHADE_LAZINESS(sf) \
	((sf).common.s.windowshade_laziness)
#define SFWINDOWSHADE_LAZINESS(st) \
	((st).flags.common.s.windowshade_laziness)
#define SMWINDOWSHADE_LAZINESS(st) \
	((st).flag_mask.common.s.windowshade_laziness)
#define SCWINDOWSHADE_LAZINESS(st) \
	((st).change_mask.common.s.windowshade_laziness)
#define SFSET_WINDOWSHADE_LAZINESS(st,x) \
	((st).flags.common.s.windowshade_laziness = (x))
#define SMSET_WINDOWSHADE_LAZINESS(st,x) \
	((st).flag_mask.common.s.windowshade_laziness = (x))
#define SCSET_WINDOWSHADE_LAZINESS(st,x) \
	((st).change_mask.common.s.windowshade_laziness = (x))
#define SDO_EWMH_MINI_ICON_OVERRIDE(sf) \
	((sf).common.s.do_ewmh_mini_icon_override)
#define SFDO_EWMH_MINI_ICON_OVERRIDE(st) \
	((st).flags.common.s.do_ewmh_mini_icon_override)
#define SMDO_EWMH_MINI_ICON_OVERRIDE(st) \
	((st).flag_mask.common.s.do_ewmh_mini_icon_override)
#define SCDO_EWMH_MINI_ICON_OVERRIDE(st) \
	((st).change_mask.common.s.do_ewmh_mini_icon_override)
#define SFSET_DO_EWMH_MINI_ICON_OVERRIDE(st,x) \
	((st).flags.common.s.do_ewmh_mini_icon_override = !!(x))
#define SMSET_DO_EWMH_MINI_ICON_OVERRIDE(st,x) \
	((st).flag_mask.common.s.do_ewmh_mini_icon_override = !!(x))
#define SCSET_DO_EWMH_MINI_ICON_OVERRIDE(st,x) \
	((st).change_mask.common.s.do_ewmh_mini_icon_override = !!(x))
#define SDO_EWMH_DONATE_ICON(sf) \
	((sf).common.s.do_ewmh_donate_icon)
#define SFDO_EWMH_DONATE_ICON(st) \
	((st).flags.common.s.do_ewmh_donate_icon)
#define SMDO_EWMH_DONATE_ICON(st) \
	((st).flag_mask.common.s.do_ewmh_donate_icon)
#define SCDO_EWMH_DONATE_ICON(st) \
	((st).change_mask.common.s.do_ewmh_donate_icon)
#define SFSET_DO_EWMH_DONATE_ICON(st,x) \
	((st).flags.common.s.do_ewmh_donate_icon = !!(x))
#define SMSET_DO_EWMH_DONATE_ICON(st,x) \
	((st).flag_mask.common.s.do_ewmh_donate_icon = !!(x))
#define SCSET_DO_EWMH_DONATE_ICON(st,x) \
	((st).change_mask.common.s.do_ewmh_donate_icon = !!(x))
#define SDO_EWMH_DONATE_MINI_ICON(sf) \
	((sf).common.s.do_ewmh_donate_mini_icon)
#define SFDO_EWMH_DONATE_MINI_ICON(st) \
	((st).flags.common.s.do_ewmh_donate_mini_icon)
#define SMDO_EWMH_DONATE_MINI_ICON(st) \
	((st).flag_mask.common.s.do_ewmh_donate_mini_icon)
#define SCDO_EWMH_DONATE_MINI_ICON(st) \
	((st).change_mask.common.s.do_ewmh_donate_mini_icon)
#define SFSET_DO_EWMH_DONATE_MINI_ICON(st,x) \
	((st).flags.common.s.do_ewmh_donate_mini_icon = !!(x))
#define SMSET_DO_EWMH_DONATE_MINI_ICON(st,x) \
	((st).flag_mask.common.s.do_ewmh_donate_mini_icon = !!(x))
#define SCSET_DO_EWMH_DONATE_MINI_ICON(st,x) \
	((st).change_mask.common.s.do_ewmh_donate_mini_icon = !!(x))
#define SDO_EWMH_USE_STACKING_HINTS(sf) \
	((sf).common.s.do_ewmh_use_stacking_hints)
#define SFDO_EWMH_USE_STACKING_HINTS(st) \
	((st).flags.common.s.do_ewmh_use_stacking_hints)
#define SMDO_EWMH_USE_STACKING_HINTS(st) \
	((st).flag_mask.common.s.do_ewmh_use_stacking_hints)
#define SCDO_EWMH_USE_STACKING_HINTS(st) \
	((st).change_mask.common.s.do_ewmh_use_stacking_hints)
#define SFSET_DO_EWMH_USE_STACKING_HINTS(st,x) \
	((st).flags.common.s.do_ewmh_use_stacking_hints = !!(x))
#define SMSET_DO_EWMH_USE_STACKING_HINTS(st,x) \
	((st).flag_mask.common.s.do_ewmh_use_stacking_hints = !!(x))
#define SCSET_DO_EWMH_USE_STACKING_HINTS(st,x) \
	((st).change_mask.common.s.do_ewmh_use_stacking_hints = !!(x))
#define SDO_EWMH_IGNORE_STRUT_HINTS(sf) \
	((sf).common.s.do_ewmh_ignore_strut_hints)
#define SFDO_EWMH_IGNORE_STRUT_HINTS(st) \
	((st).flags.common.s.do_ewmh_ignore_strut_hints)
#define SMDO_EWMH_IGNORE_STRUT_HINTS(st) \
	((st).flag_mask.common.s.do_ewmh_ignore_strut_hints)
#define SCDO_EWMH_IGNORE_STRUT_HINTS(st) \
	((st).change_mask.common.s.do_ewmh_ignore_strut_hints)
#define SFSET_DO_EWMH_IGNORE_STRUT_HINTS(st,x) \
	((st).flags.common.s.do_ewmh_ignore_strut_hints = !!(x))
#define SMSET_DO_EWMH_IGNORE_STRUT_HINTS(st,x) \
	((st).flag_mask.common.s.do_ewmh_ignore_strut_hints = !!(x))
#define SCSET_DO_EWMH_IGNORE_STRUT_HINTS(st,x) \
	((st).change_mask.common.s.do_ewmh_ignore_strut_hints = !!(x))
#define SDO_EWMH_IGNORE_STATE_HINTS(sf) \
	((sf).common.s.do_ewmh_ignore_state_hints)
#define SFDO_EWMH_IGNORE_STATE_HINTS(st) \
	((st).flags.common.s.do_ewmh_ignore_state_hints)
#define SMDO_EWMH_IGNORE_STATE_HINTS(st) \
	((st).flag_mask.common.s.do_ewmh_ignore_state_hints)
#define SCDO_EWMH_IGNORE_STATE_HINTS(st) \
	((st).change_mask.common.s.do_ewmh_ignore_state_hints)
#define SFSET_DO_EWMH_IGNORE_STATE_HINTS(st,x) \
	((st).flags.common.s.do_ewmh_ignore_state_hints = !!(x))
#define SMSET_DO_EWMH_IGNORE_STATE_HINTS(st,x) \
	((st).flag_mask.common.s.do_ewmh_ignore_state_hints = !!(x))
#define SCSET_DO_EWMH_IGNORE_STATE_HINTS(st,x) \
	((st).change_mask.common.s.do_ewmh_ignore_state_hints = !!(x))
#define SEWMH_MAXIMIZE_MODE(sf) \
	((sf).common.s.ewmh_maximize_mode)
#define SFEWMH_MAXIMIZE_MODE(st) \
	((st).flags.common.s.ewmh_maximize_mode)
#define SMEWMH_MAXIMIZE_MODE(st) \
	((st).flag_mask.common.s.ewmh_maximize_mode)
#define SCEWMH_MAXIMIZE_MODE(st) \
	((st).change_mask.common.s.ewmh_maximize_mode)
#define SFSET_EWMH_MAXIMIZE_MODE(st,x) \
	((st).flags.common.s.ewmh_maximize_mode = (x))
#define SMSET_EWMH_MAXIMIZE_MODE(st,x) \
	((st).flag_mask.common.s.ewmh_maximize_mode = (x))
#define SCSET_EWMH_MAXIMIZE_MODE(st,x) \
	((st).change_mask.common.s.ewmh_maximize_mode = (x))

/* access to other parts of a style (call with the style itself) */
#define SGET_NEXT_STYLE(s) \
	((s).next)
#define SSET_NEXT_STYLE(s,x) \
	((s).next = (x))
#define SGET_PREV_STYLE(s) \
	((s).prev)
#define SSET_PREV_STYLE(s,x) \
	((s).prev = (x))
#define SGET_NAME(s) \
	((s).name)
#define SSET_NAME(s,x) \
	((s).name = (x))
#define SGET_ICON_NAME(s) \
	((s).icon_name)
#define SSET_ICON_NAME(s,x) \
	((s).icon_name = (x))
#define SGET_MINI_ICON_NAME(s) \
	((s).mini_icon_name)
#define SSET_MINI_ICON_NAME(s,x) \
	((s).mini_icon_name = (x))
#ifdef USEDECOR
#define SGET_DECOR_NAME(s) \
	((s).decor_name)
#define SSET_DECOR_NAME(s,x) \
	((s).decor_name = (x))
#endif
#define SGET_FORE_COLOR_NAME(s) \
	((s).fore_color_name)
#define SSET_FORE_COLOR_NAME(s,x) \
	((s).fore_color_name = (x))
#define SGET_BACK_COLOR_NAME(s) \
	((s).back_color_name)
#define SSET_BACK_COLOR_NAME(s,x) \
	((s).back_color_name = (x))
#define SGET_FORE_COLOR_NAME_HI(s) \
	((s).fore_color_name_hi)
#define SSET_FORE_COLOR_NAME_HI(s,x) \
	((s).fore_color_name_hi = (x))
#define SGET_BACK_COLOR_NAME_HI(s) \
	((s).back_color_name_hi)
#define SSET_BACK_COLOR_NAME_HI(s,x) \
	((s).back_color_name_hi = (x))
#define SGET_ICON_FONT(s) \
	((s).icon_font)
#define SSET_ICON_FONT(s,x) \
	((s).icon_font = (x))
#define SGET_WINDOW_FONT(s) \
	((s).window_font)
#define SSET_WINDOW_FONT(s,x) \
	((s).window_font = (x))
#define SGET_COLORSET(s) \
	((s).colorset)
#define SSET_COLORSET(s,x) \
	((s).colorset = (x))
#define SSET_BORDER_COLORSET(s,x) \
	((s).border_colorset = (x))
#define SGET_BORDER_COLORSET(s) \
	((s).border_colorset)
#define SGET_COLORSET_HI(s) \
	((s).colorset_hi)
#define SSET_COLORSET_HI(s,x) \
	((s).colorset_hi = (x))
#define SGET_BORDER_COLORSET_HI(s) \
	((s).border_colorset_hi)
#define SSET_BORDER_COLORSET_HI(s,x) \
	((s).border_colorset_hi = (x))
#define SGET_FLAGS_POINTER(s) \
	(&((s).flags))
#define SGET_BORDER_WIDTH(s) \
	((s).border_width)
#define SSET_BORDER_WIDTH(s,x) \
	((s).border_width = (x))
#define SGET_HANDLE_WIDTH(s) \
	((s).handle_width)
#define SSET_HANDLE_WIDTH(s,x) \
	((s).handle_width = (x))
#define SGET_LAYER(s) \
	((s).layer)
#define SSET_LAYER(s,x) \
	((s).layer = (x))
#define SGET_START_DESK(s) \
	((s).start_desk)
#define SSET_START_DESK(s,x) \
	((s).start_desk = (x))
#define SGET_START_PAGE_X(s) \
	((s).start_page_x)
#define SSET_START_PAGE_X(s,x) \
	((s).start_page_x = (x))
#define SGET_START_PAGE_Y(s) \
	((s).start_page_y)
#define SSET_START_PAGE_Y(s,x) \
	((s).start_page_y = (x))
#define SGET_START_SCREEN(s) \
	((s).start_screen)
#define SSET_START_SCREEN(s,x) \
	((s).start_screen = (x))
#define SGET_MIN_ICON_WIDTH(s) \
	((s).min_icon_width)
#define SSET_MIN_ICON_WIDTH(s,x) \
	((s).min_icon_width = (x))
#define SGET_MIN_ICON_HEIGHT(s) \
	((s).min_icon_height)
#define SSET_MIN_ICON_HEIGHT(s,x) \
	((s).min_icon_height = (x))
#define SGET_MAX_ICON_WIDTH(s) \
	((s).max_icon_width)
#define SSET_MAX_ICON_WIDTH(s,x) \
	((s).max_icon_width = (x))
#define SGET_MAX_ICON_HEIGHT(s) \
	((s).max_icon_height)
#define SSET_MAX_ICON_HEIGHT(s,x) \
	((s).max_icon_height = (x))
#define SGET_MAX_WINDOW_WIDTH(s) \
	((s).max_window_width)
#define SSET_MAX_WINDOW_WIDTH(s,x) \
	((s).max_window_width = (x))
#define SGET_MAX_WINDOW_HEIGHT(s) \
	((s).max_window_height)
#define SSET_MAX_WINDOW_HEIGHT(s,x) \
	((s).max_window_height = (x))
#define SGET_WINDOW_SHADE_STEPS(s) \
	((s).shade_anim_steps)
#define SSET_WINDOW_SHADE_STEPS(s,x) \
	((s).shade_anim_steps = (x))
#define SGET_ICON_BOXES(s) \
	((s).icon_boxes)
#define SSET_ICON_BOXES(s,x) \
	((s).icon_boxes = (x))
#define SGET_NORMAL_PLACEMENT_PENALTY(s) \
	((s).placement_penalty[0])
#define SGET_ONTOP_PLACEMENT_PENALTY(s) \
	((s).placement_penalty[1])
#define SGET_ICON_PLACEMENT_PENALTY(s) \
	((s).placement_penalty[2])
#define SGET_STICKY_PLACEMENT_PENALTY(s) \
	((s).placement_penalty[3])
#define SGET_BELOW_PLACEMENT_PENALTY(s) \
	((s).placement_penalty[4])
#define SGET_EWMH_STRUT_PLACEMENT_PENALTY(s) \
	((s).placement_penalty[5])
#define SSET_NORMAL_PLACEMENT_PENALTY(s,x) \
	((s).placement_penalty[0] = (x))
#define SSET_ONTOP_PLACEMENT_PENALTY(s,x) \
	((s).placement_penalty[1] = (x))
#define SSET_ICON_PLACEMENT_PENALTY(s,x) \
	((s).placement_penalty[2] = (x))
#define SSET_STICKY_PLACEMENT_PENALTY(s,x) \
	((s).placement_penalty[3] = (x))
#define SSET_BELOW_PLACEMENT_PENALTY(s,x) \
	((s).placement_penalty[4] = (x))
#define SSET_EWMH_STRUT_PLACEMENT_PENALTY(s,x) \
	((s).placement_penalty[5] = (x))
#define SGET_99_PLACEMENT_PERCENTAGE_PENALTY(s) \
	((s).placement_percentage_penalty[0])
#define SGET_95_PLACEMENT_PERCENTAGE_PENALTY(s) \
	((s).placement_percentage_penalty[1])
#define SGET_85_PLACEMENT_PERCENTAGE_PENALTY(s) \
	((s).placement_percentage_penalty[2])
#define SGET_75_PLACEMENT_PERCENTAGE_PENALTY(s) \
	((s).placement_percentage_penalty[3])
#define SSET_99_PLACEMENT_PERCENTAGE_PENALTY(s,x) \
	((s).placement_percentage_penalty[0] = (x))
#define SSET_95_PLACEMENT_PERCENTAGE_PENALTY(s,x) \
	((s).placement_percentage_penalty[1] = (x))
#define SSET_85_PLACEMENT_PERCENTAGE_PENALTY(s,x) \
	((s).placement_percentage_penalty[2] = (x))
#define SSET_75_PLACEMENT_PERCENTAGE_PENALTY(s,x) \
	((s).placement_percentage_penalty[3] = (x))

/* function prototypes */
void lookup_style(FvwmWindow *fw, window_style *styles);
Bool blockcmpmask(char *blk1, char *blk2, char *mask, int length);
void check_window_style_change(
  FvwmWindow *t, update_win *flags, window_style *ret_style);
void reset_style_changes(void);
void update_style_colorset(int colorset);
void update_window_color_style(FvwmWindow *fw, window_style *style);
void update_window_color_hi_style(FvwmWindow *fw, window_style *style);
void free_icon_boxes(icon_boxes *ib);

#endif /* _STYLE_ */
