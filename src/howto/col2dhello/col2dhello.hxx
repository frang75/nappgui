/* 2D collision detection demo */

#ifndef __COL2DHELLO_HXX__
#define __COL2DHELLO_HXX__

#include "gui.hxx"

#define CENTER_RADIUS   3

typedef struct _shape_t Shape;
typedef struct _dist_t Dist;
typedef struct _box_t Box;
typedef struct _seg_t Seg;
typedef struct _obb_t OBB;
typedef struct _pol_t Pol;
typedef struct _app_t App;

typedef enum _shtype_t
{
    ekPOINT,
    ekSEGMENT,
    ekCIRCLE,
    ekBOX,
    ekOBB,
    ekPOLY
} shtype_t;

struct _seg_t
{
    V2Df center;
    real32_t length;
    real32_t angle;
    Seg2Df seg;
};

struct _box_t
{
    V2Df center;
    real32_t width;
    real32_t height;
    Box2Df box;
};

struct _obb_t
{
    V2Df center;
    real32_t width;
    real32_t height;
    real32_t angle;
    OBB2Df *obb;
};

struct _pol_t
{
    V2Df center;
    real32_t angle;
    real32_t scale;
    Pol2Df *pol;
};

struct _shape_t
{
    shtype_t type;
    bool_t mouse;
    uint32_t collisions;

    union {
        V2Df pnt;
        Seg seg;
        Cir2Df cir;
        Box box;
        OBB obb;
        Pol pol;
    } body;
};

struct _dist_t
{
    V2Df p0;
    V2Df p1;
};

struct _app_t
{
    Window *window;
    View *view;
    Layout *pnt_layout;
    Layout *seg_layout;
    Layout *cir_layout;
    Layout *box_layout;
    Layout *obb_layout;
    Layout *pol_layout;
    Panel *obj_panel;
    ArrSt(Shape) *shapes;
    ArrSt(Dist) *dists;
    shtype_t seltype;
    uint32_t selshape;
    bool_t show_seg_pt;
    V2Df mouse_pos;
    V2Df obj_pos;
};

#endif
