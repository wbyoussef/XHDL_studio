#ifndef QENTITYSCENE_LABEL_H
#define QENTITYSCENE_LABEL_H
#include "qscenebasicelement.h"


class QEntityScene_label : public QSceneBasicElement
{
public:
    QEntityScene_label(QGraphicsTextItem *mother_item, QEntityScene *entity_scene);
    void mousePressEvent ( QGraphicsSceneMouseEvent * event );

private :
};

#endif // QENTITYSCENE_LABEL_H
