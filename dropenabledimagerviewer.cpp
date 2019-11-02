#include "dropenabledimagerviewer.h"
#include <QDropEvent>
#include <QMimeData>

DropEnabledImagerViewer::DropEnabledImagerViewer(QWidget *parent):QLabel(parent)
{
    setAcceptDrops(true);
}

void DropEnabledImagerViewer::dragEnterEvent(QDragEnterEvent *event)
{
//    if (event->mimeData()->hasFormat("image"))
        event->acceptProposedAction();
}

void DropEnabledImagerViewer::dropEvent(QDropEvent *event)
{
    QPixmap temp(event->mimeData()->text());
//    temp.scaled(300,300,Qt::AspectRatioMode::KeepAspectRatio, Qt::SmoothTransformation);
    setPixmap(temp);
    adjustSize();
    event->acceptProposedAction();
}
