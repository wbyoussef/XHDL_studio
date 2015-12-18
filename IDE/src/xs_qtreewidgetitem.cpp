#include "xs_qtreewidgetitem.h"

XS_QTreeWidgetItem::XS_QTreeWidgetItem(QString full_name, XHDL::XHDL_GUI_TAG TAG)
{
    this->setTAG(TAG);
    this->setFull_name(full_name);
}
QString XS_QTreeWidgetItem::getFull_name() const
{
    return full_name;
}

void XS_QTreeWidgetItem::setFull_name(const QString &value)
{
    full_name = value;
}
XHDL::XHDL_GUI_TAG XS_QTreeWidgetItem::getTAG() const
{
    return TAG;
}

void XS_QTreeWidgetItem::setTAG(const XHDL::XHDL_GUI_TAG &value)
{
    TAG = value;
}


