#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "ip_view.h"
#include "ui_ip_view.h"
#include "Xhdl_tcl_interface.h"

IP_View::IP_View(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::IP_View)
{
    m_ui->setupUi(this);
    this->showMaximized () ;
    // this->setGeometry(this->parent()->rect());
    IPView = new QGraphicsView (this);
    //IPView->setGeometry(this->rect());
    // IPView->setAlignment( Qt::AlignCenter );
    // this->m_ui->gridLayout_2->addWidget(IPView, 0, 0, 1, 1);
    this->m_ui->gridLayout_3->addWidget(IPView, 0, 0, 1, 1);



    // Connect signals/slots
    //connect(this, SIGNAL(resized()),this, SLOT (update_myview()));
    //connect(this, SIGNAL(maximized()),this, SLOT (update_myview()));
    //connect(this, SIGNAL(clicked()),this, SLOT (update_myview()));
    this->m_ui->tableWidget_signals->setAlternatingRowColors(true);

}
QGraphicsView *IP_View::getIPView() const
{
    return IPView;
}

void IP_View::setIPView(QGraphicsView *value)
{
    IPView = value;
}
QEntityScene *IP_View::getScene() const
{
    return scene;
}

void IP_View::setScene(QEntityScene *value)
{
    this->IPView->setScene(value);
    scene = value;
}
XhdlIp *IP_View::getIp() const
{
    return ip;
}

void IP_View::setIp(XhdlIp *value)
{
    ip = value;
}


//!  Creates a blank IP
void IP_View::blankIp()
{
    this->ip = new XhdlIp();
    ip->set_ip_name("new_ip");
    ip->setIp();
}

bool IP_View::open_xml_file(QString filename)
{
    this->ip = new XhdlIp();

    ip->set_ip_name("new_ip");
    ip->setIp();
    ip_open_xml_file (this->ip , (filename.toLatin1 ()).data());

}





IP_View::~IP_View()
{
    delete m_ui;
}

void IP_View::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void IP_View::update_myview()
{

    IPView->setGeometry(this->rect());
}
