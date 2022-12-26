/*
 * NAppGUI Cross-platform C SDK
 * 2015-2022 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: dlib.h
 *
 */

/* Dynamic library loading */

#include "osbs.hxx"

__EXTERN_C

_osbs_api DLib *dlib_open(const char_t *path, const char_t *libname);

_osbs_api void dlib_close(DLib **dlib);

_osbs_api FPtr_libproc dlib_proc_imp(DLib *dlib, const char_t *procname);

_osbs_api void* dlib_var_imp(DLib *dlib, const char_t *varname);

__END_C

#define dlib_proc(dlib, procname, type)\
    (type)dlib_proc_imp(dlib, procname)

#define dlib_var(dlib, varname, type)\
    (const type*)dlib_var_imp(dlib, varname)
