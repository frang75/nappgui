/* NAppGUI Hello World */

#include "nappgui.h"
#include "all.h"

typedef struct _app_t App;

struct _app_t
{
    Window *window;
    Image *image;
    ImageView *view;
    uint32_t filter;
};

/*---------------------------------------------------------------------------*/

static const uint32_t i_IDENT_SIZE = 3;
static const real32_t i_IDENT_FACTOR = 1;
static const real32_t i_IDENT_BIAS = 0;
static const real32_t i_IDENT_FILTER[] =
{
    0, 0, 0,
    0, 1, 0,
    0, 0, 0
};


static const uint32_t i_BLUR_SIZE = 5;
static const real32_t i_BLUR_FACTOR = 1.f / 256.f;
static const real32_t i_BLUR_BIAS = 0;
static const real32_t i_BLUR_FILTER[] =
{
    1,  4,  6,  4,  1,
    4, 16, 24, 16,  4,
    6, 24, 36, 24,  6,
    4, 16, 24, 16,  4,
    1,  4,  6,  4,  1,
};

static const uint32_t i_MOTION_SIZE = 9;
static const real32_t i_MOTION_FACTOR = 1.f / 9.f;
static const real32_t i_MOTION_BIAS = 0;
static const real32_t i_MOTION_FILTER[] =
{
  1, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 1,
};

static const uint32_t i_EDGE_SIZE = 5;
static const real32_t i_EDGE_FACTOR = 1;
static const real32_t i_EDGE_BIAS = 0;
static const real32_t i_EDGE_FILTER[] =
{
    -1,  0,  0,  0,  0,
    0, -2,  0,  0,  0,
    0,  0,  6,  0,  0,
    0,  0,  0, -2,  0,
    0,  0,  0,  0, -1,
};

static const uint32_t i_SHARPEN_SIZE = 3;
static const real32_t i_SHARPEN_FACTOR = 1;
static const real32_t i_SHARPEN_BIAS = 0;
static const real32_t i_SHARPEN_FILTER[] =
{
    1, 1, 1,
    1, -7, 1,
    1, 1, 1
};

static const uint32_t i_EMBOSS_SIZE = 3;
static const real32_t i_EMBOSS_FACTOR = 1;
static const real32_t i_EMBOSS_BIAS = 128;
static const real32_t i_EMBOSS_FILTER[] =
{
    -1, -1,  0,
    -1,  0,  1,
    0,  1,  1
};

/*---------------------------------------------------------------------------*/

static void i_convolution(const byte_t *rgb_data, byte_t *result, const uint32_t w, const uint32_t h, const uint32_t bpp, const real32_t *filter, const uint32_t fsize, const real32_t factor, const real32_t bias)
{
    register uint32_t i, j;
    register uint32_t fi, fj;

    for(j = 0; j < h; ++j)
    for(i = 0; i < w; ++i)
    {
        real32_t r = 0, g = 0, b = 0;
        for(fj = 0; fj < fsize; ++fj)
        for(fi = 0; fi < fsize; ++fi)
        {
            uint32_t imageX = (i - fsize / 2 + fi + w) % w;
            uint32_t imageY = (j - fsize / 2 + fj + h) % h;
            const byte_t *pixel = rgb_data + bpp * (imageY * w + imageX);
            r += pixel[0 % bpp] * filter[fj * fsize + fi];
            g += pixel[1 % bpp] * filter[fj * fsize + fi];
            b += pixel[2 % bpp] * filter[fj * fsize + fi];
        }

        r = bmath_clampf(r * factor + bias, 0, 255);
        g = bmath_clampf(g * factor + bias, 0, 255);
        b = bmath_clampf(b * factor + bias, 0, 255);
        result[0] = (byte_t)r;
        result[1] = (byte_t)g;
        result[2] = (byte_t)b;
        result += 3;
    }
}

/*---------------------------------------------------------------------------*/

