/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2021 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: pixbuf.h
 * https://nappgui.com/en/draw2d/pixbuf.html
 *
 */

/* Pixel buffers */

#include "draw2d.hxx"

__EXTERN_C

Pixbuf *pixbuf_create(const uint32_t width, const uint32_t height, const pixformat_t format);

Pixbuf *pixbuf_copy(const Pixbuf *pixbuf);

Pixbuf *pixbuf_trim(const Pixbuf *pixbuf, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t height);

Pixbuf *pixbuf_convert(const Pixbuf *pixbuf, const Palette *palette, const pixformat_t oformat);

Pixbuf *pixbuf_rotate(const Pixbuf *pixbuf, const real32_t cx, const real32_t cy, const real32_t angle, const bool_t clip, const uint32_t background);

Pixbuf *pixbuf_scale(const Pixbuf *pixbuf, const uint32_t nwidth, const uint32_t nheight);

Pixbuf *pixbuf_convolution(const Pixbuf *pixbuf, const real32_t *matrix, const uint32_t mwidth, const uint32_t mheight, const real32_t factor, const real32_t bias);

Pixbuf *pixbuf_threshold(const Pixbuf *pixbuf, const uint8_t threshold, const bool_t invert);

void pixbuf_destroy(Pixbuf **pixbuf);

uint32_t pixbuf_size(const Pixbuf *pixbuf);

uint32_t pixbuf_width(const Pixbuf *pixbuf);

uint32_t pixbuf_height(const Pixbuf *pixbuf);

pixformat_t pixbuf_format(const Pixbuf *pixbuf);

const byte_t *pixbuf_cdata(const Pixbuf *pixbuf);

byte_t *pixbuf_data(Pixbuf *pixbuf);

uint32_t pixbuf_format_bpp(const pixformat_t format);

uint32_t pixbuf_get(const Pixbuf *pixbuf, const uint32_t x, const uint32_t y);

void pixbuf_set(Pixbuf *pixbuf, const uint32_t x, const uint32_t y, const uint32_t value);

void pixbuf_invert(Pixbuf *pixbuf);

Pixbuf *pixbuf_and(const Pixbuf *pixbuf1, const Pixbuf *pixbuf2);

void pixbuf_bounds(const Pixbuf *pixbuf, const uint32_t background, uint32_t *x, uint32_t *y, uint32_t *width, uint32_t *height);

void pixbuf_fill(Pixbuf *pixbuf, const uint32_t value);

void pixbuf_fill_rect(Pixbuf *pixbuf, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t height, const uint32_t value);

void pixbuf_line(Pixbuf *pixbuf, const uint32_t x0, const uint32_t y0, const uint32_t x1, const uint32_t y1, const uint32_t value);

void pixbuf_circle(Pixbuf *pixbuf, const uint32_t x, const uint32_t y, const uint32_t r, const uint32_t value);

__END_C

