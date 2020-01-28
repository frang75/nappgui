/*
 * NAppGUI-v1.1.1.2372 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: gui.hxx
 * https://nappgui.com/en/gui/gui.html
 *
 */

/* Graphics User Interface */

#ifndef __GUI_HXX__
#define __GUI_HXX__

#include "draw2d.hxx"

typedef enum _orient_t
{
    ekHORIZONTAL = 1,
    ekVERTICAL
} orient_t;

typedef enum _state_t
{
    ekOFF = 0,
    ekON,
    ekMIXED
} state_t;

typedef enum _mouse_t
{
    ekMLEFT = 1,
    ekMRIGHT,
    ekMMIDDLE
} mouse_t;

typedef enum _close_t
{
    ekCLESC = 1,
    ekCLINTRO,
    ekCLBUTTON,
    ekCLDEACT
} close_t;

typedef enum _scale_t
{
    ekAUTO = 1,
    ekSNONE,
    ekASPECT,
    ekASPECTDW
} scale_t;

typedef enum _key_t
{
    ekKEY_UNDEF             = 0,
    ekKEY_A                 = 1,
    ekKEY_S                 = 2,
    ekKEY_D                 = 3,
    ekKEY_F                 = 4,
    ekKEY_H                 = 5,
    ekKEY_G                 = 6,
    ekKEY_Z                 = 7,
    ekKEY_X                 = 8,
    ekKEY_C                 = 9,
    ekKEY_V                 = 10,
    ekKEY_BACKSLASH         = 11,
    ekKEY_B                 = 12,
    ekKEY_Q                 = 13,
    ekKEY_W                 = 14,
    ekKEY_E                 = 15,
    ekKEY_R                 = 16,
    ekKEY_Y                 = 17,
    ekKEY_T                 = 18,
    ekKEY_1                 = 19,
    ekKEY_2                 = 20,
    ekKEY_3                 = 21,
    ekKEY_4                 = 22,
    ekKEY_6                 = 23,
    ekKEY_5                 = 24,
    ekKEY_9                 = 25,
    ekKEY_7                 = 26,
    ekKEY_8                 = 27,
    ekKEY_0                 = 28,
    ekKEY_RBRACKET          = 29,
    ekKEY_O                 = 30,
    ekKEY_U                 = 31,
    ekKEY_LBRACKET          = 32,
    ekKEY_I                 = 33,
    ekKEY_P                 = 34,
    ekKEY_RETURN            = 35,
    ekKEY_L                 = 36,
    ekKEY_J                 = 37,
    ekKEY_SEMICOLON         = 38,
    ekKEY_K                 = 39,
    ekKEY_APOSTROPHE        = 40,
    ekKEY_COMMA             = 41,
    ekKEY_MINUS             = 42,
    ekKEY_N                 = 43,
    ekKEY_M                 = 44,
    ekKEY_PERIOD            = 45,
    ekKEY_TAB               = 46,
    ekKEY_SPACE             = 47,
    ekKEY_MAJOR_MINOR       = 48,
    ekKEY_BACK              = 49,
    ekKEY_ESCAPE            = 50,
    ekKEY_F17               = 51,
    ekKEY_NUMPAD_DECIMAL    = 52,
    ekKEY_NUMPAD_MULT       = 53,
    ekKEY_NUMPAD_ADD        = 54,
    ekKEY_NUMLOCK           = 55,
    ekKEY_NUMPAD_DIV        = 56,
    ekKEY_NUMPAD_RETURN     = 57,
    ekKEY_NUMPAD_SUBTRACT   = 58,
    ekKEY_F18               = 59,
    ekKEY_F19               = 60,
    ekKEY_NUMPAD_EQUAL      = 61,
    ekKEY_NUMPAD0           = 62,
    ekKEY_NUMPAD1           = 63,
    ekKEY_NUMPAD2           = 64,
    ekKEY_NUMPAD3           = 65,
    ekKEY_NUMPAD4           = 66,
    ekKEY_NUMPAD5           = 67,
    ekKEY_NUMPAD6           = 68,
    ekKEY_NUMPAD7           = 69,
    ekKEY_NUMPAD8           = 70,
    ekKEY_NUMPAD9           = 71,
    ekKEY_F5                = 72,
    ekKEY_F6                = 73,
    ekKEY_F7                = 74,
    ekKEY_F3                = 75,
    ekKEY_F8                = 76,
    ekKEY_F9                = 77,
    ekKEY_F11               = 78,
    ekKEY_F13               = 79,
    ekKEY_F16               = 80,
    ekKEY_F14               = 81,
    ekKEY_F10               = 82,
    ekKEY_F12               = 83,
    ekKEY_F15               = 84,
    ekKEY_PAGE_UP           = 85,
    ekKEY_PAGE_BEGIN        = 86,
    ekKEY_SUPR              = 87,
    ekKEY_F4                = 88,
    ekKEY_PAGE_DOWN         = 89,
    ekKEY_F2                = 90,
    ekKEY_PAGE_END          = 91,
    ekKEY_F1                = 92,
    ekKEY_LEFT              = 93,
    ekKEY_RIGHT             = 94,
    ekKEY_DOWN              = 95,
    ekKEY_UP                = 96,
    ekKEY_ALT               = 100,
    ekKEY_CONTROL           = 101
} vkey_t;

