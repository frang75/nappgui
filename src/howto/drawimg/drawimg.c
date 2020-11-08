/* Drawing on an image */

#include "nappgui.h"
#include "allres.h"

typedef struct _app_t App;

struct _app_t
{
    Window *window;
    Font *font;
    View *view;
    ImageView *iview;
    uint32_t res;
    real32_t angle;
    real32_t scale;
};

static uint32_t i_WIDTH[4] = {600, 300, 150, 75};
static uint32_t i_HEIGHT[4] = {400, 200, 100, 50};
static real32_t i_SCALE[4] = {1, .5f, .25f, .125f};

/*---------------------------------------------------------------------------*/

static void i_draw(DCtx *ctx, const T2Df *t2d_global, const Font *font)
{
    T2Df t2d_object;
    V2Df triangle[] = { {472,0}, {600,144}, {344,144} };
    const Image *image1 = gui_image(MONKEY_GIF);
    const Image *image2 = gui_image(ZOMBIE_PNG);
    t2d_scalef(&t2d_object, t2d_global, .5f, .5f);
    draw_matrix(ctx, &t2d_object);
    draw_image(ctx, image1, 688, 288);
    draw_line_color(ctx, color_rgb(255, 0, 0));
    draw_line_width(ctx, 3);
    draw_fill_color(ctx, color_rgb(0, 0, 255));
    t2d_rotatef(&t2d_object, t2d_global, kBMATH_PIf / 4);
    draw_matrix(ctx, &t2d_object);
    draw_rect(ctx, ekSKFILL, 0, 0, 320, 200);
    draw_fill_color(ctx, color_rgb(0, 255, 0));
    draw_matrix(ctx, t2d_global);
    draw_circle(ctx, ekSKFILL, 300, 200, 100);
    draw_line_color(ctx, color_rgb(0, 0, 255));
    draw_fill_color(ctx, color_rgb(255, 0, 0));
    draw_polygon(ctx, ekSKFILL, triangle, 3);
    t2d_scalef(&t2d_object, t2d_global, .7f, .7f);
    draw_matrix(ctx, &t2d_object);
    draw_image(ctx, image2, 0, 0);
    draw_font(ctx, font);
    draw_matrix(ctx, t2d_global);
    draw_text_color(ctx, color_rgb(255, 0, 0));
    draw_text(ctx, "Hello Drawings!", 200, 15);
    draw_line_color(ctx, color_rgb(0, 128, 0));
    draw_line(ctx, 150, 350, 330, 350);
    draw_line_color(ctx, color_rgb(0, 0, 255));
    draw_line(ctx, 100, 370, 330, 370);
    draw_line_color(ctx, color_rgb(128, 0, 0));
    draw_line(ctx, 20, 390, 330, 390);
}

/*---------------------------------------------------------------------------*/

static void i_OnDraw(App *app, Event *e)
{
    T2Df t2d;
    const EvDraw *p = event_params(e, EvDraw);
    t2d_rotatef(&t2d, kT2D_IDENTf, app->angle);
    t2d_scalef(&t2d, &t2d, app->scale, 1);
    draw_clear(p->ctx, color_rgb(200, 200, 200));
    i_draw(p->ctx, &t2d, app->font);
}

/*---------------------------------------------------------------------------*/

static void i_draw_img(App *app)
{
    T2Df t2d;
    DCtx *ctx = dctx_bitmap(i_WIDTH[app->res], i_HEIGHT[app->res], ekRGB24);
    Image *image;
    t2d_scalef(&t2d, kT2D_IDENTf, i_SCALE[app->res], i_SCALE[app->res]);
    draw_clear(ctx, color_rgb(200, 200, 200));
    i_draw(ctx, &t2d, app->font);
    image = dctx_image(&ctx);
    imageview_image(app->iview, image);
    image_destroy(&image);
}

/*---------------------------------------------------------------------------*/

static void i_OnResolution(App *app, Event *e)
{
    const EvButton *p = event_params(e, EvButton);
    app->res = p->index;
    i_draw_img(app);
}

/*---------------------------------------------------------------------------*/

