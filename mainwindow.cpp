#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QHeaderView>
#include <QFile>
#include <QMessageBox>
#include <iostream>
#include <QtGlobal>
#include <QtDebug>
#include <QTextStream>

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
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
