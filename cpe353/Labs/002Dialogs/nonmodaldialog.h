#ifndef NONMODALDIALOG_H
#define NONMODALDIALOG_H

#include <QDialog>

namespace Ui {
class NonModalDialog;
}

class NonModalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NonModalDialog(QWidget *parent = nullptr);
    ~NonModalDialog();

private:
    Ui::NonModalDialog *ui;
    int n = 1;

private slots:
    void repeat();
};

#endif // NONMODALDIALOG_H
