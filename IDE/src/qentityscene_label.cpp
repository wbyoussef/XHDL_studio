#include <QGraphicsItemGroup>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>



#include "qentityscene_label.h"


QEntityScene_label::QEntityScene_label(QGraphicsTextItem *mother_item,
                                       QEntityScene *entity_scene)
        : QSceneBasicElement (entity_scene,ip)
{
    //
    int x = mother_item->boundingRect().x();
    int y = mother_item->boundingRect().y();
    int h = mother_item->boundingRect().height();
    int w = mother_item->boundingRect().width();

    QGraphicsRectItem *border_widget = this->scene()->addRect(QRect(x-20,y-20,w+40,h+40) );
    border_widget->setPen(QPen (Qt::green, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin));

    QRadialGradient gradient(50, 50, 50, 50, 50);
    gradient.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
    gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0, 0));
    border_widget->setBrush (QBrush (gradient));

    // Group Widgets
    this->addToGroup(border_widget);
}




void QEntityScene_label::mousePressEvent ( QGraphicsSceneMouseEvent * event )
{
    exit (0);
}

