/* Col2D Hello GUI */

#include "nappgui.h"
#include "col2dgui.h"

/*---------------------------------------------------------------------------*/

void col2dhello_dbind(void)
{
    dbind_enum(shtype_t, ekPOINT);
    dbind_enum(shtype_t, ekSEGMENT);
    dbind_enum(shtype_t, ekCIRCLE);
    dbind_enum(shtype_t, ekBOX);
    dbind_enum(shtype_t, ekOBB);
    dbind_enum(shtype_t, ekCONVEX_POLY);
    dbind_enum(shtype_t, ekSIMPLE_POLY);
    dbind(App, shtype_t, seltype);
    dbind(App, bool_t, show_seg_pt);
    dbind(Seg, real32_t, length);
    dbind(Seg, real32_t, angle);
    dbind(Cir2Df, real32_t, r);
    dbind(Box, real32_t, width);
    dbind(Box, real32_t, height);
    dbind(OBB, real32_t, width);
    dbind(OBB, real32_t, height);
    dbind(OBB, real32_t, angle);
    dbind(Pol, real32_t, angle);
    dbind(Pol, real32_t, scale);
    dbind_range(Seg, real32_t, length, 20, 300);
    dbind_range(Seg, real32_t, angle, 0, 360 * kBMATH_DEG2RADf);
    dbind_range(Cir2Df, real32_t, r, 5, 100);
    dbind_range(Box, real32_t, width, 20, 300);
    dbind_range(Box, real32_t, height, 20, 300);
    dbind_range(OBB, real32_t, width, 20, 300);
    dbind_range(OBB, real32_t, height, .2f, 300);
    dbind_range(OBB, real32_t, angle, 0, 360 * kBMATH_DEG2RADf);
    dbind_range(Pol, real32_t, angle, 0, 360 * kBMATH_DEG2RADf);
    dbind_range(Pol, real32_t, scale, 5, 30);
}

/*---------------------------------------------------------------------------*/

static void i_OnSeg(App *app, Event *e)
{
    Shape *shape = arrst_get(app->shapes, app->selshape, Shape);
    cassert(shape->type == ekSEGMENT);
    col2dhello_update_seg(&shape->body.seg);
    col2dhello_collisions(app);
    view_update(app->view);
    unref(e);
}

/*---------------------------------------------------------------------------*/

static void i_OnCircle(App *app, Event *e)
{
    col2dhello_collisions(app);
    view_update(app->view);
    unref(e);
}

/*---------------------------------------------------------------------------*/

static void i_OnBox(App *app, Event *e)
{
    Shape *shape = arrst_get(app->shapes, app->selshape, Shape);
    cassert(shape->type == ekBOX);
    col2dhello_update_box(&shape->body.box);
    col2dhello_collisions(app);
    view_update(app->view);
    unref(e);
}

/*---------------------------------------------------------------------------*/

static void i_OnOBB(App *app, Event *e)
{
    Shape *shape = arrst_get(app->shapes, app->selshape, Shape);
    cassert(shape->type == ekOBB);
    col2dhello_update_obb(&shape->body.obb);
    col2dhello_collisions(app);
    view_update(app->view);
    unref(e);
}

/*---------------------------------------------------------------------------*/

static void i_OnPoly(App *app, Event *e)
{
    Shape *shape = arrst_get(app->shapes, app->selshape, Shape);
    cassert(shape->type == ekCONVEX_POLY || shape->type == ekSIMPLE_POLY);
    col2dhello_update_pol(&shape->body.pol);
    col2dhello_collisions(app);
    view_update(app->view);
    unref(e);
}

/*---------------------------------------------------------------------------*/

static void i_OnOpt(App *app, Event *e)
{
    view_update(app->view);
    unref(e);
}

/*---------------------------------------------------------------------------*/

static Layout *i_empty_layout(void)
{
    Layout *layout = layout_create(1, 1);
    return layout;
}

/*---------------------------------------------------------------------------*/

static Layout *i_point_layout(App *app)
{
    Layout *layout = layout_create(1, 1);
    Label *label = label_create();
    label_text(label, "Selected Point");
    layout_label(layout, label, 0, 0);
    app->pnt_layout = layout;
    return layout;
}

