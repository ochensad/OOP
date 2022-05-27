#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsScene>

#include "config/config.h"
#include "draw/factory/graphsolution.h"
#include "facade/facade.h"
#include "loader/baseloader.h"
#include "draw/factory/qtfactory.h"
#include "managers/draw/drawmanagercreator.h"
#include "managers/scene/scenemanagercreator.h"
#include "command/scenecommands.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    const int win_x = 1001;
    const int win_y = 571;

    int model_count = -1;
    int camera_count = -1;

    void update_scene();
    void setup_scene();
    void clear_scene();
    void check_cam_exist();
private slots:
    void on_loadButton_clicked();

    void on_moveButton_clicked();

    void on_rotateButton_clicked();

    void on_scaleButton_clicked();

    void on_add_camButton_clicked();

    void on_pushButton_clicked();

    void on_clear_Button_clicked();

    void on_set_model_button_clicked();

    void on_delete_model_button_clicked();

    void on_pushButton_2_clicked();

    void on_move_up_cam_clicked();

    void on_move_right_cam_clicked();

    void on_move_left_cam_clicked();

    void on_move_down_cam_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<Facade> facade;
    std::shared_ptr<BaseDrawer> drawer;

};
#endif // MAINWINDOW_H
