#include "dragablegridlayout.h"
#include <QDrag>
#include <QMimeData>
#include <QDebug>
#include <QMouseEvent>
#include <QApplication>

DragableGridLayout::DragableGridLayout(QWidget *parent)
    : QListView(parent)
{
    SubDirGridViewModel_ = new QFileSystemModel(this);
    SubDirGridViewModel_->setRootPath(QDir::rootPath());
    QStringList image_file_ext;
    image_file_ext << "*.jpg" << "*.bmp" << "*.png";
    SubDirGridViewModel_->setNameFilters(std::move(image_file_ext));
    SubDirGridViewModel_->setNameFilterDisables(true);
    setModel(SubDirGridViewModel_);
    connect(this, SIGNAL(clicked(const QModelIndex&)),this, SLOT(on_listView_clicked(const QModelIndex&)));
}

void DragableGridLayout::on_listView_clicked(const QModelIndex &index)
{
    qDebug() << __FUNCTION__;
    DraggedFilePath_ = SubDirGridViewModel_->filePath(index);
    DraggedImg_ = QPixmap(SubDirGridViewModel_->filePath(index));
}

void DragableGridLayout::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        DragStartPosition_ = event->pos();
    }
    QListView::mousePressEvent(event);
}

void DragableGridLayout::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << __FUNCTION__;
    if (!(event->buttons() & Qt::LeftButton))
        return;
    if ((event->pos() - DragStartPosition_).manhattanLength()
         < QApplication::startDragDistance())
        return;

    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    mimeData->setText(DraggedFilePath_);
    drag->setMimeData(mimeData);
    drag->setPixmap(DraggedImg_);

    Qt::DropAction dropAction = drag->exec();
}
