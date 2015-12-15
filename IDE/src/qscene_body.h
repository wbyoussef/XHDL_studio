#ifndef QSCENE_BODY_H
#define QSCENE_BODY_H

#include "qscene_inout.h"
#include "qentityscene.h"

class QScene_body : public QSceneBasicElement
{
public:
    QScene_body (QEntityScene *entity_scene);
    void mousePressEvent ( QGraphicsSceneMouseEvent * event );

private :
};


#endif // QSCENE_BODY_H
