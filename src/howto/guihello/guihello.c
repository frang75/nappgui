/* NAppGUI GUI Basics */
    
#include "nappgui.h"
#include "res.h"
#include "labels.h"
#include "buttons.h"
#include "sliders.h"
#include "form.h"
#include "popcom.h"
#include "baslayout.h"
#include "sublayout.h"
#include "subpanel.h"
#include "multilayout.h"

typedef struct _app_t App;

struct _app_t
{
    Window *window;
    Layout *layout;
};

/*---------------------------------------------------------------------------*/

static void i_set_panel(Layout *layout, const uint32_t index)
{
    Panel *panel = NULL;
    switch (index) {
    case 0:
        panel = labels_single_line();
        break;
    case 1:
        panel = labels_multi_line();
        break;
    case 2:
        panel = labels_mouse_over();
        break;
    case 3:
        panel = buttons_basics();
        break;
    case 4:
        panel = popup_combo();
        break;
    case 5:
        panel = form_basic();
        break;
    case 6:
        panel = sliders();
        break;
    case 7:
        panel = basic_layout();
        break;
    case 8:
        panel = sublayouts();
        break;
    case 9:
        panel = subpanels();
        break;
    case 10:
        panel = multilayouts();
        break;
    }

    layout_panel(layout, panel, 1, 0);
}

/*---------------------------------------------------------------------------*/

static void i_OnSelect(App *app, Event *e)
{
    const EvButton *p = event_params(e, EvButton);
    i_set_panel(app->layout, p->index);
    window_update(app->window);
}

/*---------------------------------------------------------------------------*/

static Panel *i_panel(App *app)
{
    Panel *panel = panel_create();
    Layout *layout = layout_create(2, 1);
    PopUp *popup = popup_create();
    popup_add_elem(popup, "Labels single line", NULL);
    popup_add_elem(popup, "Labels multi line", NULL);
    popup_add_elem(popup, "Labels mouse sensitive", NULL);
    popup_add_elem(popup, "Buttons", NULL);
    popup_add_elem(popup, "PopUp Combo", NULL);
    popup_add_elem(popup, "Form", NULL);
    popup_add_elem(popup, "Sliders", NULL);
    popup_add_elem(popup, "Basic Layout", NULL);
    popup_add_elem(popup, "SubLayouts", NULL);
    popup_add_elem(popup, "Subpanels", NULL);
    popup_add_elem(popup, "Multi-Layouts", NULL);
    popup_selected(popup, 0);
    popup_OnSelect(popup, listener(app, i_OnSelect, App));
    layout_popup(layout, popup, 0, 0);
    i_set_panel(layout, 0);
    panel_layout(panel, layout);
    layout_valign(layout, 0, 0, ekTOP);
    layout_margin(layout, 10);
    layout_hmargin(layout, 0, 10);
    app->layout = layout;
    return panel;
}

/*---------------------------------------------------------------------------*/

static Window *i_window(App *app)
{
    Panel *panel = i_panel(app);
    Window *window = window_create(ekWNSTD, &panel);
    window_title(window, "NAppGUI GUI Basics");
    return window;
}

/*---------------------------------------------------------------------------*/

static void i_OnClose(App *app, Event *e)
{
    unref(app);
    unref(e);
    osapp_finish();
}

/*---------------------------------------------------------------------------*/

static App *i_create(void)
{
    App *app = heap_new(App);
    gui_respack(res_respack);
    gui_language("");
    app->window = i_window(app);
    window_origin(app->window, v2df(500.f, 200.f));
    window_OnClose(app->window, listener(app, i_OnClose, App));
    window_show(app->window);
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
