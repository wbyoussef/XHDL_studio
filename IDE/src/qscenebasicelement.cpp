#include "qscenebasicelement.h"

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "qentityscene.h"
#include <QtWidgets>

QSceneBasicElement::QSceneBasicElement( QEntityScene *entity_scene, XhdlIp *ip)
        : QGraphicsItemGroup ( )
{
    entity_scene->addItem(this);
    // test purpose rectangle
    //QGraphicsRectItem *border_widget = this->scene()->addRect(QRect(10,33,3,5) );
    //this->addToGroup(border_widget);

    this->set_ip(ip);



}


void QSceneBasicElement::mousePressEvent ( QGraphicsSceneMouseEvent * event )
{
    exit (0);
}


void QSceneBasicElement::set_ip (XhdlIp *ip)
{
    this->ip = ip;
}


void QSceneBasicElement::setX(int x)
{

}

void QSceneBasicElement::setY(int y)
{

}


int QSceneBasicElement::getX()
{

}

int QSceneBasicElement::setY()
{

}

