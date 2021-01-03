/*
 * NAppGUI Cross-platform C SDK
 * © 2015-2021 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: osbs.h
 * https://nappgui.com/en/osbs/osbs.html
 *
 */

/* Operating System Basic Services */

#include "osbs.hxx"

__EXTERN_C

void osbs_start(void);

void osbs_finish(void);

platform_t osbs_platform(void);

win_t osbs_windows(void);

endian_t osbs_endian(void);

__END_C