/*---------------------------------------------------------------------------*/

static Layout *i_segment_layout(App *app)
{
    Layout *layout = layout_create(1, 5);
    Label *label1 = label_create();
    Label *label2 = label_create();
    Label *label3 = label_create();
    Slider *slider1 = slider_create();
    Slider *slider2 = slider_create();
    label_text(label1, "Selected Segment");
    label_text(label2, "Length:");
    label_text(label3, "Angle:");
    layout_label(layout, label1, 0, 0);
    layout_label(layout, label2, 0, 1);
    layout_label(layout, label3, 0, 3);
    layout_slider(layout, slider1, 0, 2);
    layout_slider(layout, slider2, 0, 4);
    layout_vmargin(layout, 0, 5);
    layout_vmargin(layout, 2, 10);
    cell_dbind(layout_cell(layout, 0, 2), Seg, real32_t, length);
    cell_dbind(layout_cell(layout, 0, 4), Seg, real32_t, angle);
    layout_dbind(layout, listener(app, i_OnSeg, App), Seg);
    app->seg_layout = layout;
    return layout;
}

/*---------------------------------------------------------------------------*/

static Layout *i_circle_layout(App *app)
{
    Layout *layout = layout_create(1, 3);
    Label *label1 = label_create();
    Label *label2 = label_create();
    Slider *slider = slider_create();
    label_text(label1, "Selected Circle");
    label_text(label2, "Radix:");
    layout_label(layout, label1, 0, 0);
    layout_label(layout, label2, 0, 1);
    layout_slider(layout, slider, 0, 2);
    layout_vmargin(layout, 0, 5);
    cell_dbind(layout_cell(layout, 0, 2), Cir2Df, real32_t, r);
    layout_dbind(layout, listener(app, i_OnCircle, App), Cir2Df);
    app->cir_layout = layout;
    return layout;
}

/*---------------------------------------------------------------------------*/

static Layout *i_box_layout(App *app)
{
    Layout *layout = layout_create(1, 5);
    Label *label1 = label_create();
    Label *label2 = label_create();
    Label *label3 = label_create();
    Slider *slider1 = slider_create();
    Slider *slider2 = slider_create();
    label_text(label1, "Selected Box");
    label_text(label2, "Width:");
    label_text(label3, "Height:");
    layout_label(layout, label1, 0, 0);
    layout_label(layout, label2, 0, 1);
    layout_label(layout, label3, 0, 3);
    layout_slider(layout, slider1, 0, 2);
    layout_slider(layout, slider2, 0, 4);
    layout_vmargin(layout, 0, 5);
    layout_vmargin(layout, 2, 10);
    cell_dbind(layout_cell(layout, 0, 2), Box, real32_t, width);
    cell_dbind(layout_cell(layout, 0, 4), Box, real32_t, height);
    layout_dbind(layout, listener(app, i_OnBox, App), Box);
    app->box_layout = layout;
    return layout;
}

/*---------------------------------------------------------------------------*/

static Layout *i_obb_layout(App *app)
{
    Layout *layout = layout_create(1, 7);
    Label *label1 = label_create();
    Label *label2 = label_create();
    Label *label3 = label_create();
    Label *label4 = label_create();
    Slider *slider1 = slider_create();
    Slider *slider2 = slider_create();
    Slider *slider3 = slider_create();
    label_text(label1, "Selected Oriented Box");
    label_text(label2, "Width:");
    label_text(label3, "Height:");
    label_text(label4, "Angle:");
    layout_label(layout, label1, 0, 0);
    layout_label(layout, label2, 0, 1);
    layout_label(layout, label3, 0, 3);
    layout_label(layout, label4, 0, 5);
    layout_slider(layout, slider1, 0, 2);
    layout_slider(layout, slider2, 0, 4);
    layout_slider(layout, slider3, 0, 6);
    layout_vmargin(layout, 0, 5);
    layout_vmargin(layout, 2, 10);
    layout_vmargin(layout, 4, 10);
    cell_dbind(layout_cell(layout, 0, 2), OBB, real32_t, width);
    cell_dbind(layout_cell(layout, 0, 4), OBB, real32_t, height);
    cell_dbind(layout_cell(layout, 0, 6), OBB, real32_t, angle);
    layout_dbind(layout, listener(app, i_OnOBB, App), OBB);
    app->obb_layout = layout;
    return layout;
}

