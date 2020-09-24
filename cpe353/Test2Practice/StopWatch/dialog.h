#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include "clock.h"

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

    QTimer*     timer;
    bool        paused;
    Clock       clock;

private slots:
    void startTimer();
    void pauseTimer();
    void clearTimer();
    void updateDisplay();
};

#endif // DIALOG_H
