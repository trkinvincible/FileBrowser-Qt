#ifndef DRAGABLEGRIDLAYOUT_H
#define DRAGABLEGRIDLAYOUT_H

#include <QWidget>
#include <QListView>
#include <QFileSystemModel>
#include <QUrl>

class DragableGridLayout : public QListView
{
    Q_OBJECT
public:
    DragableGridLayout(QWidget *parent = 0);
    ~DragableGridLayout(){}
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private slots:
    void on_listView_clicked(const QModelIndex &index);

private:
    QFileSystemModel *SubDirGridViewModel_;
    QPoint DragStartPosition_;
    QUrl DraggedFileUrl_;
};

#endif // DRAGABLEGRIDLAYOUT_H