/*---------------------------------------------------------------------------*/

static Layout *i_pol_layout(App *app)
{
    Layout *layout = layout_create(1, 5);
    Label *label1 = label_create();
    Label *label2 = label_create();
    Label *label3 = label_create();
    Slider *slider1 = slider_create();
    Slider *slider2 = slider_create();
    label_text(label1, "Selected Polygon");
    label_text(label2, "Angle:");
    label_text(label3, "Scale:");
    layout_label(layout, label1, 0, 0);
    layout_label(layout, label2, 0, 1);
    layout_label(layout, label3, 0, 3);
    layout_slider(layout, slider1, 0, 2);
    layout_slider(layout, slider2, 0, 4);
    layout_vmargin(layout, 0, 5);
    layout_vmargin(layout, 2, 10);
    cell_dbind(layout_cell(layout, 0, 2), Pol, real32_t, angle);
    cell_dbind(layout_cell(layout, 0, 4), Pol, real32_t, scale);
    layout_dbind(layout, listener(app, i_OnPoly, App), Pol);
    app->pol_layout = layout;
    return layout;
}

/*---------------------------------------------------------------------------*/

static void i_OnNewShape(App *app, Event *e)
{
    S2Df size;
    view_get_size(app->view, &size);
    col2dhello_new_shape(app, v2df(size.width / 2, size.height / 2));
    col2dhello_dbind_shape(app);
    col2dhello_collisions(app);
    view_update(app->view);
    unref(e);
}

/*---------------------------------------------------------------------------*/

static Layout *i_new_layout(App *app)
{
    Layout *layout = layout_create(1, 2);
    PopUp *popup = popup_create();
    Button *button = button_push();
    button_text(button, "New Shape");
    button_OnClick(button, listener(app, i_OnNewShape, App));
    layout_popup(layout, popup, 0, 0);
    layout_button(layout, button, 0, 1);
    layout_vmargin(layout, 0, 5);
    cell_dbind(layout_cell(layout, 0, 0), App, shtype_t, seltype);
    return layout;
}

/*---------------------------------------------------------------------------*/

static Layout *i_left_layout(App *app)
{
    Layout *layout1 = layout_create(1, 3);
    Layout *layout2 = i_new_layout(app);
    Layout *layout3 = i_empty_layout();
    Layout *layout4 = i_point_layout(app);
    Layout *layout5 = i_segment_layout(app);
    Layout *layout6 = i_circle_layout(app);
    Layout *layout7 = i_box_layout(app);
    Layout *layout8 = i_obb_layout(app);
    Layout *layout9 = i_pol_layout(app);
    Button *button1 = button_check();
    Panel *panel = panel_create();
    button_text(button1, "Show Segment-Point distance");
    panel_layout(panel, layout3);
    panel_layout(panel, layout4);
    panel_layout(panel, layout5);
    panel_layout(panel, layout6);
    panel_layout(panel, layout7);
    panel_layout(panel, layout8);
    panel_layout(panel, layout9);
    layout_hsize(layout1, 0, 200);
    layout_layout(layout1, layout2, 0, 0);
    layout_button(layout1, button1, 0, 1);
    layout_panel(layout1, panel, 0, 2);
    layout_vmargin(layout1, 0, 10);
    layout_vmargin(layout1, 1, 10);
    layout_margin(layout1, 10);
    app->obj_panel = panel;
    cell_dbind(layout_cell(layout1, 0, 1), App, bool_t, show_seg_pt);
    layout_dbind(layout1, listener(app, i_OnOpt, App), App);
    layout_dbind_obj(layout1, app, App);        
    return layout1;
}

/*---------------------------------------------------------------------------*/

static color_t i_color(const uint32_t collision, const bool_t mouse)
{
    if (collision > 0)
    {
        if (collision == 1)
            return color_rgb(255, 170, 0);

        if (collision == 2)
            return color_rgb(255, 127, 0);

        return color_rgb(255, 42, 0);
    }
    else
    {
        if (mouse == TRUE)
            return color_rgb(127, 85, 255);

        return color_gray(120);
    }
}

