/*
 * NAppGUI-v1.1.1.2374 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: arch.hxx
 * https://nappgui.com/en/sewer/arch.html
 *
 */

/* Architectures */

#ifndef __BASEARCH_HXX__
#define __BASEARCH_HXX__

#if defined (_WINDOWS)

    #if defined (_MSC_VER) && _MSC_VER <= 1500
    #define __STDC_LIMIT_MACROS
    #endif

    #define __WINDOWS__
    #define __DESKTOP__
    #if defined (_M_AMD64)
        #define __x64__
    #elif defined (_M_IX86)
        #define __x86__
    #else
        #error Unknown processor
    #endif
    #define on_platform(w, a, l)    (w)

#elif defined (__APPLE__)
    #include <TargetConditionals.h>
    
    #if TARGET_OS_MAC == 1
        #define __UNIX__
        #if TARGET_OS_IPHONE == 1
            #define __IOS__
            #define __EMBEDDED__
            #define __ARM__
        #else
            #define __MACOS__
            #define __DESKTOP__

            #if defined (__i386__)
                #define __x86__
            #elif defined (__x86_64__)
                #define __x64__
            #else
                #error Unknown processor
            #endif

        #endif
    #else
        #error APPLE Machine not supported
    #endif

    #define on_platform(w, a, l)    (a)

#elif defined(__linux__)
	#define __UNIX__
    #define __LINUX__
    #define __DESKTOP__

	#if defined(__GTK3_TOOLKIT__)
    #define __GTK3__
	#endif

    #if defined (__i386__)
        #define __x86__
    #elif defined (__x86_64__)
        #define __x64__
    #elif defined (__arm__)
        #define __ARM__
    #else
        #error Unknown processor
    #endif

    #define on_platform(w, a, l)    (l)

#else
    #error Unknown configuration
#endif

#endif