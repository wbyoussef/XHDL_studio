#include "qscene_inout.h"
#include "qentityscene.h"

QScene_inout::QScene_inout(QEntityScene *entity_scene,QString signal_name)
        : QSceneBasicElement (entity_scene, entity_scene->ip)
{
    // define rectangle shape
    int body_width = 100;
    int body_height = 30 ;

    // Draw the rectangle
    border_widget = this->scene()->addRect(QRect(100,33,body_width, body_height ) );
    border_widget->setPen(QPen (Qt::blue, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    // Paint the rectangle
    QRadialGradient gradient(100, 50, 50, 50, 50);
    gradient.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
    gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0, 0));
    border_widget->setBrush (QBrush (gradient));

    this->addToGroup(border_widget);
}



void QScene_inout::setX(int x)
{
    border_widget->setX(x);
}

void QScene_inout::setY(int y)
{
    border_widget->setY(y);
}


int QScene_inout::getX()
{
    return border_widget->x();
}

int QScene_inout::getY()
{
    return border_widget->y();
}
