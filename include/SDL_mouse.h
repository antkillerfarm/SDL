/*
    SDL - Simple DirectMedia Layer
    Copyright (C) 1997-2006 Sam Lantinga

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    Sam Lantinga
    slouken@libsdl.org
*/

/**
 * \file SDL_mouse.h
 *
 * Include file for SDL mouse event handling
 */

#ifndef _SDL_mouse_h
#define _SDL_mouse_h

#include "SDL_stdinc.h"
#include "SDL_error.h"
#include "SDL_video.h"

#include "begin_code.h"
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
/* *INDENT-OFF* */
extern "C" {
/* *INDENT-ON* */
#endif

typedef struct SDL_Cursor SDL_Cursor;   /* Implementation dependent */

/* Function prototypes */

/* \fn int SDL_GetNumMice(void)
 *
 * \brief Get the number of mouse input devices available.
 *
 * \sa SDL_SelectMouse()
 */
extern DECLSPEC int SDLCALL SDL_GetNumMice(void);

/* \fn int SDL_SelectMouse(int index)
 *
 * \brief Set the index of the currently selected mouse.
 *
 * \return The index of the currently selected mouse.
 *
 * \note You can query the currently selected mouse by passing an index of -1.
 *
 * \sa SDL_GetNumMice()
 */
extern DECLSPEC int SDLCALL SDL_SelectMouse(int index);

/* \fn SDL_WindowID SDL_GetMouseFocusWindow(void)
 *
 * \brief Get the window which currently has focus for the currently selected mouse.
 */
extern DECLSPEC SDL_WindowID SDLCALL SDL_GetMouseFocusWindow(void);

/*
 * \fn Uint8 SDL_GetMouseState(int *x, int *y)
 *
 * \brief Retrieve the current state of the mouse.
 *
 * The current button state is returned as a button bitmask, which can
 * be tested using the SDL_BUTTON(X) macros, and x and y are set to the
 * mouse cursor position relative to the focus window for the currently
 * selected mouse.  You can pass NULL for either x or y.
 */
extern DECLSPEC Uint8 SDLCALL SDL_GetMouseState(int *x, int *y);

/*
 * \fn Uint8 SDL_GetRelativeMouseState(int *x, int *y)
 *
 * \brief Retrieve the current state of the mouse.
 *
 * The current button state is returned as a button bitmask, which can
 * be tested using the SDL_BUTTON(X) macros, and x and y are set to the
 * mouse deltas since the last call to SDL_GetRelativeMouseState().
 */
extern DECLSPEC Uint8 SDLCALL SDL_GetRelativeMouseState(int *x, int *y);

/*
 * \fn void SDL_WarpMouseInWindow(SDL_WindowID windowID, int x, int y)
 *
 * \brief Moves the currently selected mouse to the given position within the window.
 *
 * \param windowID The window to move the mouse into, or 0 for the current mouse focus
 * \param x The x coordinate within the window
 * \param y The y coordinate within the window
 *
 * \note This function generates a mouse motion event
 */
extern DECLSPEC void SDLCALL SDL_WarpMouseInWindow(SDL_WindowID windowID,
                                                   int x, int y);

/*
 * Create a cursor using the specified data and mask (in MSB format).
 * The cursor width must be a multiple of 8 bits.
 *
 * The cursor is created in black and white according to the following:
 * data  mask    resulting pixel on screen
 *  0     1       White
 *  1     1       Black
 *  0     0       Transparent
 *  1     0       Inverted color if possible, black if not.
 *
 * Cursors created with this function must be freed with SDL_FreeCursor().
 */
extern DECLSPEC SDL_Cursor *SDLCALL SDL_CreateCursor
    (Uint8 * data, Uint8 * mask, int w, int h, int hot_x, int hot_y);

/*
 * Set the currently active cursor to the specified one.
 * If the cursor is currently visible, the change will be immediately 
 * represented on the display.
 */
extern DECLSPEC void SDLCALL SDL_SetCursor(SDL_Cursor * cursor);

/*
 * Returns the currently active cursor.
 */
extern DECLSPEC SDL_Cursor *SDLCALL SDL_GetCursor(void);

/*
 * Deallocates a cursor created with SDL_CreateCursor().
 */
extern DECLSPEC void SDLCALL SDL_FreeCursor(SDL_Cursor * cursor);

/*
 * Toggle whether or not the cursor is shown on the screen.
 * The cursor start off displayed, but can be turned off.
 * SDL_ShowCursor() returns 1 if the cursor was being displayed
 * before the call, or 0 if it was not.  You can query the current
 * state by passing a 'toggle' value of -1.
 */
extern DECLSPEC int SDLCALL SDL_ShowCursor(int toggle);

/* Used as a mask when testing buttons in buttonstate
   Button 1:	Left mouse button
   Button 2:	Middle mouse button
   Button 3:	Right mouse button
   Button 4:	Mouse wheel up	 (may also be a real button)
   Button 5:	Mouse wheel down (may also be a real button)
 */
#define SDL_BUTTON(X)		(1 << ((X)-1))
#define SDL_BUTTON_LEFT		1
#define SDL_BUTTON_MIDDLE	2
#define SDL_BUTTON_RIGHT	3
#define SDL_BUTTON_WHEELUP	4
#define SDL_BUTTON_WHEELDOWN	5
#define SDL_BUTTON_LMASK	SDL_BUTTON(SDL_BUTTON_LEFT)
#define SDL_BUTTON_MMASK	SDL_BUTTON(SDL_BUTTON_MIDDLE)
#define SDL_BUTTON_RMASK	SDL_BUTTON(SDL_BUTTON_RIGHT)


/* Ends C function definitions when using C++ */
#ifdef __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#endif
#include "close_code.h"

#endif /* _SDL_mouse_h */

/* vi: set ts=4 sw=4 expandtab: */
