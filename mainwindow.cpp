#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myObj.name = "My Object";
    myObj.DoSetup(myThrd);
    myObj.moveToThread(&myThrd);

    connect(&myObj, SIGNAL(NumberChanged(int)), this, SLOT(onNumberChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNumberChanged(int i)
{
    ui->label->setText(QString::number(i));
}

void MainWindow::on_pushButton_clicked()
{
    myThrd.start();
}

void MainWindow::on_pushButton_2_clicked()
{
    myObj.stop = true;
}