typedef enum _keymod_t
{
    ekKEYMOD_NONE           = 0,
    ekKEYMOD_SHIFT          = 1,
    ekKEYMOD_CONTROL        = 1 << 1,
    ekKEYMOD_ALT            = 1 << 2,
    ekKEYMOD_COMMAND        = 1 << 3
} keymod_t;

typedef enum _view_flag_t
{
    ekHSCROLL       = 0x8,
    ekVSCROLL       = 0x10
} view_flag_t;

typedef enum _window_flag_t
{
    ekWNFLAG = 0,
    ekWNEDGE = 1,
    ekWNTITLE = 2,
    ekWNMAX = 4,
    ekWNMIN = 8,
    ekWNCLOSE = 16,
    ekWNRES = 32,
    ekWNSTD = ekWNTITLE | ekWNMIN | ekWNCLOSE,
    ekWNSRES = ekWNSTD | ekWNMAX | ekWNRES
} window_flag_t;

typedef enum _gevent_t
{
    ekEVENT_LABEL = 0x400,
    ekEVENT_BUTTON,
    ekEVENT_POPUP,
    ekEVENT_SLIDER,
    ekEVENT_UPDOWN,
    ekEVENT_TXTFILTER,
    ekEVENT_TXTCHANGE,
    ekEVENT_FOCUS,
    ekEVENT_MENU,
    ekEVENT_CLICK,
    ekEVENT_MOVED,
    ekEVENT_ENTER,
    ekEVENT_EXIT,
    ekEVENT_BEGDRAG,
    ekEVENT_DRAG,
    ekEVENT_ENDDRAG,
    ekEVENT_WHEEL,
    ekEVENT_KEYDOWN,
    ekEVENT_KEYUP,
    ekEVENT_DRAW,
    ekEVENT_RESIZE,
    ekEVENT_WNDMOVED,
    ekEVENT_WNDSIZING,
    ekEVENT_WNDSIZE,
    ekEVENT_WNDCLOSE,
    ekEVENT_THEME,

    ekEVENT_OBJVALIDATE,
    ekEVENT_OBJCHANGE

} event_t;

typedef struct _control_t Control;
typedef struct _label_t Label;
typedef struct _button_t Button;
typedef struct _popup_t PopUp;
typedef struct _edit_t Edit;
typedef struct _combo_t Combo;
typedef struct _updown_t UpDown;
typedef struct _slider_t Slider;
typedef struct _progress_t Progress;
typedef struct _view_t View;
typedef struct _textview_t TextView;
typedef struct _imageview_t ImageView;
typedef struct _tableview_t TableView;
typedef struct _splitview_t SplitView;
typedef struct _layout_t Layout;
typedef struct _cell_t Cell;
typedef struct _panel_t Panel;
typedef struct _window_t Window;
typedef struct _menu_t Menu;
typedef struct _menu_item_t MenuItem;
typedef struct _evbutton_t EvButton;
typedef struct _evslider_t EvSlider;
typedef struct _evtext_t EvText;
typedef struct _evtextfilter_t EvTextFilter;
typedef struct _evdraw_t EvDraw;
typedef struct _evmouse_t EvMouse;
typedef struct _evwheel_t EvWheel;
typedef struct _evkey_t EvKey;
typedef struct _evpos_t EvPos;
typedef struct _evsize_t EvSize;
typedef struct _evwinclose_t EvWinClose;
typedef struct _evmenu_t EvMenu;

typedef ResPack*(*FPtr_respack)(const char_t *locale);

struct _evbutton_t
{
    uint32_t index;
    state_t state;
    const char_t *text;
};

struct _evslider_t
{
    real32_t pos;
    real32_t incr;
};

struct _evtext_t
{
    const char_t *text;
    uint32_t cpos;
};

#define kTEXTFILTER_SIZE    1024

struct _evtextfilter_t
{
    bool_t apply;
    char_t text[kTEXTFILTER_SIZE];
    uint32_t cpos;
};

struct _evdraw_t
{
    DCtx *ctx;
    real32_t visible_x;
    real32_t visible_y;
    real32_t visible_width;
    real32_t visible_height;
    real32_t width;
    real32_t height;
};

struct _evmouse_t
{
    real32_t x;
    real32_t y;
    real32_t width;
    real32_t height;
    mouse_t button;
    uint32_t count;
};

struct _evwheel_t
{
    real32_t x;
    real32_t y;
    real32_t dx;
    real32_t dy;
    real32_t dz;
};

struct _evkey_t
{
    vkey_t key;
};

struct _evpos_t
{
    real32_t x;
    real32_t y;
};

struct _evsize_t
{
    real32_t width;
    real32_t height;
};

struct _evwinclose_t
{
    close_t origin;
};

struct _evmenu_t
{
    uint32_t index;
    state_t state;
    const char_t *str;
};

#endif
