/*
 * NAppGUI-v1.1.1.2372 Cross-platform C SDK
 * © 2015-2020 Francisco Garcia Collado
 * All rights reserved
 * https://nappgui.com/en/legal/eula.html
 *
 * File: core.hxx
 * https://nappgui.com/en/core/core.html
 *
 */

/* Core library */

#ifndef __CORE_HXX__
#define __CORE_HXX__

#include "osbs.hxx"

typedef enum _core_event_t
{
    ekEASSERT = 0x100,
    ekEFILE,
    ekEENTRY,
    ekEEXIT
} core_event_t;

typedef enum _sstate_t
{
    ekSTOK,
    ekSTEND,
    ekSTCORRUPT,
    ekSTBROKEN
} sstate_t;

typedef enum _lextoken_t
{
    ekTSLCOM = 1,
    ekTMLCOM,
    ekTSPACE,
    ekTEOL,

    ekTLESS,        /* < */
    ekTGREAT,       /* > */
    ekTCOMMA,       /* , */				
    ekTPERIOD,      /* . */
    ekTSCOLON,      /* ; */
    ekTCOLON,       /* : */

    ekTOPENPAR,     /* ( */
    ekTCLOSPAR,     /* ) */
    ekTOPENBRAC,    /* [ */
    ekTCLOSBRAC,    /* ] */
    ekTOPENCURL,    /* { */
    ekTCLOSCURL,    /* } */
    
    ekTPLUS,        /* + */
    ekTMINUS,       /* - */
    ekTASTERK,      /* * */
    ekTEQUALS,      /* = */

    ekTDOLLAR,      /* $ */
    ekTPERCENT,     /* % */
    ekTPOUND,       /* # */
    ekTAMPER,       /* & */

    ekTAPOST,       /* ' */
    ekTQUOTE,       /* " */
    ekTCIRCUM,      /* ^ */
    ekTTILDE,       /* ~ */
    ekTEXCLA,       /* ! */
    ekTQUEST,       /* ? */
    ekTVLINE,       /* | */
    ekTSLASH,       /* / */
    ekTBSLASH,      /* \ */
    ekTAT,          /* @ */

    ekTINTEGER,
    ekTOCTAL,
    ekTHEX,
    ekTREAL,
    ekTSTRING,
    ekTIDENT,

    ekTUNDEF,
    ekTCORRUP,
    ekTEOF,

    ekTRESERVED

} lextoken_t;

typedef struct _array_t Array;
typedef struct _buffer_t Buffer;
typedef struct _clock_t Clock;
typedef struct _event_t Event;
typedef struct _lexscn_t LexScn;
typedef struct _listener_t Listener;
typedef struct _rbtree_t RBTree;
typedef const char_t* ResId;
typedef struct _respack ResPack;
typedef struct _stream_t Stream;
typedef struct _string_t String;
typedef struct _direntry_t DirEntry;
typedef struct _evfiledir_t EvFileDir;

#define HEAPARR         "::arr"
#define ARRST           "ArrSt::"
#define ARRPT           "ArrPt::"
#define ArrPt(type)     struct Arr##Pt##type
#define ArrSt(type)     struct Arr##St##type
#define SetPt(type)     struct Set##Pt##type
#define SetSt(type)     struct Set##St##type
#define DictPt(type)    struct Dict##Pt##type
#define DictSt(type)    struct Dict##St##type
#define HashPt(type)    struct Hash##Pt##type
#define HashSt(type)    struct Hash##St##type
#define TreePt(type)    struct Tree##Pt##type
#define NodePt(type)    struct Node##Pt##type
#define TreeSt(type)    struct Tree##St##type
#define NodeSt(type)    struct Node##St##type

ArrSt(bool_t);
ArrSt(int8_t);
ArrSt(int16_t);
ArrSt(int32_t);
ArrSt(int64_t);
ArrSt(uint8_t);
ArrSt(uint16_t);
ArrSt(uint32_t);
ArrSt(uint64_t);
ArrSt(real32_t);
ArrSt(real64_t);
SetSt(bool_t);
SetSt(int8_t);
SetSt(int16_t);
SetSt(int32_t);
SetSt(int64_t);
SetSt(uint8_t);
SetSt(uint16_t);
SetSt(uint32_t);
SetSt(uint64_t);
SetSt(real32_t);
SetSt(real64_t);
ArrPt(String);
ArrPt(ResPack);

typedef void(*FPtr_remove)(void *obj);
#define FUNC_CHECK_REMOVE(func, type)\
    (void)((void(*)(type*))func == func)

typedef void(*FPtr_event_handler)(void *obj, Event *event);
#define FUNC_CHECK_EVENT_HANDLER(func, type)\
    (void)((void(*)(type*, Event*))func == func)

typedef void*(*FPtr_read)(Stream *stream);
#define FUNC_CHECK_READ(func, type)\
    (void)((type*(*)(Stream*))func == func)

typedef void(*FPtr_read_init)(Stream *stream, void *obj);
#define FUNC_CHECK_READ_INIT(func, type)\
    (void)((void(*)(Stream*, type*))func == func)

typedef void(*FPtr_write)(Stream *stream, const void *obj);
#define FUNC_CHECK_WRITE(func, type)\
    (void)((void(*)(Stream*, const type*))func == func)

struct _direntry_t
{
    String *name;
    file_type_t type;
    uint64_t size;
    Date date;
};

struct _evfiledir_t
{
    const char_t *pathname;
    uint32_t depth;
};

#ifdef  __cplusplus

struct IListener
{
protected:
    Listener *listen(IListener *obj, void(IListener::*handler)(Event*));
};

typedef void(IListener::*EventHandler)(Event*);

#endif

#endif
