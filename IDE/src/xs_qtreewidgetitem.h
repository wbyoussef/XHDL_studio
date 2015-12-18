#ifndef XS_QTREEWIDGETITEM_H
#define XS_QTREEWIDGETITEM_H

#include <QWidget>
#include <QTreeWidgetItem>
#include "ninja_defines.h"

class XS_QTreeWidgetItem : public QTreeWidgetItem {
public:
    XS_QTreeWidgetItem(QString full_name, XHDL::XHDL_GUI_TAG TAG);

    QString getFull_name() const;
    void setFull_name(const QString &value);


    XHDL::XHDL_GUI_TAG getTAG() const;
    void setTAG(const XHDL::XHDL_GUI_TAG &value);

private :
    QString full_name;
    XHDL::XHDL_GUI_TAG TAG;
};

#endif // XS_QTREEWIDGETITEM_H
