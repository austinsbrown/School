#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    Ui::Dialog *ui;   /* On this exam, the form pointer UI must remain a public member of Dialog */

signals:
    void updateStatus(bool status);

private slots:
    void changeButton();
    void mysteryButton();
    void reset();
    void processWinner();
    void createDialog();
    void setLabels();
};

#endif // DIALOG_H
