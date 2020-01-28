/* Images from URL */

#include "nappgui.h"
#include "httpreq.h"

typedef struct _app_t App;

struct _app_t
{
    Window *window;
    ImageView *view;
    uint32_t selected;
    Label *imgname;
    Label *imgsize;
    Label *imgres;
    Label *imgformat;
};

static const char_t *i_HOST = "test.nappgui.com";
static const char_t *i_URI = "/image_formats";
static const char_t *i_FILES[] = {
                            "anim_04_bat.gif",
                            "anim_04_cube.gif",
                            "anim_04_dragon.gif",
                            "anim_04_game.gif",
                            "anim_04_item.gif",
                            "anim_04_player.gif",
                            "home_01_gray.jpg",
                            "home_01_rgb.jpg",
                            "home_02_index02.png",
                            "home_02_index02c.png",
                            "home_02_index04.png",
                            "home_02_index04c.png",
                            "home_02_index16.png",
                            "home_02_index16c.png",
                            "home_02_index256.png",
                            "home_02_index256c.png",
                            "home_02_rgba.png",
                            "home_02_rgbac.png",
                            "sea_01_gray.jpg",
                            "sea_01_rgb.jpg",
                            "sea_02_index02.png",
                            "sea_02_index02c.png",
                            "sea_02_index04.png",
                            "sea_02_index04c.png",
                            "sea_02_index16.png",
                            "sea_02_index16c.png",
                            "sea_02_index256.png",
                            "sea_02_index256c.png",
                            "sea_02_rgb.png",
                            "sea_02_rgbc.png",
                            "sea_03_bmp_index02.bmp",
                            "sea_03_bmp_index04.bmp",
                            "sea_03_bmp_index16.bmp",
                            "sea_03_bmp_index256.bmp",
                            "sea_03_bmp_rgb.bmp" };

/*---------------------------------------------------------------------------*/

static __INLINE const char_t *i_pixformat(const pixformat_t format)
{
    switch (format) {
    case ekGRAY8:
        return "GrayScale8";
    case ekRGB24:
        return "RGB24";
    case ekRGBA32:
        return "RGBA32";
    }
    return "";
}

/*---------------------------------------------------------------------------*/

static void i_download(App *app)
{
    String *uri = str_printf("%s/%s", i_URI, i_FILES[app->selected]);
    ierror_t err;
    Stream *stm = http_dget(i_HOST, 80, tc(uri), &err);
    if (stm != NULL)
    {
        uint32_t width, height;
        pixformat_t format;
        uint64_t start = stm_bytes_readed(stm);
        Image *image = image_read(stm);
        uint64_t end = stm_bytes_readed(stm);
        String *ssize = str_printf("%d bytes", (uint32_t)(end - start));
        String *sres;
        // Test for image pixels read
        if (image_get_codec(image) != ekGIF)
        {
            Buffer *pixdata = NULL;
            image_pixels(image, &width, &height, &format, &pixdata);
            image_destroy(&image);
            image = image_from_pixels(width, height, format, buffer_data(pixdata));
            buffer_destroy(&pixdata);
        }
        else
        {
            image_size(image, &width, &height);
            image_pixformat(image, &format);
        }

        imageview_image(app->view, image);
        sres = str_printf("%d x %d", width, height);
        label_text(app->imgname, i_FILES[app->selected]);
        label_text(app->imgsize, tc(ssize));
        label_text(app->imgres, tc(sres));
        label_text(app->imgformat, i_pixformat(format));
        image_destroy(&image);
        stm_close(&stm);
        str_destroy(&ssize);
        str_destroy(&sres);
    }

    str_destroy(&uri);
}

/*---------------------------------------------------------------------------*/

static Layout* i_label(const char_t *title, Label **info)
{
    Layout *layout = layout_create(2, 1);
    Label *label = label_create();
    Font *font = font_system(font_regular_size(), ekFBOLD);
    *info = label_create();
    label_text(label, title);
    label_font(label, font);
    layout_label(layout, label, 0, 0);
    layout_label(layout, *info, 1, 0);
    layout_halign(layout, 1, 0, ekJUSTIFY);
    layout_hmargin(layout, 0, 5);
    layout_hexpand(layout, 1);
    font_destroy(&font);
    return layout;
}

/*---------------------------------------------------------------------------*/

static void i_add_files(PopUp *popup)
{
    register uint32_t i, n = sizeof(i_FILES) / sizeof(char_t*);
    for (i = 0; i < n; ++i)
        popup_add_elem(popup, i_FILES[i], NULL);

    popup_list_height(popup, 20);
}

/*---------------------------------------------------------------------------*/

static void i_OnSelect(App *app, Event *e)
{
    const EvButton *p = event_params(e, EvButton);
    app->selected = p->index;
    i_download(app);
}

/*---------------------------------------------------------------------------*/

static Panel *i_panel(App *app)
{
    Panel *panel = panel_create();
    Layout *layout1 = layout_create(2, 1);
    Layout *layout2 = layout_create(1, 2);
    Layout *layout3 = layout_create(1, 5);
    Label *label = label_create();
    PopUp *popup = popup_create();
    ImageView *view = imageview_create();
    app->view = view;
    label_text(label, "Images");
    i_add_files(popup);
    popup_OnSelect(popup, listener(app, i_OnSelect, App));
    imageview_size(view, s2df(600, 400));
    layout_label(layout2, label, 0, 0);
    layout_popup(layout2, popup, 0, 1);
    layout_imageview(layout3, view, 0, 0);
    layout_layout(layout3, i_label("Image name:", &app->imgname), 0, 1);
    layout_layout(layout3, i_label("Image size:", &app->imgsize), 0, 2);
    layout_layout(layout3, i_label("Image dimensions:", &app->imgres), 0, 3);
    layout_layout(layout3, i_label("Image format:", &app->imgformat), 0, 4);
    layout_layout(layout1, layout2, 0, 0);
    layout_layout(layout1, layout3, 1, 0);
    layout_margin(layout1, 5);
    layout_hmargin(layout1, 0, 5);
    layout_vmargin(layout2, 0, 5);
    layout_vmargin(layout3, 0, 5);
    layout_vmargin(layout3, 1, 3);
    layout_vmargin(layout3, 2, 3);
    layout_valign(layout1, 0, 0, ekTOP);
    panel_layout(panel, layout1);
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
    String *title = str_printf("Images from URL '%s%s'", i_HOST, i_URI);
    app->window = window_create(ekWNSTD, &panel);
    app->selected = 0;
    i_download(app);
    window_title(app->window, tc(title));
    window_origin(app->window, v2df(500, 200));
    window_OnClose(app->window, listener(app, i_OnClose, App));
    window_show(app->window);
    str_destroy(&title);
    return app;
}

/*---------------------------------------------------------------------------*/

static void i_destroy(App **app)
{
    window_destroy(&(*app)->window);
    heap_delete(app, App);
}

/*---------------------------------------------------------------------------*/

#include "osmain.h"
osmain(i_create, i_destroy, "", App)
