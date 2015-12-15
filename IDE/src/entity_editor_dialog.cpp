#include "entity_editor_dialog.h"
#include "ui_entity_editor_dialog.h"

Entity_Editor_dialog::Entity_Editor_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Entity_Editor_dialog)
{
    ui->setupUi(this);
}

Entity_Editor_dialog::~Entity_Editor_dialog()
{
    delete ui;
}

void Entity_Editor_dialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
