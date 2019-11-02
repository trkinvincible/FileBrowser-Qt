#ifndef DROPENABLEDIMAGERVIEWER_H
#define DROPENABLEDIMAGERVIEWER_H

#include <QLabel>

class DropEnabledImagerViewer : public QLabel
{
public:
    DropEnabledImagerViewer(QWidget *parent = 0);
    ~DropEnabledImagerViewer(){}
protected:

    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
};

#endif // DROPENABLEDIMAGERVIEWER_H
