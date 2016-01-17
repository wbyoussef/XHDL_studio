#ifndef QENTITYSCENE_LABEL_H
#define QENTITYSCENE_LABEL_H
#include "qscenebasicelement.h"


class QEntityScene_label : public QSceneBasicElement
{
public:
    QEntityScene_label(QGraphicsTextItem *mother_item, QEntityScene *entity_scene, QString label);
    QEntityScene_label(QEntityScene *entity_scene, QString label);
    void mousePressEvent ( QGraphicsSceneMouseEvent * event );

private :
    QString lablel;

};

#endif // QENTITYSCENE_LABEL_H
