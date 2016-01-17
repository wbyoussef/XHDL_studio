
#include <QGraphicsItemGroup>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <qpainter.h>
#include <qdebug.h>

#include "qentityscene.h"
#include "ninja_apis.h"
#include "qscene_inout.h"
#include "qentityscene_label.h"
#include "qscene_body.h"

#include "XhdlEntity.h"


QEntityScene::QEntityScene(XhdlIp *ip)
{
    this->ip = ip;
    this->draw_scene ();
    // this->addText(ip->get_ip_name());

    this->inputs_cnt = xhdl_get_inputs_cnt(ip);
    this->outputs_cnt = xhdl_get_outputs_cnt(ip);
    this->setGridStep(25);
}


void QEntityScene::draw_scene ()
{
    draw_ip_name ();
    draw_body ();
//    draw_inputs ();
//    draw_outputs ();
}



void QEntityScene::draw_ip_name ()
{

    this->label = new QEntityScene_label(this,ip->get_ip_name());

}

void QEntityScene::draw_body ()
{
    //draw the Body of the IP
    Scene_body = new QScene_body(this);
}

void QEntityScene::draw_inputs ()
{
    vector <XhdlSignal*>::const_iterator p_it;
    for ( p_it = ip->entity->list_bus.begin() ; p_it != ip->entity->list_bus.end () ; p_it ++ )
      {
        if (is_input (*p_it))
        {
            QScene_inout *tmp_inout = new QScene_inout (this, ((*p_it)->name).c_str());
            this->input_list.push_back(tmp_inout);
        }
      }

}

void QEntityScene::draw_outputs ()
{
    vector <XhdlSignal*>::const_iterator p_it;
    for ( p_it = ip->entity->list_bus.begin() ; p_it != ip->entity->list_bus.end () ; p_it ++ )
      {
        if (is_output (*p_it))
        {
            QScene_inout *tmp_inout = new QScene_inout (this, ((*p_it)->name).c_str());
            this->output_list.push_back(tmp_inout);
        }
      }
}


// Place inout wideget on canvas
void QEntityScene::place_inouts()
{
    for (int i = 0; i < this->input_list.size(); ++i)
    {
        this->input_list.at(i)->setY (10 * i );
    }
}





void QEntityScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    this->drawDotsBackground(painter,rect);
}

void QEntityScene::drawMarksBackground(QPainter *painter, const QRectF &rect)
{
    const int gridSize = this->getGridStep();

    qreal left = int(rect.left()) - (int(rect.left()) % gridSize);
    qreal top = int(rect.top()) - (int(rect.top()) % gridSize);

    QVarLengthArray<QLineF, 100> lines;

    for (qreal x = rect.left()+2; x < rect.right(); x += gridSize)
        lines.append(QLineF(x, rect.top(), x, rect.bottom()));
    for (qreal y = rect.top()+2; y < rect.bottom(); y += gridSize)
        lines.append(QLineF(rect.left(), y, rect.right(), y));

    painter->setBrush(Qt::Dense7Pattern);
    QPen pen;
    QVector<qreal> dashes;
    qreal space = 20;

    dashes << 5 << space ;
    pen.setDashPattern(dashes);
    pen.setColor(Qt::gray);
    painter->setPen(pen);
//    painter->setPen(Qt::DotLine);
    painter->drawLines(lines.data(), lines.size());

}

void QEntityScene::drawDotsBackground(QPainter *painter, const QRectF &rect)
{
    const int gridSize = this->getGridStep();
    QPen pen;
    painter->setPen(pen);

    qreal left = int(rect.left()) - (int(rect.left()) % gridSize);
    qreal top = int(rect.top()) - (int(rect.top()) % gridSize);
    QVector<QPointF> points;
    for (qreal x = left; x < rect.right(); x += gridSize){
        for (qreal y = top; y < rect.bottom(); y += gridSize){
            points.append(QPointF(x,y));
        }
    }
    painter->drawPoints(points.data(), points.size());
}

int QEntityScene::getGridStep() const
{
    return GridStep;
}

void QEntityScene::setGridStep(int value)
{
    GridStep = value;
}
