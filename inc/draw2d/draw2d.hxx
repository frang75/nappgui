/*
 * NAppGUI-v1.1.1.2372 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: draw2d.hxx
 * https://nappgui.com/en/draw2d/draw2d.html
 *
 */

/* Operating system 2D drawing support */

#ifndef __DRAW2D_HXX__
#define __DRAW2D_HXX__

#include "geom2d.hxx"

typedef enum _pixformat_t
{
    ekGRAY8,
    ekRGB24,
    ekRGBA32
} pixformat_t;

typedef enum _codec_t
{
    ekJPG = 1,
    ekPNG,
    ekBMP,
    ekGIF
} codec_t;

typedef enum _fstyle_t
{
    ekFNORMAL       = 0,
    ekFBOLD         = 1,
    ekFITALIC       = 2,
    ekFSTRIKEOUT    = 4,
    ekFUNDERLINE    = 8,

    ekFPIXELS       = 0,
    ekFPOINTS       = 16
} fstyle_t;

typedef enum _linecap_t
{
    ekLCFLAT,
    ekLCSQUARE,
    ekLCROUND
} linecap_t;

typedef enum _linejoin_t
{
    ekLJMITER,
    ekLJROUND,
    ekLJBEVEL
} linejoin_t;

typedef enum _fillwrap_t
{
    ekFCLAMP,
    ekFTILE,
    ekFFLIP
} fillwrap_t;

typedef enum _drawop_t
{
    ekSTROKE = 1,
    ekFILL,
    ekSKFILL,
    ekFILLSK
} drawop_t;

typedef enum _align_t
{
    ekLEFT = 1,
    ekTOP = 1,
    ekCENTER = 2,
    ekRIGHT = 3,
    ekBOTTOM = 3,
    ekJUSTIFY = 4
} align_t;

typedef enum _ellipsis_t
{
    ekELLIPNONE = 1,
    ekELLIPBEGIN,
    ekELLIPMIDDLE,
    ekELLIPEND,
    ekELLIPMLINE
} ellipsis_t;

typedef uint32_t color_t;
typedef struct _dctx_t DCtx;
typedef struct _image_t Image;
typedef struct _font_t Font;
ArrPt(Image);

#endif