/*---------------------------------------------------------------------------*/

static void i_draw_point(DCtx *ctx, const V2Df *pt)
{
    draw_circle(ctx, ekFILL, pt->x, pt->y, CENTER_RADIUS);
}

/*---------------------------------------------------------------------------*/

static void i_draw_segment(DCtx *ctx, const Seg *seg)
{
    draw_line(ctx, seg->seg.p0.x, seg->seg.p0.y, seg->seg.p1.x, seg->seg.p1.y);
}

/*---------------------------------------------------------------------------*/

static void i_draw_circle(DCtx *ctx, const Cir2Df *circle)
{
    draw_circle(ctx, ekFILL, circle->c.x, circle->c.y, circle->r);
    draw_fill_color(ctx, kCOLOR_BLACK);
    draw_circle(ctx, ekFILL, circle->c.x, circle->c.y, CENTER_RADIUS);
}

/*---------------------------------------------------------------------------*/

static void i_draw_box(DCtx *ctx, const Box *box)
{
    draw_rect(ctx, ekFILL, box->box.min.x, box->box.min.y, box->width, box->height);
    draw_fill_color(ctx, kCOLOR_BLACK);
    draw_circle(ctx, ekFILL, box->center.x, box->center.y, CENTER_RADIUS);
}

/*---------------------------------------------------------------------------*/

static void i_draw_obb(DCtx *ctx, const OBB *obb)
{
    T2Df t2d;
    real32_t hwidth = obb->width / 2;
    real32_t hheight = obb->height / 2;
    t2d_movef(&t2d, kT2D_IDENTf, obb->center.x - hwidth, obb->center.y - hheight);
    t2d_movef(&t2d, &t2d, hwidth, hheight);
    t2d_rotatef(&t2d, &t2d, obb->angle);
    t2d_movef(&t2d, &t2d, -hwidth, -hheight);
    draw_matrix(ctx, &t2d);
    draw_rect(ctx, ekFILL, 0, 0, obb->width, obb->height);
    draw_matrix(ctx, kT2D_IDENTf);
    draw_fill_color(ctx, kCOLOR_BLACK);
    draw_circle(ctx, ekFILL, obb->center.x, obb->center.y, CENTER_RADIUS);
}

/*---------------------------------------------------------------------------*/

static void i_draw_poly(DCtx *ctx, const Pol *pol)
{
    const V2Df *points = pol2d_pointsf(pol->pol);
    uint32_t n = pol2d_nf(pol->pol);
    draw_polygon(ctx, ekFILL, points, n);
    draw_fill_color(ctx, kCOLOR_BLACK);
    draw_circle(ctx, ekFILL, pol->center.x, pol->center.y, CENTER_RADIUS);
}

/*---------------------------------------------------------------------------*/

static void i_draw_bbox(DCtx *ctx, const Shape *shape)
{
    Box2Df bbox = kBOX2D_NULLf;
    switch(shape->type) {
    case ekPOINT:
    {
        Cir2Df c = cir2df(shape->body.pnt.x, shape->body.pnt.y, CENTER_RADIUS);
        box2d_add_circlef(&bbox, &c);
        break;
    }

    case ekSEGMENT:
        box2d_addf(&bbox, &shape->body.seg.seg.p0);
        box2d_addf(&bbox, &shape->body.seg.seg.p1);
        break;

    case ekCIRCLE:
        box2d_add_circlef(&bbox, &shape->body.cir);
        break;

    case ekBOX:
        box2d_mergef(&bbox, &shape->body.box.box);
        break;

    case ekOBB:
    {
        const V2Df *corners = obb2d_cornersf(shape->body.obb.obb);
        box2d_addnf(&bbox, corners, 4);
        break;
    }

    case ekCONVEX_POLY:
    case ekSIMPLE_POLY:
    {
        const V2Df *points = pol2d_pointsf(shape->body.pol.pol);
        uint32_t n = pol2d_nf(shape->body.pol.pol);
        box2d_addnf(&bbox, points, n);
        break;
    }

    cassert_default();
    }

    draw_line_color(ctx, color_rgb(0, 128, 0));
    draw_rect(ctx, ekSTROKE, bbox.min.x, bbox.min.y, bbox.max.x - bbox.min.x, bbox.max.y - bbox.min.y);
}

