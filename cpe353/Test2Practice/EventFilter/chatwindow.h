#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include <QTextEdit>
#include <QTextBrowser>
#include <QEvent>

class QTextBrowser;
class QTextEdit;
class QEvent;

class ChatWindow : public QWidget
{
Q_OBJECT

public:
    ChatWindow(QWidget *parent = 0);
    bool eventFilter(QObject *watched, QEvent *e);

private:
    QTextBrowser    *conversationView;
    QTextEdit       *chatEdit;
};

#endif // CHATWINDOW_H
