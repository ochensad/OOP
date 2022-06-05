#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_1_clicked()
{
    qDebug() << "Pressed button 1 in the elevator";
    lift.call(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug() << "Pressed button 2 in the elevator";
    lift.call(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    qDebug() << "Pressed button 3 in the elevator";
    lift.call(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    qDebug() << "Pressed button 4 in the elevator";
    lift.call(4);
}

void MainWindow::on_pushButton_5_clicked()
{
    qDebug() << "Pressed button 5 in the elevator";
    lift.call(4);
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Pressed button on floor 1";
    lift.call(1);
}


void MainWindow::on_pushButton_6_clicked()
{
    qDebug() << "Pressed button on floor 2";
    lift.call(2);
}


void MainWindow::on_pushButton_7_clicked()
{
    qDebug() << "Pressed button on floor 3";
    lift.call(3);
}


void MainWindow::on_pushButton_8_clicked()
{
    qDebug() << "Pressed button on floor 4";
    lift.call(4);
}


void MainWindow::on_pushButton_9_clicked()
{
    qDebug() << "Pressed button on floor 5";
    lift.call(5);
}

