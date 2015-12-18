/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
** package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at http://www.qtsoftware.com/contact.
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include <QGraphicsScene>

#include "mdichild.h"

#include "XhdlEntity.h"
#include "Xhdl_tcl_interface.h"
#include "xs_qtreewidgetitem.h"
#include "ninja_defines.h"

MdiChild::MdiChild()
{
    setAttribute(Qt::WA_DeleteOnClose);
    isUntitled = true;

}

void MdiChild::newFile()
{
    main_ip = new XhdlIp();
    main_ip->set_ip_name("new_ip");
    main_ip->setIp();
    this->entity_scene = new QEntityScene (main_ip);
    (this->getIPView())->setScene(entity_scene);
}

bool MdiChild::loadFile(const QString &fileName)
{
    main_ip = new XhdlIp();

    main_ip->set_ip_name("new_ip");
    main_ip->setIp();
    ip_open_xml_file (main_ip , (fileName.toLatin1 ()).data());

    // fill scenes
    this->entity_scene = new QEntityScene (main_ip);
    (this->getIPView())->setScene(entity_scene);
    fill_description();
    return true;

}

bool MdiChild::save()
{
    if (isUntitled) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

bool MdiChild::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                                    curFile);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

bool MdiChild::saveFile(const QString &fileName)
{
}

bool MdiChild::fill_description()
{
    //! fille IP namme
    XS_QTreeWidgetItem* item = new XS_QTreeWidgetItem("", XHDL::XHDL_NONE);
    item->setText(0,QString ("General"));

    XS_QTreeWidgetItem* item_ipname = new XS_QTreeWidgetItem(this->main_ip->entity->getFull_name().c_str(), XHDL::XHDL_ENTITTY);
    item_ipname->setText(0,"name");
    item_ipname->setText(1,this->main_ip->entity->name.c_str());
    item->addChild(item_ipname);

    XS_QTreeWidgetItem* item_params = new XS_QTreeWidgetItem("",XHDL::XHDL_NONE);
    item_params->setText(0,QString ("Parameters"));

    for (int i =0; i<this->main_ip->entity->list_params.size();i++) {
        XS_QTreeWidgetItem* item_params_unit = new XS_QTreeWidgetItem(this->main_ip->entity->list_params.at(i).c_str(),XHDL::XHDL_PARAMETER  );
        item_params_unit->setText(0, this->main_ip->entity->list_params.at(i).c_str());
        item_params->addChild(item_params_unit);
    }

    XS_QTreeWidgetItem* item_bus = new XS_QTreeWidgetItem("",XHDL::XHDL_NONE);
    item_bus->setText(0,QString ("Interface"));

    for (int i =0; i<this->main_ip->entity->list_bus.size();i++) {
        XS_QTreeWidgetItem* item_params_unit = new XS_QTreeWidgetItem(this->main_ip->entity->list_bus.at(i)->getFull_name().c_str(),XHDL::XHDL_SIGNAL);
        item_params_unit->setText(0, (this->main_ip->entity->list_bus.at(i)->name.c_str()));
        item_bus->addChild(item_params_unit);
    }

    XS_QTreeWidgetItem* item_clocks = new XS_QTreeWidgetItem("",XHDL::XHDL_NONE);
    item_clocks->setText(0,"clocks");
    XS_QTreeWidgetItem* item_clock = new XS_QTreeWidgetItem(this->main_ip->entity->clk->getFull_name().c_str(),XHDL::XHDL_CLOCK);
    item_clock->setText(0,this->main_ip->entity->clk->name.c_str());
    item_clocks->addChild(item_clock);



    XS_QTreeWidgetItem* item_archs = new XS_QTreeWidgetItem("",XHDL::XHDL_NONE);
    item_archs->setText(0,QString ("Architectures"));
    for (int i =0; i<this->main_ip->list_arch.size();i++) {
        XS_QTreeWidgetItem* tmp_item = new XS_QTreeWidgetItem(this->main_ip->list_arch.at(i)->getFull_name().c_str(),XHDL::XHDL_ARCH);
        tmp_item->setText(0, (this->main_ip->list_arch.at(i)->name.c_str()));
        item_archs->addChild(tmp_item);
    }

    // add to tree
    this->m_ui->treeWidget_summary->addTopLevelItem(item);
    this->m_ui->treeWidget_summary->addTopLevelItem(item_params);
    this->m_ui->treeWidget_summary->addTopLevelItem(item_bus);
    this->m_ui->treeWidget_summary->addTopLevelItem(item_clocks);
    this->m_ui->treeWidget_summary->addTopLevelItem(item_archs);

}

void MdiChild::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

void MdiChild::documentWasModified()
{
    /// setWindowModified(document()->isModified());
}

bool MdiChild::maybeSave()
{
    /*
    if (document()->isModified()) {
	QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("MDI"),
                     tr("'%1' has been modified.\n"
                        "Do you want to save your changes?")
                     .arg(userFriendlyCurrentFile()),
                     QMessageBox::Save | QMessageBox::Discard
		     | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
            return save();
        else if (ret == QMessageBox::Cancel)
            return false;
    }
    return true;
    */
}

void MdiChild::setCurrentFile(const QString &fileName)
{ /*
    curFile = QFileInfo(fileName).canonicalFilePath();
    isUntitled = false;
    document()->setModified(false);
    setWindowModified(false);
    setWindowTitle(userFriendlyCurrentFile() + "[*]"); */
}

QString MdiChild::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}
