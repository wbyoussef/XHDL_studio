
#include <QGraphicsItemGroup>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>


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
}


void QEntityScene::draw_scene ()
{
    draw_ip_name ();
    draw_body ();
    draw_inputs ();
    draw_outputs ();
}



void QEntityScene::draw_ip_name ()
{

    this->label = new QEntityScene_label(this->addText(ip->get_ip_name()),this);

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






