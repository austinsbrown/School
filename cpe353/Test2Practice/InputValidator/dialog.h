#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QIntValidator>
#include <QRegularExpressionValidator>
#include <QDoubleValidator>

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
};

#endif // DIALOG_H