/*---------------------------------------------------------------------------*/

static void i_OnDraw(App *app, Event *e)
{
    const EvDraw *p = event_params(e, EvDraw);

    draw_clear(p->ctx, color_rgb(255, 212, 255));

    arrst_foreach(shape, app->shapes, Shape)
        draw_fill_color(p->ctx, i_color(shape->collisions, shape->mouse));
        draw_line_color(p->ctx, i_color(shape->collisions, shape->mouse));
        
        switch(shape->type) {
        case ekPOINT:
            i_draw_point(p->ctx, &shape->body.pnt);
            break;

        case ekSEGMENT:
            i_draw_segment(p->ctx, &shape->body.seg);
            break;

        case ekCIRCLE:
            i_draw_circle(p->ctx, &shape->body.cir);
            break;

        case ekBOX:
            i_draw_box(p->ctx, &shape->body.box);
            break;

        case ekOBB:
            i_draw_obb(p->ctx, &shape->body.obb);
            break;

        case ekCONVEX_POLY:
        case ekSIMPLE_POLY:
            i_draw_poly(p->ctx, &shape->body.pol);
            break;

        cassert_default();
        }

        if (app->selshape == shape_i)
            i_draw_bbox(p->ctx, shape);

    arrst_end()

    if (app->show_seg_pt == TRUE)
    {
        real32_t pattern[2] = {2, 2};
        draw_line_dash(p->ctx, pattern, 2);
        draw_line_color(p->ctx, kCOLOR_MAGENTA);
        arrst_foreach(dist, app->dists, Dist)
            draw_line(p->ctx, dist->p0.x, dist->p0.y, dist->p1.x, dist->p1.y);
        arrst_end();
    }
}

/*---------------------------------------------------------------------------*/

static void i_OnMove(App *app, Event *e)
{
    const EvMouse *p = event_params(e, EvMouse);
    View *view = event_sender(e, View);
    col2dhello_mouse_collisions(app, p->x, p->y);
    view_update(view);
}

/*---------------------------------------------------------------------------*/

