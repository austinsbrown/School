#ifndef MODALDIALOG_H
#define MODALDIALOG_H

#include <QDialog>

namespace Ui {
class ModalDialog;
}

class ModalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModalDialog(QWidget *parent = nullptr);
    ~ModalDialog();

private:
    Ui::ModalDialog *ui;
};

#endif // MODALDIALOG_H
