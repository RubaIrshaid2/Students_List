#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QHeaderView>
#include <QFile>
#include <QMessageBox>
#include <iostream>
#include <QtGlobal>
#include <QtDebug>
#include <QTextStream>
#include <vector>
#include <QStringListModel>
#include <QListView>
#include <QTableView>
#include <QStandardItemModel>

using namespace std ;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ReadStudentsFile();
}


void MainWindow::ReadStudentsFile()
{
    QFile file(":/students.txt");

    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"Warning","File not found");
        return ;
    }

    QTextStream inStream(&file);

    while(!inStream.atEnd())
    {
        QString line = inStream.readLine();
        qDebug() << line ;
        QStringList data = line.split(",");

//        for(int i = 0 ; i < data.size() ; i++)
//        {
//            qDebug() << data[i] << " ";
//        }

        QAbstractItemModel *model = new QStringListModel(data) ;
        //QAbstractItemModel *model = new QStandardItemModel(4,1,this);



//        for(int i = 0 ;i < 4 ; i++)
//        {
//            QModelIndex index = model->index(i,0,QModelIndex());
//            model->setData(index , i);
//        }


        QTableView *firstTableView = new QTableView;
        firstTableView->setModel(model);
        mydelegate = new SpinBoxDelegate();
        firstTableView->setItemDelegate(mydelegate);
        firstTableView->show();

    }


}


MainWindow::~MainWindow()
{
    delete ui;
}
