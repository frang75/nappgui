/*
 * NAppGUI-v1.1.1.2374 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: warn.hxx
 * https://nappgui.com/en/sewer/warn.html
 *
 */

/* This header will ignore ALL warnings of code file (.c .cpp .m etc) */
/* USE ONLY IN THIRD PARTY FILES, NOT IN OWN FILES */

#if defined (_MSC_VER)
#pragma warning(pop) 
/* Unreferenced inline function has been removed */
#pragma warning( disable : 4514 )
#pragma warning( default : 4625 )
#pragma warning( default : 4626 )
#endif

#if defined (__GNUC__)

#if defined(__APPLE__)
#if (__GNUC__ == 4) && (__GNUC_MINOR__ > 2)
#pragma GCC diagnostic pop
#endif
#endif

#pragma GCC diagnostic ignored "-Wcomment"
#endif

#if defined (__clang__)
#pragma GCC diagnostic pop
#endif