static void i_get_shape_pos(const Shape *shape, V2Df *pos)
{
    switch(shape->type) {
    case ekPOINT:
        pos->x = shape->body.pnt.x;
        pos->y = shape->body.pnt.y;
        break;

    case ekSEGMENT:
        pos->x = shape->body.seg.center.x;
        pos->y = shape->body.seg.center.y;
        break;

    case ekCIRCLE:
        pos->x = shape->body.cir.c.x;
        pos->y = shape->body.cir.c.y;
        break;

    case ekBOX:
        pos->x = shape->body.box.center.x;
        pos->y = shape->body.box.center.y;
        break;

    case ekOBB:
        pos->x = shape->body.obb.center.x;
        pos->y = shape->body.obb.center.y;
        break;

    case ekCONVEX_POLY:
    case ekSIMPLE_POLY:
        pos->x = shape->body.pol.center.x;
        pos->y = shape->body.pol.center.y;
        break;

    cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

static void i_set_shape_pos(Shape *shape, const V2Df pos)
{
    switch(shape->type) {
    case ekPOINT:
        shape->body.pnt = pos;
        break;

    case ekSEGMENT:
        shape->body.seg.center = pos;
        col2dhello_update_seg(&shape->body.seg);
        break;

    case ekCIRCLE:
        shape->body.cir.c = pos;
        break;

    case ekBOX:
        shape->body.box.center = pos;
        col2dhello_update_box(&shape->body.box);
        break;

    case ekOBB:
        shape->body.obb.center = pos;
        col2dhello_update_obb(&shape->body.obb);
        break;

    case ekCONVEX_POLY:
    case ekSIMPLE_POLY:
        shape->body.pol.center = pos;
        col2dhello_update_pol(&shape->body.pol);
        break;

    cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

static void i_OnDown(App *app, Event *e)
{
    uint32_t selshape = UINT32_MAX;
    arrst_foreach(shape, app->shapes, Shape)
        if (shape->mouse == TRUE)
        {
            selshape = shape_i;
            break;
        }
    arrst_end();

    if (selshape != app->selshape)
    {
        View *view = event_sender(e, View);
        app->selshape = selshape;
        col2dhello_dbind_shape(app);
        view_update(view);
    }

    if (app->selshape != UINT32_MAX)
    {
        const EvMouse *p = event_params(e, EvMouse);
        const Shape *shape = arrst_get(app->shapes, app->selshape, Shape);
        app->mouse_pos.x = p->x;
        app->mouse_pos.y = p->y;
        i_get_shape_pos(shape, &app->obj_pos);
    }
}

/*---------------------------------------------------------------------------*/

static void i_OnDrag(App *app, Event *e)
{
    if (app->selshape != UINT32_MAX)
    {
        const EvMouse *p = event_params(e, EvMouse);
        Shape *shape = arrst_get(app->shapes, app->selshape, Shape);
        V2Df move = v2df(app->obj_pos.x + (p->x - app->mouse_pos.x), app->obj_pos.y + (p->y - app->mouse_pos.y));
        i_set_shape_pos(shape, move);
        col2dhello_collisions(app);
        view_update(app->view);
    }
}

/*---------------------------------------------------------------------------*/

static Layout *i_layout(App *app)
{
    Layout *layout1 = layout_create(2, 1);
    Layout *layout2 = i_left_layout(app);
    View *view = view_create();
    view_size(view, s2df(640, 580));
    view_OnDraw(view, listener(app, i_OnDraw, App));
    view_OnMove(view, listener(app, i_OnMove, App));
    view_OnDown(view, listener(app, i_OnDown, App));
    view_OnDrag(view, listener(app, i_OnDrag, App));
    layout_layout(layout1, layout2, 0, 0);
    layout_view(layout1, view, 1, 0);
    layout_valign(layout1, 0, 0, ekTOP);
    layout_hexpand(layout1, 1);
    app->view = view;
    return layout1;
}

/*---------------------------------------------------------------------------*/

Window *col2dhello_window(App *app)
{
    Panel *panel = panel_create();
    Layout *layout = i_layout(app);
    Window *window = NULL;
    panel_layout(panel, layout);
    window = window_create(ekWNSRES, &panel);
    return window;
}

/*---------------------------------------------------------------------------*/

void col2dhello_dbind_shape(App *app)
{
    if (app->selshape != UINT32_MAX)
    {
        Shape *shape = arrst_get(app->shapes, app->selshape, Shape);
        switch(shape->type) {
        case ekPOINT:
            panel_visible_layout(app->obj_panel, 1);
            break;

        case ekSEGMENT:
            layout_dbind_obj(app->seg_layout, &shape->body.seg, Seg);
            panel_visible_layout(app->obj_panel, 2);
            break;

        case ekCIRCLE:
            layout_dbind_obj(app->cir_layout, &shape->body.cir, Cir2Df);
            panel_visible_layout(app->obj_panel, 3);
            break;

        case ekBOX:
            layout_dbind_obj(app->box_layout, &shape->body.box, Box);
            panel_visible_layout(app->obj_panel, 4);
            break;

        case ekOBB:
            layout_dbind_obj(app->obb_layout, &shape->body.obb, OBB);
            panel_visible_layout(app->obj_panel, 5);
            break;

        case ekCONVEX_POLY:
        case ekSIMPLE_POLY:
            layout_dbind_obj(app->pol_layout, &shape->body.pol, Pol);
            panel_visible_layout(app->obj_panel, 6);
            break;

        cassert_default();
        }
    }
    else
    {
        layout_dbind_obj(app->seg_layout, NULL, Seg);
        layout_dbind_obj(app->cir_layout, NULL, Cir2Df);
        layout_dbind_obj(app->box_layout, NULL, Box);
        layout_dbind_obj(app->obb_layout, NULL, OBB);
        layout_dbind_obj(app->pol_layout, NULL, Pol);
        panel_visible_layout(app->obj_panel, 0);
    }

    panel_update(app->obj_panel);
}
