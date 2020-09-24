#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "modaldialog.h"
#include "nonmodaldialog.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

private slots:
    void modal();
    void nonModal();
};

#endif // DIALOG_H
