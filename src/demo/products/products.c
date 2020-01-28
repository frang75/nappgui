/* NAppGUI Products Demo */

#include "nappgui.h"
#include "prmodel.h"
#include "prmenu.h"
#include "prctrl.h"
#include "prview.h"
#include "res_gui.h"

typedef struct _app_t App;
struct _app_t
{
    Model *model;
    Ctrl *ctrl;
    Window *window;
    Menu *menu;
};

color_t kHOLDER;
color_t kEDITBG;
color_t kSTATBG;
color_t kSTATSK;
color_t kTXTRED;

/*---------------------------------------------------------------------------*/

static void i_OnThemeChanged(App *app, Event *e)
{
    ctrl_theme_images(app->ctrl);
    unref(e);
}

/*---------------------------------------------------------------------------*/

static App *i_create(void)
{
    App *app = heap_new(App);
    kHOLDER = color_alt(color_bgr(0x4681Cf), color_bgr(0x1569E6));
    kEDITBG = color_alt(color_bgr(0xFFFFe4), color_bgr(0x101010));
    kSTATBG = color_alt(color_bgr(0xFFC165), color_bgr(0x523d1d));
    kSTATSK = color_alt(color_bgr(0xFF8034), color_bgr(0xFF8034));
    kTXTRED = color_alt(color_bgr(0xFF0000), color_bgr(0xEB665A));
    gui_respack(res_gui_respack);
    gui_language("");
    gui_OnThemeChanged(listener(app, i_OnThemeChanged, App));
    model_bind();
    app->model = model_create();
    app->ctrl = ctrl_create(app->model);
    app->menu = prmenu_create(app->ctrl);
    app->window = prview_create(app->ctrl);
    osapp_menubar(app->menu, app->window);
    ctrl_run(app->ctrl);
    window_origin(app->window, v2df(100.f, 100.f));
    window_show(app->window);
    return app;
}

/*---------------------------------------------------------------------------*/

static void i_destroy(App **app)
{
    cassert_no_null(app);
    cassert_no_null(*app);
    ctrl_destroy(&(*app)->ctrl);
    window_destroy(&(*app)->window);
    menu_destroy(&(*app)->menu);
    model_destroy(&(*app)->model);
    heap_delete(app, App);
}

/*---------------------------------------------------------------------------*/

#include "osmain.h"
osmain(i_create, i_destroy, "", App)
