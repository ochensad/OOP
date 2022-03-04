#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "action.h"
#include "draw.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setStyleSheet("QGraphicsView {background-color: white}");

    scene->setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}

MainWindow::~MainWindow()
{
    request_t request;
    request.action = QUIT;
    switch_action(request);
    delete ui;
}


error_code_t MainWindow::draw(void)
{
    canvas_t canvas;
    canvas.scene = ui->graphicsView->scene();
    canvas.width = canvas.scene->width();
    canvas.height = canvas.scene->height();

    request_t request;
    request.action = DRAW;
    request.canvas = canvas;

    return switch_action(request);
}

void MainWindow::on_download_figure_button_clicked()
{
    request_t request;
    request.action = DOWNLOAD;
    request.filename = "data.txt";

    error_code_t er = switch_action(request);
    if (er)
    {
        error_message(er);
        return;
    }
    er = draw();
    if (er)
        error_message(er);
}


void MainWindow::on_TurnButton_clicked()
{
    request_t request;
    request.action = TURN;

    request.turn.f_x = ui->doubleSpinBox_fx->value();
    request.turn.f_y = ui->doubleSpinBox_fy->value();
    request.turn.f_z = ui->doubleSpinBox_fz->value();

    error_code_t er = switch_action(request);
    if (er)
    {
        error_message(er);
        return;
    }

    er = draw();
    if (er)
        error_message(er);
}


void MainWindow::on_pushButton_zoom_clicked()
{
    request_t request;
    request.action = ZOOM;

    request.zoom.kx = ui->doubleSpinBox_kx->value();
    request.zoom.ky = ui->doubleSpinBox_ky->value();
    request.zoom.kz = ui->doubleSpinBox_kz->value();

    error_code_t er = switch_action(request);
    if (er)
    {
        error_message(er);
        return;
    }
    er = draw();
    if (er)
        error_message(er);
}


void MainWindow::on_pushButton_move_clicked()
{
    request_t request;
    request.action = MOVE;

    request.move.dx = ui->doubleSpinBox_dx->value();
    request.move.dy = ui->doubleSpinBox_dy->value();
    request.move.dz = ui->doubleSpinBox_dz->value();

    error_code_t er = switch_action(request);
    if (er)
    {
        error_message(er);
        return;
    }
    er = draw();
    if (er)
        error_message(er);
}

