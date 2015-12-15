#ifndef ENTITY_EDITOR_DIALOG_H
#define ENTITY_EDITOR_DIALOG_H

#include <QDialog>

namespace Ui {
    class Entity_Editor_dialog;
}

class Entity_Editor_dialog : public QDialog {
    Q_OBJECT
public:
    Entity_Editor_dialog(QWidget *parent = 0);
    ~Entity_Editor_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Entity_Editor_dialog *ui;
};

#endif // ENTITY_EDITOR_DIALOG_H
