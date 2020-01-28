/* Multi-threaded fractals */

#include "nappgui.h"

typedef struct _app_t App;
typedef struct _thdata_t ThData;

struct _app_t
{
    Window *window;
    ImageView *view;
    Label *time_label;
    Clock *clock;
    pixformat_t format;
    uint32_t threads;
    bool_t vertical;
    real64_t fct;
};

struct _thdata_t
{
    real64_t fct;
    real64_t kreal;
    real64_t kimag;
    uint32_t *imgdata;
    uint32_t imgwidth;
    uint32_t imgheight;
    uint32_t i;
    uint32_t j;
    uint32_t width;
    uint32_t height;
};

static const real64_t i_FCT = 2.85;
static const uint32_t i_ITERATIONS = 512;
static const uint32_t i_WIDTH = 601;
static const uint32_t i_HEIGHT = 601;

/*---------------------------------------------------------------------------*/

static uint32_t i_inset(real64_t zreal, real64_t zimag, real64_t creal, real64_t cimag)
{
    uint32_t i;
    for(i = 0; i < i_ITERATIONS; ++i) 
    {
        real64_t ztmp, zdist;
        ztmp = zreal * zreal - zimag * zimag;
        zimag = zreal * zimag + zreal * zimag;
        zreal = ztmp;
        zreal = zreal + creal;
        zimag = zimag + cimag;
        zdist = zimag * zimag  + zreal * zreal;
        if (zdist > 3) 
            return i;
    }

    return 0;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_julia_thread(ThData *data)
{
    real64_t fct = data->fct;
    uint32_t imgwidth = data->imgwidth;
    real64_t freal = fct / imgwidth;
    real64_t fimag = fct / data->imgheight;
    real64_t kreal = data->kreal;
    real64_t kimag = data->kimag;
    uint32_t *imgdata = data->imgdata;
    uint32_t res, pos;
    real64_t creal, cimag;
    register uint32_t stj = data->j;
    register uint32_t edj = data->j + data->height;
    register uint32_t sti = data->i;
    register uint32_t edi = data->i + data->width;
    register uint32_t i, j;

    for(j = stj; j < edj; ++j)
    {
        pos = j * imgwidth + data->i;
        cimag = fimag * j - (fct / 2);

        for(i = sti; i < edi; ++i)
        {
            creal = freal * i - (fct / 2);
            res = i_inset(creal, cimag, kreal, kimag);
            if (res > 0)
            {
                uint8_t n_res = res % 255;
                if ( res < ( i_ITERATIONS >> 1 ) )
                    res = color_rgb((uint8_t)(n_res << 2), (uint8_t)(n_res << 3), (uint8_t)(n_res << 4));
                else
                    res = color_rgb((uint8_t)(n_res << 4), (uint8_t)(n_res << 2), (uint8_t)(n_res << 5));
            }
            else
            {
                res = kCOLOR_BLACK;
            }

            imgdata[pos++] = res;
        }
    }

    return 5;
}

/*---------------------------------------------------------------------------*/

static void i_julia(const uint32_t nthreads, const bool_t vertical, const real64_t fct, const real64_t kreal, const real64_t kimag, uint32_t *imgdata, const uint32_t imgwidth, const uint32_t imgheight)
{
    ThData data[8];
    data[0].fct = fct;
    data[0].kreal = kreal;
    data[0].kimag = kimag;
    data[0].imgdata = imgdata;
    data[0].imgwidth = imgwidth;
    data[0].imgheight = imgheight;

    if (nthreads == 1)
    {
        data[0].i = 0;
        data[0].j = 0;
        data[0].width = imgwidth;
        data[0].height = imgheight;
        i_julia_thread(&data[0]);
    }
    else
    {
        Thread *thread[8];

        register uint32_t i;
        if (vertical == TRUE)
        {
            uint32_t width = imgwidth / nthreads;
            for (i = 0; i < nthreads; ++i)
            {
                data[i] = data[0];
                data[i].i = i * width;
                data[i].j = 0;
                data[i].width = width;
                data[i].height = imgheight;
            }

            data[nthreads-1].width += (imgwidth - (width * nthreads));
        }
        else
        {
            uint32_t height = imgheight / nthreads;
            for (i = 0; i < nthreads; ++i)
            {
                data[i] = data[0];
                data[i].i = 0;
                data[i].j = i * height;
                data[i].width = imgwidth;
                data[i].height = height;
            }

            data[nthreads-1].height += (imgheight - (height * nthreads));
        }

        for (i = 0; i < nthreads; ++i)
            thread[i] = bthread_create(i_julia_thread, &data[i], ThData);

        for (i = 0; i < nthreads; ++i)
        {
            uint32_t thid = bthread_wait(thread[i]);
            cassert_unref(thid == 5, thid);
            bthread_close(&thread[i]);
        }
    }
}

/*---------------------------------------------------------------------------*/

static void i_image(App *app)
{
    uint32_t *imgdata = heap_new_n(i_WIDTH * i_HEIGHT, uint32_t);
    real64_t rfactor = app->fct / i_WIDTH;
    real64_t ifactor = app->fct / i_HEIGHT;
    real64_t kreal = rfactor * 307 - 2;
    real64_t kimag = ifactor * 184 - 1.4;
    Image *image = NULL;
    real64_t timems;
    String *str;

    clock_reset(app->clock);
    i_julia(app->threads, app->vertical, app->fct, kreal, kimag, imgdata, i_WIDTH, i_HEIGHT);
    timems = 1000. * clock_elapsed(app->clock);
    str = str_printf("%.3f milliseconds", timems);
    label_text(app->time_label, tc(str));
    str_destroy(&str);

    if (app->format == ekRGBA32)
    {
        image = image_from_pixels(i_WIDTH, i_HEIGHT, ekRGBA32, (const byte_t*)imgdata);
    }
    else
    {
        Buffer *convers = image_pixel_convers((const byte_t*)imgdata, i_WIDTH, i_HEIGHT, ekRGBA32, app->format);
        image = image_from_pixels(i_WIDTH, i_HEIGHT, app->format, buffer_data(convers));
        buffer_destroy(&convers);
    }

    imageview_image(app->view, image);
    image_destroy(&image);
    heap_delete_n(&imgdata, i_WIDTH * i_HEIGHT, uint32_t);
}

/*---------------------------------------------------------------------------*/

static void i_OnSlider(App *app, Event *e)
{
    const EvSlider *p = event_params(e, EvSlider);
    real64_t st = i_FCT - 1;
    real64_t ed = i_FCT + 1;
    app->fct = ((ed - st) * p->pos) + st;
    i_image(app);
}

/*---------------------------------------------------------------------------*/

static void i_OnPixformat(App *app, Event *e)
{
    const EvButton *p = event_params(e, EvButton);
    if (p->index == 0)
        app->format = ekRGBA32;
    else if (p->index == 1)
        app->format = ekRGB24;
    else if (p->index == 2)
        app->format = ekGRAY8;
    i_image(app);
}

/*---------------------------------------------------------------------------*/

static void i_OnThreads(App *app, Event *e)
{
    const EvButton *p = event_params(e, EvButton);
    switch(p->index) {
    case 0: app->threads = 1; break;
    case 1: app->threads = 2; break;
    case 2: app->threads = 3; break;
    case 3: app->threads = 4; break;
    case 4: app->threads = 8; break; }
    i_image(app);
}

/*---------------------------------------------------------------------------*/

static void i_OnVertical(App *app, Event *e)
{
    const EvButton *p = event_params(e, EvButton);
    app->vertical = p->index == 0 ? TRUE : FALSE;
    i_image(app);
}

/*---------------------------------------------------------------------------*/

static Panel *i_panel(App *app)
{
    Panel *panel = panel_create();
    Layout *layout1 = layout_create(1, 2);
    Layout *layout2 = layout_create(3, 2);
    Layout *layout3 = layout_create(3, 1);
    Label *label1 = label_create();
    Label *label2 = label_create();
    Label *label3 = label_create();
    PopUp *popup1 = popup_create();
    PopUp *popup2 = popup_create();
    Slider *slider = slider_create();
    Button *button1 = button_radio();
    Button *button2 = button_radio();
    ImageView *view = imageview_create();
    label_text(label1, "PixFormat:");
    label_text(label2, "Threads:");
    popup_add_elem(popup1, "RGBA32", NULL);
    popup_add_elem(popup1, "RGB24", NULL);
    popup_add_elem(popup1, "GRAY8", NULL);
    popup_selected(popup1, 0);
    popup_OnSelect(popup1, listener(app, i_OnPixformat, App));
    popup_add_elem(popup2, "1", NULL);
    popup_add_elem(popup2, "2", NULL);
    popup_add_elem(popup2, "3", NULL);
    popup_add_elem(popup2, "4", NULL);
    popup_add_elem(popup2, "8", NULL);
    popup_selected(popup2, 0);
    popup_OnSelect(popup2, listener(app, i_OnThreads, App));
    slider_value(slider, .5f);
    slider_OnMoved(slider, listener(app, i_OnSlider, App));
    button_text(button1, "Vert");
    button_text(button2, "Hotz");
    button_state(button1, ekON);
    button_OnClick(button1, listener(app, i_OnVertical, App));
    imageview_size(view, s2di(i_WIDTH, i_HEIGHT));
    layout_label(layout2, label1, 0, 0);
    layout_popup(layout2, popup1, 1, 0);
    layout_slider(layout2, slider, 2, 0);
    layout_label(layout2, label2, 0, 1);
    layout_popup(layout2, popup2, 1, 1);
    layout_button(layout3, button1, 0, 0);
    layout_button(layout3, button2, 1, 0);
    layout_label(layout3, label3, 2, 0);
    layout_layout(layout2, layout3, 2, 1);
    layout_layout(layout1, layout2, 0, 0);
    layout_imageview(layout1, view, 0, 1);
    layout_halign(layout3, 2, 0, ekJUSTIFY);
    layout_hmargin(layout2, 0, 5);
    layout_hmargin(layout2, 1, 5);
    layout_hmargin(layout3, 1, 15);
    layout_hexpand(layout2, 2);
    layout_hexpand(layout3, 2);
    layout_margin2(layout2, 0, 5);
    panel_layout(panel, layout1);
    app->fct = i_FCT;
    app->format = ekRGBA32;
    app->threads = 1;
    app->vertical = TRUE;
    app->view = view;
    app->time_label = label3;
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
    app->window = window_create(ekWNSTD, &panel);
    app->clock = clock_create(0);
    i_image(app);
    window_title(app->window, "Fractals");
    window_origin(app->window, v2df(500, 200));
    window_OnClose(app->window, listener(app, i_OnClose, App));
    window_show(app->window);
    return app;
}

/*---------------------------------------------------------------------------*/

static void i_destroy(App **app)
{
    window_destroy(&(*app)->window);
    clock_destroy(&(*app)->clock);
    heap_delete(app, App);
}

/*---------------------------------------------------------------------------*/

#include "osmain.h"
osmain(i_create, i_destroy, "", App)
