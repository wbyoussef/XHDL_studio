#ifndef QSCENEBASICELEMENT_H
#define QSCENEBASICELEMENT_H

#include <QGraphicsItemGroup>
#include <QAbstractGraphicsShapeItem>

#include "XhdlIp.h"

class QEntityScene ;

class QSceneBasicElement : public QGraphicsItemGroup
{
    enum element_type { INPUT, OUTPUT, BUFFER, PORTMAT, PROCESS, STATIC, XSIGNAL};
public:
    QSceneBasicElement(QEntityScene *entity_scene, XhdlIp *ip);
    void select ();
    void deselect ();
    bool isselected ();
    QString get_vhdl();
    QString get_tcl();
    void copy();
    void cut();
    void properties();
    void edit();
    void get_from_vhdl();
    void start_move();
    void end_move ();
    void set_border_color(QColor);
    void set_fill_color(QColor);
    void mousePressEvent ( QGraphicsSceneMouseEvent * event );
    void setX(int x);
    void setY(int y);

    int getX();
    int setY();

    void set_ip (XhdlIp *ip);
    XhdlIp *ip;

private :
        QColor border_color;
        QColor fill_color;
        element_type type;

};

#endif // QSCENEBASICELEMENT_H
