#ifndef IP_VIEW_H
#define IP_VIEW_H

#include <QtGui/QWidget>
#include <QGraphicsView>

namespace Ui {
    class IP_View;
}

class IP_View : public QWidget {
    Q_OBJECT
public:
    IP_View(QWidget *parent = 0);
    // canvas for displyaing items
    QGraphicsView *IPView;
    ~IP_View();

protected:
    void changeEvent(QEvent *e);

protected :
    Ui::IP_View *m_ui;


    // SLOTS :
public slots :
void update_myview();

};

#endif // IP_VIEW_H
