/* 2D collision detection demo */

#include "nappgui.h"
#include "col2dgui.h"

/*---------------------------------------------------------------------------*/

static void i_OnClose(App *app, Event *e)
{
    osapp_finish();
    unref(app);
    unref(e);
}

/*---------------------------------------------------------------------------*/

static Pol2Df *i_convex_pol(void)
{
    const V2Df pt[] = { {4,1}, {2,5}, {-3,5}, {-4,2}, {0,-3} };
    Pol2Df *pol = pol2d_createf(pt, sizeof(pt) / sizeof(V2Df));
    cassert(pol2d_convexf(pol) == TRUE);
    return pol;
}

/*---------------------------------------------------------------------------*/

static Pol2Df *i_simple_pol(void)
{
    const V2Df pt[] = { {9.78f, 12.17f}, {-10.00f, 11.01f}, {-9.68f, 3.20f}, {-9.30f, -5.98f}, {-4.27f, -5.84f}, {-4.03f, -12.17f}, {2.72f, -12.12f}, {2.47f, -6.36f}, {2.04f, 3.26f}, {-1.45f, 3.05f}, {-1.08f, -2.08f}, {-3.98f, -2.38f}, {-4.23f, 2.88f}, {-1.45f, 3.05f}, {2.04f, 3.26f}, {10.00f, 3.75f} };
    Pol2Df *pol = pol2d_createf(pt, sizeof(pt) / sizeof(V2Df));
    cassert(pol2d_convexf(pol) == FALSE);
    return pol;
}

/*---------------------------------------------------------------------------*/

static ArrSt(Shape) *i_shapes(void) 
{
    ArrSt(Shape) *shapes = arrst_create(Shape);
    Shape *shape = arrst_new_n(shapes, 10, Shape);
    shape[0].type = ekCIRCLE;
    shape[0].mouse = FALSE;
    shape[0].collisions = 0;
    shape[0].body.cir.r = 50;
    shape[0].body.cir.c.x = 100;
    shape[0].body.cir.c.y = 100;
    shape[1].type = ekCIRCLE;
    shape[1].mouse = FALSE;
    shape[1].collisions = 0;
    shape[1].body.cir.r = 20;
    shape[1].body.cir.c.x = 300;
    shape[1].body.cir.c.y = 200;
    shape[2].type = ekOBB;
    shape[2].mouse = FALSE;
    shape[2].collisions = 0;
    shape[2].body.obb.center.x = 150;
    shape[2].body.obb.center.y = 350;
    shape[2].body.obb.angle = 200 * kBMATH_DEG2RADf;
    shape[2].body.obb.width = 200;
    shape[2].body.obb.height = 20;
    shape[2].body.obb.obb = NULL;
    shape[3].type = ekOBB;
    shape[3].mouse = FALSE;
    shape[3].collisions = 0;
    shape[3].body.obb.center.x = 460;
    shape[3].body.obb.center.y = 90;
    shape[3].body.obb.angle = 15 * kBMATH_DEG2RADf;
    shape[3].body.obb.width = 200;
    shape[3].body.obb.height = 60;
    shape[3].body.obb.obb = NULL;
    shape[4].type = ekPOINT;
    shape[4].mouse = FALSE;
    shape[4].collisions = 0;
    shape[4].body.pnt.x = 520;
    shape[4].body.pnt.y = 230;
    shape[5].type = ekPOINT;
    shape[5].mouse = FALSE;
    shape[5].collisions = 0;
    shape[5].body.pnt.x = 220;
    shape[5].body.pnt.y = 205;
    shape[6].type = ekBOX;
    shape[6].mouse = FALSE;
    shape[6].collisions = 0;
    shape[6].body.box.center.x = 100;
    shape[6].body.box.center.y = 225;
    shape[6].body.box.width = 100;
    shape[6].body.box.height = 50;
    shape[7].type = ekSEGMENT;
    shape[7].mouse = FALSE;
    shape[7].collisions = 0;
    shape[7].body.seg.center.x = 420;
    shape[7].body.seg.center.y = 280;
    shape[7].body.seg.length = 190;
    shape[7].body.seg.angle = 2.2f;
    shape[8].type = ekCONVEX_POLY;
    shape[8].mouse = FALSE;
    shape[8].collisions = 0;
    shape[8].body.pol.center.x = 535;
    shape[8].body.pol.center.y = 325;
    shape[8].body.pol.angle = .55f;
    shape[8].body.pol.scale = 15;
    shape[8].body.pol.t2d = *kT2D_IDENTf;
    shape[8].body.pol.pol = i_convex_pol();
    shape[9].type = ekSIMPLE_POLY;
    shape[9].mouse = FALSE;
    shape[9].collisions = 0;
    shape[9].body.pol.center.x = 370;
    shape[9].body.pol.center.y = 450;
    shape[9].body.pol.angle = .78f;
    shape[9].body.pol.scale = 7;
    shape[9].body.pol.t2d = *kT2D_IDENTf;
    shape[9].body.pol.pol = i_simple_pol();
    col2dhello_update_obb(&shape[2].body.obb);
    col2dhello_update_obb(&shape[3].body.obb);
    col2dhello_update_box(&shape[6].body.box);
    col2dhello_update_seg(&shape[7].body.seg);
    col2dhello_update_pol(&shape[8].body.pol);
    col2dhello_update_pol(&shape[9].body.pol);
    return shapes;
}

