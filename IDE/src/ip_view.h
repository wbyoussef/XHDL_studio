#ifndef IP_VIEW_H
#define IP_VIEW_H

#include <QtWidgets/QWidget>
#include <QGraphicsView>

namespace Ui {
    class IP_View;
}

class IP_View : public QWidget {
    Q_OBJECT
public:
    IP_View(QWidget *parent = 0);
    // canvas for displyaing items
    ~IP_View();

    QGraphicsView *getIPView() const;
    void setIPView(QGraphicsView *value);

private :
    QGraphicsView *IPView;


protected:
    void changeEvent(QEvent *e);

protected :
    Ui::IP_View *m_ui;


    // SLOTS :
public slots :
void update_myview();

};

#endif // IP_VIEW_H
