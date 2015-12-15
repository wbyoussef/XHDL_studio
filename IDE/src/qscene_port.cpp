#include "qscene_port.h"

QScene_port ::QScene_port (QGraphicsTextItem *mother_item,
                                       QEntityScene *entity_scene)
        : QSceneBasicElement (entity_scene, ip)
{
    //
    int x = mother_item->boundingRect().x();
    int y = mother_item->boundingRect().y();
    int h = mother_item->boundingRect().height();
    int w = mother_item->boundingRect().width();

    QGraphicsRectItem *border_widget = this->scene()->addRect(QRect(x,y,w,h) );

    // Group Widgets
    this->addToGroup(border_widget);
}




void QScene_port ::mousePressEvent ( QGraphicsSceneMouseEvent * event )
{
    // exit (0);
}

