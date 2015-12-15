#ifndef QSCENE_PORT_H
#define QSCENE_PORT_H

#include "qscene_inout.h"
#include "qentityscene.h"


class QScene_port : public QSceneBasicElement
{
public:
    QScene_port (QGraphicsTextItem *mother_item, QEntityScene *entity_scene);
    void mousePressEvent ( QGraphicsSceneMouseEvent * event );

private :
};


#endif // QSCENE_PORT_H
