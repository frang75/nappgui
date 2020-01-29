/*
 * NAppGUI-v1.1.1.2374 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: color.h
 * https://nappgui.com/en/draw2d/color.html
 *
 */

/* Color */

#include "draw2d.hxx"

__EXTERN_C

color_t color_rgb(const uint8_t r, const uint8_t g, const uint8_t b);

color_t color_rgba(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a);

color_t color_rgbaf(const real32_t r, const real32_t g, const real32_t b, const real32_t a);

color_t color_bgr(const uint32_t bgr);

color_t color_html(const char_t *html);

color_t color_alt(const color_t light_color, const color_t dark_color);

void color_to_html(const color_t color, char_t *html, const uint32_t size);

void color_get_rgb(const color_t color, uint8_t *r, uint8_t *g, uint8_t *b);

void color_get_rgbf(const color_t color, real32_t *r, real32_t *g, real32_t *b);

void color_get_rgba(const color_t color, uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a);

void color_get_rgbaf(const color_t color, real32_t *r, real32_t *g, real32_t *b, real32_t *a);

uint8_t color_get_alpha(const color_t color);

bool_t color_dark_mode(void);

extern const color_t kCOLOR_TRANSPARENT;

extern const color_t kCOLOR_LABEL;

extern const color_t kCOLOR_VIEW;

extern const color_t kCOLOR_LINE;

extern const color_t kCOLOR_LINK;

extern const color_t kCOLOR_TEXT;

extern const color_t kCOLOR_SELTEXT;

extern const color_t kCOLOR_BGTEXT;

extern const color_t kCOLOR_BGSELTEXT;

extern const color_t kCOLOR_HEADER;

extern const color_t kCOLOR_ROW1;

extern const color_t kCOLOR_ROW2;

extern const color_t kCOLOR_BLACK;

extern const color_t kCOLOR_WHITE;

extern const color_t kCOLOR_RED;

extern const color_t kCOLOR_GREEN;

extern const color_t kCOLOR_BLUE;

extern const color_t kCOLOR_YELLOW;

extern const color_t kCOLOR_CYAN;

extern const color_t kCOLOR_MAGENTA;

__END_C