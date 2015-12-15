#ifndef QSCENE_INOUT_H
#define QSCENE_INOUT_H

#include "qscenebasicelement.h"

class QScene_inout : public QSceneBasicElement
{
public:
    QScene_inout(QEntityScene *entity_scene, QString signal_name);
    void setX(int x);
    void setY(int y);

    int getX();
    int getY();

    // inout canvas elements :
private :
    QGraphicsRectItem *border_widget;


};

#endif // QSCENE_INOUT_H
