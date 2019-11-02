#include "dropenabledimagerviewer.h"
#include <QDropEvent>
#include <QMimeData>
#include <QDebug>

DropEnabledImagerViewer::DropEnabledImagerViewer(QWidget *parent):QLabel(parent)
{
    setAcceptDrops(true);
}

void DropEnabledImagerViewer::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}

void DropEnabledImagerViewer::dropEvent(QDropEvent *event)
{
    qDebug() << event->mimeData()->urls();
    QPixmap temp(event->mimeData()->urls().back().toLocalFile());
    setPixmap(temp);
    adjustSize();
    event->acceptProposedAction();
}
