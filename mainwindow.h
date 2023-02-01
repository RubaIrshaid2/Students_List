#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "spinboxdelegate.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ReadStudentsFile();

private:
    Ui::MainWindow *ui;
    SpinBoxDelegate *mydelegate ;


};
#endif // MAINWINDOW_H
