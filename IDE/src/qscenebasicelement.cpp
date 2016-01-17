#include "qscenebasicelement.h"

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "qentityscene.h"
#include <QtWidgets>

QSceneBasicElement::QSceneBasicElement( QEntityScene *entity_scene, XhdlIp *ip)
        : QGraphicsItemGroup ( )
{
    this->entity_scene = entity_scene;
    entity_scene->addItem(this);
    // test purpose rectangle
    //QGraphicsRectItem *border_widget = this->scene()->addRect(QRect(10,33,3,5) );
    //this->addToGroup(border_widget);

    this->set_ip(ip);
    this->setFlags(QGraphicsItem::ItemIsSelectable |
            QGraphicsItem::ItemIsMovable |
            QGraphicsItem::ItemSendsGeometryChanges);


}


void QSceneBasicElement::mousePressEvent ( QGraphicsSceneMouseEvent * event )
{
    exit (0);
}


void QSceneBasicElement::set_ip (XhdlIp *ip)
{
    this->ip = ip;
}

QVariant QSceneBasicElement::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange && scene()) {
        QPointF newPos = value.toPointF();
        if(QApplication::mouseButtons() == Qt::LeftButton )
        {
            int gridSize = entity_scene->getGridStep();//customScene->getGridSize();
            qreal xV = round(newPos.x()/gridSize)*gridSize;
            qreal yV = round(newPos.y()/gridSize)*gridSize;
            return QPointF(xV, yV);
        }
        else
            return newPos;
    }
    else
        return QGraphicsItem::itemChange(change, value);
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