/*---------------------------------------------------------------------------*/

static App *i_create(void)
{
    App *app = heap_new0(App);
    col2dhello_dbind();
    app->shapes = i_shapes();
    app->dists = arrst_create(Dist);
    app->seltype = ekOBB;
    app->selshape = UINT32_MAX;
    app->show_seg_pt = TRUE;
    app->window = col2dhello_window(app);
    window_title(app->window, "2D Collision Detection");
    window_origin(app->window, v2df(500, 200));
    window_OnClose(app->window, listener(app, i_OnClose, App));
    window_show(app->window);
    col2dhello_dbind_shape(app);
    col2dhello_collisions(app);
    return app;
}

/*---------------------------------------------------------------------------*/

static void i_remove_shape(Shape *shape)
{
    cassert_no_null(shape);
    if (shape->type == ekOBB)
        obb2d_destroyf(&shape->body.obb.obb);
    else if (shape->type == ekCONVEX_POLY || shape->type == ekSIMPLE_POLY)
        pol2d_destroyf(&shape->body.pol.pol);
}

/*---------------------------------------------------------------------------*/

static void i_destroy(App **app)
{
    arrst_destroy(&(*app)->shapes, i_remove_shape, Shape);
    arrst_destroy(&(*app)->dists, NULL, Dist);
    window_destroy(&(*app)->window);
    heap_delete(app, App);
}

/*---------------------------------------------------------------------------*/

