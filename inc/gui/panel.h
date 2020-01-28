/*
 * NAppGUI-v1.1.1.2372 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: panel.h
 * https://nappgui.com/en/gui/panel.html
 *
 */

/* Panel */

#include "gui.hxx"

__EXTERN_C

Panel *panel_create(void);

uint32_t panel_layout(Panel *panel, Layout *layout);

Layout *panel_get_layout(Panel *panel, const uint32_t index);

void panel_visible_layout(Panel *panel, const uint32_t index);

void panel_update(Panel *panel);

void panel_data_imp(Panel *panel, void **data, FPtr_destroy func_destroy_item);

void *panel_get_data_imp(const Panel *panel);

__END_C

#define panel_data(panel, data, func_destroy_data, type)\
    (\
        (void)((type**)data == data),\
        FUNC_CHECK_DESTROY(func_destroy_data, type),\
        panel_data_imp(panel, (void**)data, (FPtr_destroy)func_destroy_data)\
    )

#define panel_get_data(panel, type)\
    (type*)panel_get_data_imp(panel)


