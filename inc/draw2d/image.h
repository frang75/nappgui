/*
 * NAppGUI-v1.1.1.2372 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: image.h
 * https://nappgui.com/en/draw2d/image.html
 *
 */

/* Images */

#include "draw2d.hxx"

__EXTERN_C

Image *image_from_pixels(const uint32_t width, const uint32_t height, const pixformat_t format, const byte_t *data);

Image *image_from_file(const char_t *pathname, ferror_t *error);

Image *image_from_data(const byte_t *data, const uint32_t size);

Image *image_scale(const Image *image, const uint32_t nwidth, const uint32_t nheight);

Image *image_copy(const Image *image);

Image *image_read(Stream *stm);

bool_t image_to_file(const Image *image, const char_t *pathname, ferror_t *error);

void image_write(Stream *stream, const Image *image);

void image_destroy(Image **image);

void image_size(const Image *image, uint32_t *width, uint32_t *height);

void image_pixformat(const Image *image, pixformat_t *format);

void image_pixels(const Image *image, uint32_t *width, uint32_t *height, pixformat_t *format, Buffer **data);

void image_codec(Image *image, const codec_t codec);

codec_t image_get_codec(const Image *image);

uint32_t image_num_frames(const Image *image);

real32_t image_frame_length(const Image *image, const uint32_t findex);

Buffer *image_pixel_convers(const byte_t *data, const uint32_t width, const uint32_t height, const pixformat_t from, const pixformat_t to);

uint32_t image_bpp(const pixformat_t format);

__END_C
