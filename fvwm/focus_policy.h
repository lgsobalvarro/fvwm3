/* -*-c-*- */
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

#ifndef FOCUS_POLICY_H
#define FOCUS_POLICY_H

/* ---------------------------- included header files ----------------------- */

/* ---------------------------- global definitions -------------------------- */

/* ---------------------------- access macros ------------------------------- */

#define FP_DO_FOCUS_ENTER(fp) \
	((fp).do_focus_enter)
#define FPS_FOCUS_ENTER(fp,x) \
	((fp).do_focus_enter = !!(x))
#define FP_DO_UNFOCUS_LEAVE(fp) \
	((fp).do_unfocus_leave)
#define FPS_UNFOCUS_LEAVE(fp,x) \
	((fp).do_unfocus_leave = !!(x))
#define FP_DO_FOCUS_CLICK_CLIENT(fp) \
	((fp).do_focus_click_client)
#define FPS_FOCUS_CLICK_CLIENT(fp,x) \
	((fp).do_focus_click_client = !!(x))
#define FP_DO_FOCUS_CLICK_DECOR(fp) \
	((fp).do_focus_click_decor)
#define FPS_FOCUS_CLICK_DECOR(fp,x) \
	((fp).do_focus_click_decor = !!(x))
#define FP_DO_FOCUS_BY_PROGRAM(fp) \
	((fp).do_focus_by_program)
#define FPS_FOCUS_BY_PROGRAM(fp,x) \
	((fp).do_focus_by_program = !!(x))
#define FP_DO_FOCUS_BY_FUNCTION(fp) \
	((fp).do_focus_by_function)
#define FPS_FOCUS_BY_FUNCTION(fp,x) \
	((fp).do_focus_by_function = !!(x))
#define FP_IS_LENIENT(fp) \
	((fp).is_lenient)
#define FPS_LENIENT(fp,x) \
	((fp).is_lenient = !!(x))
#define FP_DO_RAISE_FOCUSED_CLIENT_CLICK(fp) \
	((fp).do_raise_focused_client_click)
#define FPS_RAISE_FOCUSED_CLIENT_CLICK(fp,x) \
	((fp).do_raise_focused_client_click = !!(x))
#define FP_DO_RAISE_UNFOCUSED_CLIENT_CLICK(fp) \
	((fp).do_raise_unfocused_client_click)
#define FPS_RAISE_UNFOCUSED_CLIENT_CLICK(fp,x) \
	((fp).do_raise_unfocused_client_click = !!(x))
#define FP_DO_RAISE_FOCUSED_DECOR_CLICK(fp) \
	((fp).do_raise_focused_decor_click)
#define FPS_RAISE_FOCUSED_DECOR_CLICK(fp,x) \
	((fp).do_raise_focused_decor_click = !!(x))
#define FP_DO_RAISE_UNFOCUSED_DECOR_CLICK(fp) \
	((fp).do_raise_unfocused_decor_click)
#define FPS_RAISE_UNFOCUSED_DECOR_CLICK(fp,x) \
	((fp).do_raise_unfocused_decor_click = !!(x))
#define FP_USE_MOUSE_BUTTONS(fp) \
	((fp).use_mouse_buttons)
#define FPS_MOUSE_BUTTONS(fp,x) \
	((fp).use_mouse_buttons = (x))
#define FP_USE_MODIFIERS(fp) \
	((fp).use_modifiers)
#define FPS_MODIFIERS(fp,x) \
	((fp).use_modifiers = (x))
#define FP_DO_PASS_FOCUS_CLICK(fp) \
	((fp).do_pass_focus_click)
#define FPS_PASS_FOCUS_CLICK(fp,x) \
	((fp).do_pass_focus_click = !!(x))
#define FP_DO_PASS_RAISE_CLICK(fp) \
	((fp).do_pass_raise_click)
#define FPS_PASS_RAISE_CLICK(fp,x) \
	((fp).do_pass_raise_click = !!(x))
#define FP_DO_IGNORE_FOCUS_CLICK_MOTION(fp) \
	((fp).do_ignore_focus_click_motion)
#define FPS_IGNORE_FOCUS_CLICK_MOTION(fp,x) \
	((fp).do_ignore_focus_click_motion = !!(x))
#define FP_DO_IGNORE_RAISE_CLICK_MOTION(fp) \
	((fp).do_ignore_raise_click_motion)
#define FPS_IGNORE_RAISE_CLICK_MOTION(fp,x) \
	((fp).do_ignore_raise_click_motion = !!(x))
#define FP_DO_ALLOW_FUNC_FOCUS_CLICK(fp) \
	((fp).do_allow_func_focus_click)
#define FPS_ALLOW_FUNC_FOCUS_CLICK(fp,x) \
	((fp).do_allow_func_focus_click = !!(x))
#define FP_DO_ALLOW_FUNC_RAISE_CLICK(fp) \
	((fp).do_allow_func_raise_click)
#define FPS_ALLOW_FUNC_RAISE_CLICK(fp,x) \
	((fp).do_allow_func_raise_click = !!(x))
#define FP_DO_GRAB_FOCUS_WHEN_CREATED(fp) \
	((fp).do_grab_focus_when_created)
#define FPS_GRAB_FOCUS_WHEN_CREATED(fp,x) \
	((fp).do_grab_focus_when_created = !!(x))
#define FP_DO_GRAB_FOCUS_WHEN_TRANSIENT_CREATED(fp) \
	((fp).do_grab_focus_when_transient_created)
#define FPS_GRAB_FOCUS_WHEN_TRANSIENT_CREATED(fp,x) \
	((fp).do_grab_focus_when_transient_created = !!(x))

/* ---------------------------- type definitions ---------------------------- */

typedef struct
{
	/* focus transition */
	unsigned do_focus_enter : 1;
	unsigned do_unfocus_leave : 1;
	unsigned do_focus_click_client : 1;
	unsigned do_focus_click_decor : 1;
	unsigned do_focus_by_program : 1;
	unsigned do_focus_by_function : 1;
	/* application focus model */
	unsigned is_lenient : 1;
	/* raising the window */
	unsigned do_raise_focused_client_click : 1;
	unsigned do_raise_unfocused_client_click : 1;
	unsigned do_raise_focused_decor_click : 1;
	unsigned do_raise_unfocused_decor_click : 1;
	/* click configuration */
	unsigned use_mouse_buttons : NUMBER_OF_MOUSE_BUTTONS;
	unsigned use_modifiers : 8;
	/* recycling of focus and raise clicks */
	unsigned do_pass_focus_click : 1;
	unsigned do_pass_raise_click : 1;
	unsigned do_ignore_focus_click_motion : 1;
	unsigned do_ignore_raise_click_motion : 1;
	unsigned do_allow_func_focus_click : 1;
	unsigned do_allow_func_raise_click : 1;
	/* initial focus */
	unsigned do_grab_focus_when_created : 1;
	unsigned do_grab_focus_when_transient_created : 1;
} focus_policy_t;

/* ---------------------------- forward declarations ------------------------ */

/* ---------------------------- exported variables (globals) ---------------- */

/* ---------------------------- interface functions ------------------------- */

void fpol_init_default_fp(focus_policy_t *fp);

#endif /* FOCUS_POLICY_H */