void col2dhello_new_shape(App *app, const V2Df pos)
{
    Shape *shape = arrst_new(app->shapes, Shape);
    shape->type = app->seltype;
    shape->collisions = 0;
    shape->mouse = FALSE;
    app->selshape = arrst_size(app->shapes, Shape) - 1;

    switch(app->seltype) {
    case ekPOINT:
        shape->body.pnt = pos;
        break;

    case ekSEGMENT:
        shape->body.seg.center = pos;
        shape->body.seg.length = 100;
        shape->body.seg.angle = 15 * kBMATH_DEG2RADf;
        col2dhello_update_seg(&shape->body.seg);
        break;

    case ekCIRCLE:
        shape->body.cir.c = pos;
        shape->body.cir.r = 30;
        break;

    case ekBOX:
        shape->body.box.center = pos;
        shape->body.box.width = 100;
        shape->body.box.height = 50;
        col2dhello_update_box(&shape->body.box);
        break;

    case ekOBB:
        shape->body.obb.center = pos;
        shape->body.obb.width = 100;
        shape->body.obb.height = 50;
        shape->body.obb.angle = 15 * kBMATH_DEG2RADf;
        shape->body.obb.obb = NULL;
        col2dhello_update_obb(&shape->body.obb);
        break;

    case ekCONVEX_POLY:
        shape->body.pol.center = pos;
        shape->body.pol.angle = 0;
        shape->body.pol.scale = 10;
        shape->body.pol.t2d = *kT2D_IDENTf;
        shape->body.pol.pol = i_convex_pol();
        col2dhello_update_pol(&shape->body.pol);
        break;

    case ekSIMPLE_POLY:
        shape->body.pol.center = pos;
        shape->body.pol.angle = 0;
        shape->body.pol.scale = 10;
        shape->body.pol.t2d = *kT2D_IDENTf;
        shape->body.pol.pol = i_simple_pol();
        col2dhello_update_pol(&shape->body.pol);
        break;

    cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void col2dhello_update_seg(Seg *seg)
{
    V2Df hvec;
    cassert_no_null(seg);
    hvec.x = seg->length / 2;
    hvec.y = 0;
    v2d_rotatef(&hvec, seg->angle);
    seg->seg.p0.x = seg->center.x - hvec.x;
    seg->seg.p0.y = seg->center.y - hvec.y;
    seg->seg.p1.x = seg->center.x + hvec.x;
    seg->seg.p1.y = seg->center.y + hvec.y;
}

/*---------------------------------------------------------------------------*/

void col2dhello_update_box(Box *box)
{
    cassert_no_null(box);
    box->box.min.x = box->center.x - box->width / 2;
    box->box.min.y = box->center.y - box->height / 2;
    box->box.max.x = box->center.x + box->width / 2;
    box->box.max.y = box->center.y + box->height / 2;
}

/*---------------------------------------------------------------------------*/

void col2dhello_update_obb(OBB *obb)
{
    cassert_no_null(obb);
    if (obb->obb == NULL)
        obb->obb = obb2d_createf(&obb->center, obb->width, obb->height, obb->angle);
    else
        obb2d_updatef(obb->obb, &obb->center, obb->width, obb->height, obb->angle);
}

/*---------------------------------------------------------------------------*/

void col2dhello_update_pol(Pol *pol)
{
    T2Df t2d, nt2d;
    cassert_no_null(pol);
    cassert_no_null(pol->pol);
    t2d_inversef(&t2d, &pol->t2d);
    t2d_movef(&nt2d, kT2D_IDENTf, pol->center.x, pol->center.y);
    t2d_rotatef(&nt2d, &nt2d, pol->angle);
    t2d_scalef(&nt2d, &nt2d, pol->scale, pol->scale);
    t2d_multf(&t2d, &nt2d, &t2d);
    pol2d_transformf(pol->pol, &t2d);
    pol->t2d = nt2d;
}

/*---------------------------------------------------------------------------*/

static bool_t i_mouse_inside(const Shape *shape, const real32_t mouse_x, const real32_t mouse_y)
{
    V2Df m = v2df(mouse_x, mouse_y);

    switch(shape->type) {
    case ekPOINT:
        return col2d_point_pointf(&shape->body.pnt, &m, CENTER_RADIUS, NULL);

    case ekSEGMENT:
        return col2d_segment_pointf(&shape->body.seg.seg, &m, CENTER_RADIUS, NULL);

    case ekCIRCLE:
        return col2d_circle_pointf(&shape->body.cir, &m, NULL);

    case ekBOX:
        return col2d_box_pointf(&shape->body.box.box, &m, NULL);

    case ekOBB:
        return col2d_obb_pointf(shape->body.obb.obb, &m, NULL);

    case ekCONVEX_POLY:
    case ekSIMPLE_POLY:
        return col2d_poly_pointf(shape->body.pol.pol, &m, NULL);

    cassert_default();
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

void col2dhello_mouse_collisions(App *app, const real32_t mouse_x, const real32_t mouse_y)
{
    arrst_foreach(shape, app->shapes, Shape)
        shape->mouse = i_mouse_inside(shape, mouse_x, mouse_y);
    arrst_end();
}

/*---------------------------------------------------------------------------*/

static void i_point_segment_dist(const Seg2Df *seg, const V2Df *pnt, ArrSt(Dist) *dists)
{
    Dist *dist = arrst_new(dists, Dist);
    real32_t t = seg2d_close_paramf(seg, pnt);
    dist->p0 = *pnt;
    dist->p1 = seg2d_evalf(seg, t);
}

/*---------------------------------------------------------------------------*/

void col2dhello_collisions(App *app)
{
    Shape *shape = arrst_all(app->shapes, Shape);
    uint32_t n = arrst_size(app->shapes, Shape);
    uint32_t i, j;

    arrst_clear(app->dists, NULL, Dist);

    for (i = 0; i < n; ++i)
        shape[i].collisions = 0;

    for (i = 0; i < n; ++i)
    for (j = i + 1; j < n; ++j)
    {
        bool_t col = FALSE;
        switch(shape[i].type) {
        case ekPOINT:
            switch(shape[j].type) {
            case ekPOINT:
                col = col2d_point_pointf(&shape[i].body.pnt, &shape[j].body.pnt, CENTER_RADIUS, NULL);
                break;

            case ekSEGMENT:
                col = col2d_segment_pointf(&shape[j].body.seg.seg, &shape[i].body.pnt, CENTER_RADIUS, NULL);
                i_point_segment_dist(&shape[j].body.seg.seg, &shape[i].body.pnt, app->dists);
                break;

            case ekCIRCLE:
                col = col2d_circle_pointf(&shape[j].body.cir, &shape[i].body.pnt, NULL);
                break;

            case ekBOX:
                col = col2d_box_pointf(&shape[j].body.box.box, &shape[i].body.pnt, NULL);
                break;

            case ekOBB:
                col = col2d_obb_pointf(shape[j].body.obb.obb, &shape[i].body.pnt, NULL);
                break;

            case ekCONVEX_POLY:
            case ekSIMPLE_POLY:
                col = col2d_poly_pointf(shape[j].body.pol.pol, &shape[i].body.pnt, NULL);
                break;

            cassert_default();
            }
            break;

        case ekSEGMENT:
            switch(shape[j].type) {
            case ekPOINT:
                col = col2d_segment_pointf(&shape[i].body.seg.seg, &shape[j].body.pnt, CENTER_RADIUS, NULL);
                i_point_segment_dist(&shape[i].body.seg.seg, &shape[j].body.pnt, app->dists);
                break;

            case ekSEGMENT:
                col = col2d_segment_segmentf(&shape[i].body.seg.seg, &shape[j].body.seg.seg, NULL);
                break;

            case ekCIRCLE:
                col = col2d_circle_segmentf(&shape[j].body.cir, &shape[i].body.seg.seg, NULL);
                break;

            case ekBOX:
                col = col2d_box_segmentf(&shape[j].body.box.box, &shape[i].body.seg.seg, NULL);
                break;

            case ekOBB:
                col = col2d_obb_segmentf(shape[j].body.obb.obb, &shape[i].body.seg.seg, NULL);
                break;

            case ekCONVEX_POLY:
            case ekSIMPLE_POLY:
                col = col2d_poly_segmentf(shape[j].body.pol.pol, &shape[i].body.seg.seg, NULL);
                break;

            cassert_default();
            }
            break;

        case ekCIRCLE:
            switch(shape[j].type) {
            case ekPOINT:
                col = col2d_circle_pointf(&shape[i].body.cir, &shape[j].body.pnt, NULL);
                break;

            case ekSEGMENT:
                col = col2d_circle_segmentf(&shape[i].body.cir, &shape[j].body.seg.seg, NULL);
                break;

            case ekCIRCLE:
                col = col2d_circle_circlef(&shape[i].body.cir, &shape[j].body.cir, NULL);
                break;

            case ekBOX:
                col = col2d_box_circlef(&shape[j].body.box.box, &shape[i].body.cir, NULL);
                break;

            case ekOBB:
                col = col2d_obb_circlef(shape[j].body.obb.obb, &shape[i].body.cir, NULL);
                break;

            case ekCONVEX_POLY:
            case ekSIMPLE_POLY:
                col = col2d_poly_circlef(shape[j].body.pol.pol, &shape[i].body.cir, NULL);
                break;

            cassert_default();
            }
            break;

        case ekBOX:
            switch(shape[j].type) {
            case ekPOINT:
                col = col2d_box_pointf(&shape[i].body.box.box, &shape[j].body.pnt, NULL);
                break;

            case ekSEGMENT:
                col = col2d_box_segmentf(&shape[i].body.box.box, &shape[j].body.seg.seg, NULL);
                break;

            case ekCIRCLE:
                col = col2d_box_circlef(&shape[i].body.box.box, &shape[j].body.cir, NULL);
                break;

            case ekBOX:
                col = col2d_box_boxf(&shape[i].body.box.box, &shape[j].body.box.box, NULL);
                break;

            case ekOBB:
                col = col2d_obb_boxf(shape[j].body.obb.obb, &shape[i].body.box.box, NULL);
                break;

            case ekCONVEX_POLY:
            case ekSIMPLE_POLY:
                col = col2d_poly_boxf(shape[j].body.pol.pol, &shape[i].body.box.box, NULL);
                break;

            cassert_default();
            }
            break;

        case ekOBB:
            switch(shape[j].type) {
            case ekPOINT:
                col = col2d_obb_pointf(shape[i].body.obb.obb, &shape[j].body.pnt, NULL);
                break;

            case ekSEGMENT:
                col = col2d_obb_segmentf(shape[i].body.obb.obb, &shape[j].body.seg.seg, NULL);
                break;

            case ekCIRCLE:
                col = col2d_obb_circlef(shape[i].body.obb.obb, &shape[j].body.cir, NULL);
                break;

            case ekBOX:
                col = col2d_obb_boxf(shape[i].body.obb.obb, &shape[j].body.box.box, NULL);
                break;

            case ekOBB:
                col = col2d_obb_obbf(shape[i].body.obb.obb, shape[j].body.obb.obb, NULL);
                break;

            case ekCONVEX_POLY:
            case ekSIMPLE_POLY:
                col = col2d_poly_obbf(shape[j].body.pol.pol, shape[i].body.obb.obb, NULL);
                break;

            cassert_default();
            }
            break;

        case ekCONVEX_POLY:
        case ekSIMPLE_POLY:
            switch(shape[j].type) {
            case ekPOINT:
                col = col2d_poly_pointf(shape[i].body.pol.pol, &shape[j].body.pnt, NULL);
                break;

            case ekSEGMENT:
                col = col2d_poly_segmentf(shape[i].body.pol.pol, &shape[j].body.seg.seg, NULL);
                break;

            case ekCIRCLE:
                col = col2d_poly_circlef(shape[i].body.pol.pol, &shape[j].body.cir, NULL);
                break;

            case ekBOX:
                col = col2d_poly_boxf(shape[i].body.pol.pol, &shape[j].body.box.box, NULL);
                break;

            case ekOBB:
                col = col2d_poly_obbf(shape[i].body.pol.pol, shape[j].body.obb.obb, NULL);
                break;

            case ekCONVEX_POLY:
            case ekSIMPLE_POLY:
                col = col2d_poly_polyf(shape[i].body.pol.pol, shape[j].body.pol.pol, NULL);
                break;

            cassert_default();
            }
            break;

        cassert_default();
        }

        if (col == TRUE)
        {
            shape[i].collisions += 1;
            shape[j].collisions += 1;
        }
    }
}

/*---------------------------------------------------------------------------*/

#include "osmain.h"
osmain(i_create, i_destroy, "", App)
