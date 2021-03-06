/**
 * \author  Tilen Majerle <tilen@majerle.eu>
 * \brief   GUI edit text widget
 *  
\verbatim
   ----------------------------------------------------------------------
    Copyright (c) 2017 Tilen Majerle

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without restriction,
    including without limitation the rights to use, copy, modify, merge,
    publish, distribute, sublicense, and/or sell copies of the Software, 
    and to permit persons to whom the Software is furnished to do so, 
    subject to the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
    AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
   ----------------------------------------------------------------------
\endverbatim
 */
#ifndef GUI_EDITTEXT_H
#define GUI_EDITTEXT_H

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup      GUI_WIDGETS
 * \{
 */
#include "gui_widget.h"
#if GUI_USE_KEYBOARD
#include "gui_keyboard.h"
#endif

/**
 * \defgroup        GUI_EDITTEXT Edit text
 * \brief           Single-line edit text widget
 * \{
 *
 * Edit text widget can receive keyboard input in unicode format and display text in single line.
 *
 * \image html image_widget_edittext.png Text view in focused state ready to accept keyboard entries (unicode)
 *
 * Example code of image above:
 * \code{c}                
//Create widget and allocate memory for text edit process
handle = GUI_EDITTEXT_Create(1, 10, 10, 400, 40, h, 0, 0);
GUI_WIDGET_AllocTextMemory(handle, 255);
GUI_WIDGET_SetText(handle, _GT("Edit text"));
\endcode
 */

/**
 * \brief           Edit text color list enumeration
 */
typedef enum GUI_EDITTEXT_COLOR_t {
    GUI_EDITTEXT_COLOR_BG = 0x00,           /*!< Background color index */
    GUI_EDITTEXT_COLOR_FG,                  /*!< Foreground color index */
    GUI_EDITTEXT_COLOR_BORDER,              /*!< Border color index */
} GUI_EDITTEXT_COLOR_t;

/**
 * \brief           Vertical align for edit text inside box
 */
typedef enum GUI_EDITTEXT_VALIGN_t {        
    GUI_EDITTEXT_VALIGN_TOP = GUI_VALIGN_TOP,       /*!< Vertical align top, default value */
    GUI_EDITTEXT_VALIGN_CENTER = GUI_VALIGN_CENTER, /*!< Vertical align center */
    GUI_EDITTEXT_VALIGN_BOTTOM = GUI_VALIGN_BOTTOM  /*!< Vertical align bottom */
} GUI_EDITTEXT_VALIGN_t;

/**
 * \brief           Horizontal align for edit text inside box
 */
typedef enum GUI_EDITTEXT_HALIGN_t {        
    GUI_EDITTEXT_HALIGN_LEFT = GUI_HALIGN_LEFT,     /*!< Horizontal align left, default value */
    GUI_EDITTEXT_HALIGN_CENTER = GUI_HALIGN_CENTER, /*!< Horizontal align center */
    GUI_EDITTEXT_HALIGN_RIGHT = GUI_HALIGN_RIGHT    /*!< Horizontal align right */
} GUI_EDITTEXT_HALIGN_t;
    
#if defined(GUI_INTERNAL) || defined(DOXYGEN)

#define GUI_EDITTEXT_FLAG_MULTILINE         ((uint8_t)0x01) /*!< Defines widget as multi-line edit */

/**
 * \brief           GUI EDIT TEXT widget structure
 */
typedef struct GUI_EDITTEXT_t {
    GUI_HANDLE C;                           /*!< GUI handle object, must always be first on list */
    
    uint8_t Flags;                          /*!< List of widget flags */
    GUI_EDITTEXT_VALIGN_t VAlign;           /*!< Vertical align setup */
    GUI_EDITTEXT_HALIGN_t HAlign;           /*!< Horizontal align setup */
} GUI_EDITTEXT_t;
#endif /* defined(GUI_INTERNAL) || defined(DOXYGEN) */

/**
 * \brief           Create new edit text widget
 * \param[in]       id: Widget unique ID to use for identity for callback processing
 * \param[in]       x: Widget X position relative to parent widget
 * \param[in]       y: Widget Y position relative to parent widget
 * \param[in]       width: Widget width in units of pixels
 * \param[in]       height: Widget height in uints of pixels
 * \param[in]       parent: Parent widget handle. Set to NULL to use current active parent widget
 * \param[in]       cb: Pointer to \ref GUI_WIDGET_CALLBACK_t callback function. Set to NULL to use default widget callback
 * \param[in]       flags: Flags for widget creation
 * \retval          > 0: \ref GUI_HANDLE_p object of created widget
 * \retval          0: Widget creation failed
 */
GUI_HANDLE_p GUI_EDITTEXT_Create(GUI_ID_t id, GUI_iDim_t x, GUI_iDim_t y, GUI_Dim_t width, GUI_Dim_t height, GUI_HANDLE_p parent, GUI_WIDGET_CALLBACK_t cb, uint16_t flags);

/**
 * \brief           Set color to specific part of widget
 * \param[in,out]   h: Widget handle
 * \param[in]       index: Color index. This parameter can be a value of \ref GUI_EDITTEXT_COLOR_t enumeration
 * \param[in]       color: Color value
 * \retval          1: Color was set ok
 * \retval          0: Color was not set
 */
uint8_t GUI_EDITTEXT_SetColor(GUI_HANDLE_p h, GUI_EDITTEXT_COLOR_t index, GUI_Color_t color);

/**
 * \brief           Set edit text to multi line mode
 * \note            When multiline is enabled, vertical text alignment is always top positioned
 * \param[in,out]   h: Widget handle
 * \param[in]       multiline: Set to 1 to enable multiline or 0 to disable
 * \retval          1: Color was set ok
 * \retval          0: Color was not set
 */
uint8_t GUI_EDITTEXT_SetMultiline(GUI_HANDLE_p h, uint8_t multiline);

/**
 * \brief           Set vertical align for text inside text box
 * \param[in,out]   h: Widget handle
 * \param[in]       align: Vertical align. This parameter can be a value of \ref GUI_EDITTEXT_VALIGN_t enumeration
 * \retval          1: Align was set ok
 * \retval          0: Align was not set
 */
uint8_t GUI_EDITTEXT_SetVAlign(GUI_HANDLE_p h, GUI_EDITTEXT_VALIGN_t align);

/**
 * \brief           Set horizontal align for text inside text box
 * \param[in,out]   h: Widget handle
 * \param[in]       align: Vertical align. This parameter can be a value of \ref GUI_EDITTEXT_HALIGN_t enumeration
 * \retval          1: Align was set ok
 * \retval          0: Align was not set
 */
uint8_t GUI_EDITTEXT_SetHAlign(GUI_HANDLE_p h, GUI_EDITTEXT_HALIGN_t align);

/**
 * \}
 */

/**
 * \}
 */

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif
