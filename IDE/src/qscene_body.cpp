#include "qscene_body.h"
#include "ninja_apis.h"


QScene_body ::QScene_body (QEntityScene *entity_scene)
        : QSceneBasicElement (entity_scene, entity_scene->ip)
{
    // inputs count
    int in_cnt = xhdl_get_inputs_cnt( this->ip );
    // outputs count
    int out_cnt = xhdl_get_outputs_cnt( this->ip );

    // define rectangle shape
    int body_width = 300; //to match ip name length
    int body_height;
    if (in_cnt > out_cnt)
    {
      body_height =10 * in_cnt + 200;
    } else
    {
        body_height =10 * out_cnt + 200;
    }


    // Draw therectangle
    QGraphicsRectItem *border_widget = this->scene()->addRect(QRect(100,33,body_width, body_height ) );
    border_widget->setPen(QPen (Qt::red, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin));

    // Paint the rectangle
//    QRadialGradient gradient(100, 50, 50, 50, 50);
//    gradient.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
//    gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0, 0));
//    border_widget->setBrush (QBrush (gradient));

    this->addToGroup(border_widget);
}




void QScene_body ::mousePressEvent ( QGraphicsSceneMouseEvent * event )
{
    // exit (0);
}