static void i_apply_filter(App *app)
{
    uint32_t w, h;
    pixformat_t format;
    Buffer *data = NULL;
    Buffer *result = NULL;
    const real32_t *filter = NULL;
    uint32_t filter_size = 0;
    real32_t filter_factor = 0;
    real32_t filter_bias = 0;
    Image *image = NULL;

    image_pixels(app->image, &w, &h, &format, &data);
    result = buffer_create(w * h * 3);

    switch (app->filter) {
    case 0:
        filter = i_IDENT_FILTER;
        filter_size = i_IDENT_SIZE;
        filter_factor = i_IDENT_FACTOR;
        filter_bias = i_IDENT_BIAS;
        break;
    case 1:
        filter = i_BLUR_FILTER;
        filter_size = i_BLUR_SIZE;
        filter_factor = i_BLUR_FACTOR;
        filter_bias = i_BLUR_BIAS;
        break;
    case 2:
        filter = i_MOTION_FILTER;
        filter_size = i_MOTION_SIZE;
        filter_factor = i_MOTION_FACTOR;
        filter_bias = i_MOTION_BIAS;
        break;
    case 3:
        filter = i_EDGE_FILTER;
        filter_size = i_EDGE_SIZE;
        filter_factor = i_EDGE_FACTOR;
        filter_bias = i_EDGE_BIAS;
        break;
    case 4:
        filter = i_SHARPEN_FILTER;
        filter_size = i_SHARPEN_SIZE;
        filter_factor = i_SHARPEN_FACTOR;
        filter_bias = i_SHARPEN_BIAS;
        break;
    case 5:
        filter = i_EMBOSS_FILTER;
        filter_size = i_EMBOSS_SIZE;
        filter_factor = i_EMBOSS_FACTOR;
        filter_bias = i_EMBOSS_BIAS;
        break;
    cassert_default();
    }

    i_convolution(buffer_data(data), buffer_data(result), w, h, image_bpp(format), filter, filter_size, filter_factor, filter_bias);
    image = image_from_pixels(w, h, ekRGB24, buffer_data(result));
    imageview_image(app->view, image);
    buffer_destroy(&data);
    buffer_destroy(&result);
    image_destroy(&image);
}

/*---------------------------------------------------------------------------*/

static void i_OnButton(App *app, Event *e)
{
    const EvButton *p = event_params(e, EvButton);
    app->filter = p->index;
    i_apply_filter(app);
}

/*---------------------------------------------------------------------------*/

static Panel *i_panel(App *app)
{
    Panel *panel = panel_create();
    Layout *layout1 = layout_create(1, 2);
    Layout *layout2 = layout_create(6, 1);
    Layout *layout3 = layout_create(2, 1);
    Button *button1 = button_radio();
    Button *button2 = button_radio();
    Button *button3 = button_radio();
    Button *button4 = button_radio();
    Button *button5 = button_radio();
    Button *button6 = button_radio();
    ImageView *view1 = imageview_create();
    ImageView *view2 = imageview_create();
    uint32_t w, h;
    button_text(button1, "Identity");
    button_text(button2, "Blur");
    button_text(button3, "Motion");
    button_text(button4, "Edge");
    button_text(button5, "Sharpen");
    button_text(button6, "Emboss");
    button_state(button3, ekON);
    button_OnClick(button1, listener(app, i_OnButton, App));
    image_size(app->image, &w, &h);
    imageview_image(view1, app->image);
    imageview_image(view2, app->image);
    imageview_size(view1, s2di(w, h));
    imageview_size(view2, s2di(w, h));
    layout_button(layout2, button1, 0, 0);
    layout_button(layout2, button2, 1, 0);
    layout_button(layout2, button3, 2, 0);
    layout_button(layout2, button4, 3, 0);
    layout_button(layout2, button5, 4, 0);
    layout_button(layout2, button6, 5, 0);
    layout_imageview(layout3, view1, 0, 0);
    layout_imageview(layout3, view2, 1, 0);
    layout_layout(layout1, layout2, 0, 0);
    layout_layout(layout1, layout3, 0, 1);
    layout_margin(layout1, 10);
    layout_vmargin(layout1, 0, 5);
    layout_hmargin(layout3, 0, 5);
    panel_layout(panel, layout1);
    app->view = view2;
    return panel;
}

/*---------------------------------------------------------------------------*/

static void i_OnClose(App *app, Event *e)
{
    osapp_finish();
    unref(app);
    unref(e);
}

/*---------------------------------------------------------------------------*/

static App *i_create(void)
{
    App *app = heap_new0(App);
    ResPack *pack = all_respack("");
    Panel *panel = NULL;
    app->image = image_copy(image_from_resource(pack, IMAGE_JPG));
    panel = i_panel(app);
    app->window = window_create(ekWNSTD, &panel);
    app->filter = 2;
    i_apply_filter(app);
    window_title(app->window, "Image Filters");
    window_origin(app->window, v2df(500, 200));
    window_OnClose(app->window, listener(app, i_OnClose, App));
    window_show(app->window);
    respack_destroy(&pack);
    return app;
}

/*---------------------------------------------------------------------------*/

static void i_destroy(App **app)
{
    window_destroy(&(*app)->window);
    image_destroy(&(*app)->image);
    heap_delete(app, App);
}

/*---------------------------------------------------------------------------*/

#include "osmain.h"
osmain(i_create, i_destroy, "", App)
