/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2021 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: progress.h
 * https://nappgui.com/en/gui/progress.html
 *
 */

/* Progress bars */

#include "gui.hxx"

__EXTERN_C

Progress *progress_create(void);

void progress_undefined(Progress *progress, const bool_t running);

void progress_value(Progress *progress, const real32_t value);

__END_C

