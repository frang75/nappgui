/* NAppGUI Hello World */

#include "nappgui.h"
#include "all.h"

typedef struct _app_t App;

struct _app_t
{
    Window *window;
    Image *image;
    ImageView *view;
    Cell *slider;
    uint32_t filter;
    real32_t angle;
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

static void i_apply_filter(App *app)
{
    Pixbuf *pixbuf = NULL;
    Pixbuf *output = NULL;
    Image *image = NULL;

    image_pixels(app->image, ekFIMAGE, &pixbuf, NULL);

    switch (app->filter) {
    case 0:
        output = pixbuf_convolution(pixbuf, i_IDENT_FILTER, i_IDENT_SIZE, i_IDENT_SIZE, i_IDENT_FACTOR, i_IDENT_BIAS);
        break;
    case 1:
        output = pixbuf_convolution(pixbuf, i_BLUR_FILTER, i_BLUR_SIZE, i_BLUR_SIZE, i_BLUR_FACTOR, i_BLUR_BIAS);
        break;
    case 2:
        output = pixbuf_convolution(pixbuf, i_MOTION_FILTER, i_MOTION_SIZE, i_MOTION_SIZE, i_MOTION_FACTOR, i_MOTION_BIAS);
        break;
    case 3:
        output = pixbuf_convolution(pixbuf, i_EDGE_FILTER, i_EDGE_SIZE, i_EDGE_SIZE, i_EDGE_FACTOR, i_EDGE_BIAS);
        break;
    case 4:
        output = pixbuf_convolution(pixbuf, i_SHARPEN_FILTER, i_SHARPEN_SIZE, i_SHARPEN_SIZE, i_SHARPEN_FACTOR, i_SHARPEN_BIAS);
        break;
    case 5:
        output = pixbuf_convolution(pixbuf, i_EMBOSS_FILTER, i_EMBOSS_SIZE, i_EMBOSS_SIZE, i_EMBOSS_FACTOR, i_EMBOSS_BIAS);
        break;
    case 6:
        output = pixbuf_rotate(pixbuf, (real32_t)(pixbuf_width(pixbuf) / 2), (real32_t)(pixbuf_height(pixbuf) / 2), app->angle * kBMATH_PIf, TRUE, color_gray(240));
        break;
    cassert_default();
    }

    cell_enabled(app->slider, app->filter == 6);
    image = image_from_pixbuf(output, NULL);
    imageview_image(app->view, image);
    pixbuf_destroy(&pixbuf);
    pixbuf_destroy(&output);
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

static void i_OnSlider(App *app, Event *e)
{
    const EvSlider *p = event_params(e, EvSlider);
    app->angle = p->pos;
    i_apply_filter(app);
}

/*---------------------------------------------------------------------------*/

static Panel *i_panel(App *app)
{
    Panel *panel = panel_create();
    Layout *layout1 = layout_create(1, 2);
    Layout *layout2 = layout_create(8, 1);
    Layout *layout3 = layout_create(2, 1);
    Button *button1 = button_radio();
    Button *button2 = button_radio();
    Button *button3 = button_radio();
    Button *button4 = button_radio();
    Button *button5 = button_radio();
    Button *button6 = button_radio();
    Button *button7 = button_radio();
    Slider *slider = slider_create();
    ImageView *view1 = imageview_create();
    ImageView *view2 = imageview_create();
    uint32_t w, h;
    button_text(button1, "Identity");
    button_text(button2, "Blur");
    button_text(button3, "Motion");
    button_text(button4, "Edge");
    button_text(button5, "Sharpen");
    button_text(button6, "Emboss");
    button_text(button7, "Rotation");
    button_state(button3, ekON);
    button_OnClick(button1, listener(app, i_OnButton, App));
    slider_OnMoved(slider, listener(app, i_OnSlider, App));
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
    layout_button(layout2, button7, 6, 0);
    layout_slider(layout2, slider, 7, 0);
    layout_imageview(layout3, view1, 0, 0);
    layout_imageview(layout3, view2, 1, 0);
    layout_layout(layout1, layout2, 0, 0);
    layout_layout(layout1, layout3, 0, 1);
    layout_margin(layout1, 10);
    layout_hmargin(layout2, 0, 15);
    layout_hmargin(layout2, 1, 15);
    layout_hmargin(layout2, 2, 15);
    layout_hmargin(layout2, 3, 15);
    layout_hmargin(layout2, 4, 15);
    layout_hmargin(layout2, 5, 15);
    layout_vmargin(layout1, 0, 5);
    layout_hmargin(layout3, 0, 5);
    layout_hexpand(layout2, 7);
    panel_layout(panel, layout1);
    app->slider = layout_cell(layout2, 7, 0);
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
