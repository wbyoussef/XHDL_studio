#ifndef QENTITYSCENE_H
#define QENTITYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsItemGroup>

#include "XhdlIp.h"

#include "qscenebasicelement.h"
#include "qscene_inout.h"
#include "qscene_body.h"

class QScene_body ;
class QSceneBasicElement;

class QEntityScene_label;

class QEntityScene : public QGraphicsScene
{
public:
    QEntityScene(XhdlIp *ip);
    void draw_scene ();
    XhdlIp *ip;
    void drawBackground(QPainter *painter, const QRectF &rect);
    void drawMarksBackground(QPainter *painter, const QRectF &rect);
    void drawDotsBackground(QPainter *painter, const QRectF &rect);

    int getGridStep() const;
    void setGridStep(int value);

private :
    int GridStep;
    QEntityScene_label* label;
    void draw_ip_name ();
    void draw_body ();
    void draw_inputs ();
    void draw_outputs ();
    void place_inouts();
    // Number of inputs
    int inputs_cnt;
    // Number of outputs
    int outputs_cnt;

    // Widget Elements
    /////////////////////////////

    // List of Inout widegts
    QVector<QScene_inout*> input_list;
    QVector<QScene_inout*> output_list;

    // Body Widget
    QScene_body *Scene_body ;


};







#endif // QENTITYSCENE_H
