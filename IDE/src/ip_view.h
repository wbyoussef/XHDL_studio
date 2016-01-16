#ifndef IP_VIEW_H
#define IP_VIEW_H

#include <QtWidgets/QWidget>
#include <QGraphicsView>

namespace Ui {
    class IP_View;
}

#include "qentityscene.h"

class IP_View : public QWidget {
    Q_OBJECT
public:
    IP_View(QWidget *parent = 0);
    // canvas for displyaing items
    ~IP_View();

    QGraphicsView *getIPView() const;
    void setIPView(QGraphicsView *value);

    QEntityScene *getScene() const;
    void setScene(QEntityScene *value);

    XhdlIp *getIp() const;
    void setIp(XhdlIp *value);
    void blankIp();
    bool open_xml_file (QString  filename);

private :
    QGraphicsView *IPView;
    QEntityScene *scene;
    XhdlIp* ip;


protected:
    void changeEvent(QEvent *e);

protected :
    Ui::IP_View *m_ui;


    // SLOTS :
public slots :
void update_myview();

};

#endif // IP_VIEW_H
