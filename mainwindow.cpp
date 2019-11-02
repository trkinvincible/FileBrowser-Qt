#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DirTreeViewModel_ = new QFileSystemModel(this);
    DirTreeViewModel_->setRootPath("/media/trk/DATA/camera");
    ui->treeView->setModel(DirTreeViewModel_);
    connect(ui->treeView, SIGNAL(clicked(const QModelIndex&)),this, SLOT(on_treeView_clicked(const QModelIndex&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    qDebug() << __FUNCTION__;
    QString currPath = DirTreeViewModel_->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(qobject_cast<QFileSystemModel*>(ui->listView->model())->setRootPath(currPath));
}
