#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "treemodel.h"
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
#include <vector>

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

    TreeModel *tm  = new TreeModel("" , NULL);
    ui->treeView->setModel(tm);

    QTextStream inStream(&file);

    while(!inStream.atEnd())
    {
        QString line = inStream.readLine();
        qDebug() << line ;

        QStringList data = line.split(",");
        QVector <QVariant> dd ;

        for(int i =0 ; i < data.size() ; i++)
            dd.append(data[i]);
        TreeItem *ti = new TreeItem( dd , tm->rootItem);

        tm->rootItem->appendChild(ti);

    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


//        for(int i = 0 ; i < data.size() ; i++)
//        {
//            qDebug() << data[i] << " ";
//        }



//        for(int i = 0 ;i < 4 ; i++)
//        {
//            QModelIndex index = model->index(i,0,QModelIndex());
//            model->setData(index , i);
//        }

//QTableView *firstTableView = new QTableView;
//firstTableView->setModel(model);
//mydelegate = new SpinBoxDelegate();
//firstTableView->setItemDelegate(mydelegate);
//firstTableView->show();