static Layout *i_img_layout(App *app)
{
    Layout *layout = layout_create(5, 1);
    Label *label = label_create();
    Button *button1 = button_radio();
    Button *button2 = button_radio();
    Button *button3 = button_radio();
    Button *button4 = button_radio();
    label_text(label, "Image context:");
    button_text(button1, "600x400");
    button_text(button2, "300x200");
    button_text(button3, "150x100");
    button_text(button4, "75x50");
    button_state(button1, ekON);
    button_OnClick(button1, listener(app, i_OnResolution, App));
    layout_label(layout, label, 0, 0);
    layout_button(layout, button1, 1, 0);
    layout_button(layout, button2, 2, 0);
    layout_button(layout, button3, 3, 0);
    layout_button(layout, button4, 4, 0);
    layout_hmargin(layout, 0, 5);
    layout_hmargin(layout, 1, 10);
    layout_hmargin(layout, 2, 10);
    layout_hmargin(layout, 3, 10);
    return layout;
}

/*---------------------------------------------------------------------------*/

static void i_OnAngle(App *app, Event *e)
{
    const EvSlider *p = event_params(e, EvSlider);
    app->angle = (p->pos - .5f) * kBMATH_PIf;
    view_update(app->view);
}

/*---------------------------------------------------------------------------*/

static void i_OnScale(App *app, Event *e)
{
    const EvSlider *p = event_params(e, EvSlider);
    app->scale = p->pos + .5f;
    view_update(app->view);
}

/*---------------------------------------------------------------------------*/

static Layout *i_win_layout(App *app)
{
    Layout *layout = layout_create(3, 1);
    Label *label = label_create();
    Slider *slider1 = slider_create();
    Slider *slider2 = slider_create();
    label_text(label, "Window context: 600x400");
    slider_value(slider1, .5f);
    slider_value(slider2, .5f);
    slider_OnMoved(slider1, listener(app, i_OnAngle, App));
    slider_OnMoved(slider2, listener(app, i_OnScale, App));
    layout_label(layout, label, 0, 0);
    layout_slider(layout, slider1, 1, 0);
    layout_slider(layout, slider2, 2, 0);
    layout_hmargin(layout, 0, 10);
    layout_hmargin(layout, 1, 10);
    layout_hexpand2(layout, 1, 2, .5f);
    return layout;
}

/*---------------------------------------------------------------------------*/

static Panel *i_panel(App *app)
{
    Panel *panel = panel_create();
    Layout *layout = layout_create(2, 2);
    Layout *wlayout = i_win_layout(app);
    Layout *ilayout = i_img_layout(app);
    View *view = view_create();
    ImageView *iview = imageview_create();
    view_size(view, s2df(600, 400));
    imageview_size(iview, s2df(600, 400));
    view_OnDraw(view, listener(app, i_OnDraw, App));
    imageview_scale(iview, ekASPECT);
    layout_layout(layout, wlayout, 0, 0);
    layout_view(layout, view, 0, 1);
    layout_imageview(layout, iview, 1, 1);
    layout_layout(layout, ilayout, 1, 0);
    layout_halign(layout, 1, 0, ekLEFT);
    layout_margin(layout, 10);
    layout_hmargin(layout, 0, 5);
    layout_vmargin(layout, 0, 5);
    panel_layout(panel, layout);
    app->view = view;
    app->iview = iview;
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
    Panel *panel = i_panel(app);
    gui_respack(allres_respack);
    gui_language("");
    app->window = window_create(ekWNSTD, &panel);
    app->font = font_system(25.f, 0);
    app->res = 0;
    app->angle = 0;
    app->scale = 1;
    i_draw_img(app);
    window_title(app->window, "Drawing on an image");
    window_origin(app->window, v2df(500, 200));
    window_OnClose(app->window, listener(app, i_OnClose, App));
    window_show(app->window);
    return app;
}

/*---------------------------------------------------------------------------*/

static void i_destroy(App **app)
{
    window_destroy(&(*app)->window);
    font_destroy(&(*app)->font);
    heap_delete(app, App);
}

/*---------------------------------------------------------------------------*/

#include "osmain.h"
osmain(i_create, i_destroy, "", App)
