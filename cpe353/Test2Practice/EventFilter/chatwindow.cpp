#include "chatwindow.h"
#include <QVBoxLayout>
#include <QSplitter>
#include <QKeyEvent>


ChatWindow::ChatWindow(QWidget *parent)
{
    QVBoxLayout *lay = new QVBoxLayout(this);
    QSplitter *splitter = new QSplitter(Qt::Vertical, this);
    lay->addWidget(splitter);
    conversationView = new QTextBrowser;
    chatEdit = new QTextEdit;
    splitter->addWidget(conversationView);
    splitter->addWidget(chatEdit);
    chatEdit->installEventFilter(this);
    setWindowTitle(tr("Chat Window"));
    setTabOrder(chatEdit, conversationView);
}

bool ChatWindow::eventFilter(QObject *watched, QEvent *e)
{
    if(!watched || !e) return QWidget::eventFilter(watched, e);

    if(watched == chatEdit && e->type() == QEvent::KeyPress)
    {
        QKeyEvent *ke = static_cast<QKeyEvent*>(e);
        switch (ke->key())
        {
            case Qt::Key_0:
            case Qt::Key_1:
            case Qt::Key_2:
            case Qt::Key_3:
            case Qt::Key_4:
            case Qt::Key_5:
            case Qt::Key_6:
            case Qt::Key_7:
            case Qt::Key_8:
            case Qt::Key_9: conversationView->append(ke->text());
                            break;

            case Qt::Key_Enter:
            case Qt::Key_Return:
                            chatEdit->clear();
                            break;

        }
    }
    return QWidget::eventFilter(watched, e);
}






















