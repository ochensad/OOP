#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "command/cameracommands.h"
#include "object/invisible/camera/camera.h"
#include "command/modelcommands.h"
#include "command/cameracommands.h"
#include <memory>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_scene();

    facade = std::make_shared<Facade>(Facade());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setup_scene()
{
    scene = std::shared_ptr<QGraphicsScene>(new QGraphicsScene());

    ui->graphicsView->setScene(scene.get());
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setStyleSheet("QGraphicsView {background-color: white}");

    auto cont = ui->graphicsView->contentsRect();
    scene->setSceneRect(0, 0, cont.width(), cont.height());
    std::shared_ptr<QPen> pen (new QPen(Qt::red));
    std::shared_ptr<AbsGraphFactory> factory(new QtFactory(scene, pen));
    drawer = factory->createGraphics();
}

void MainWindow::update_scene()
{
    drawer->clearScene();

    QString mod = ui->combomodelBox->currentText();

    if (mod == "")
    {
        return;
    }
    int index = ui->combomodelBox->currentIndex();

    DrawSceneCommand draw_command(drawer, index);
    facade->exec(draw_command);
}

void MainWindow::check_cam_exist()
{
    if (SceneManagerCreator().createManager()->getScene()->getCameras().size() == 0)
    {
        std::string msg = "No camera found.";
        throw CameraError(msg);
    }
}

void MainWindow::on_loadButton_clicked()
{
    try
        {
            check_cam_exist();
            std::string filedir = "C:\\Users\\79645\\";
            std::string confdir = "C:\\Users\\79645\\config.txt";

            std::string filename = ui->model_name->text().toStdString();

            std::string file_n = filedir + filename;

            //cout << file_n;

            LoadModelCommand load_command(confdir, file_n);

            facade->exec(load_command);
            this->model_count++;
            ui->combomodelBox->addItem(ui->model_name->text());
        } catch (const CameraError &error)
        {
            QMessageBox::critical(NULL, "Ошибка", "Прежде чем добавлять модель, добавьте хотя бы одну камеру.");
            return;
        } catch (const FileError &error)
        {
            QMessageBox::critical(NULL, "Ошибка", "Что-то не так пошло при загрузке файла...");
            return;
        }

        //update_scene();
}


void MainWindow::on_moveButton_clicked()
{
    try
        {
            double x = ui->dx_Box->value();
            double y = ui->dy_Box->value();
            double z = ui->dz_Box->value();

            QString mod = ui->combomodelBox->currentText();

            if (mod == "")
            {
                QMessageBox::critical(NULL, "Ошибка", "Модель не выбрана");
                return;
            }
            int index = ui->combomodelBox->currentIndex();
            MoveModelCommand move_command(x, y, z, index);
            facade->exec(move_command);
            update_scene();
        } catch (const ModelError &error)
        {
            QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной модели");
            return;
        }
}


void MainWindow::on_rotateButton_clicked()
{
    try
        {
            double x = ui->fx_Box->value();
            double y = ui->fy_Box->value();
            double z = ui->fz_Box->value();


            QString mod = ui->combomodelBox->currentText();

            if (mod == "")
            {
                QMessageBox::critical(NULL, "Ошибка", "Модель не выбрана");
                return;
            }
            int index = ui->combomodelBox->currentIndex();

            RotateModelCommand rotate_command(x, y, z, index);
            facade->exec(rotate_command);
            update_scene();
        } catch (const ModelError &error)
        {
            QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной модели");
            return;
        }
}


void MainWindow::on_scaleButton_clicked()
{
    try
        {
            double x = ui->kx_Box->value();
            double y = ui->ky_Box->value();
            double z = ui->kz_Box->value();

            QString mod = ui->combomodelBox->currentText();

            if (mod == "")
            {
                QMessageBox::critical(NULL, "Ошибка", "Модель не выбрана");
                return;
            }
            int index = ui->combomodelBox->currentIndex();

            ScaleModelCommand scale_command(x, y, z, index);
            facade->exec(scale_command);
            update_scene();
        } catch (const ModelError &error)
        {
            QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной модели");
            return;
        }
}


void MainWindow::on_add_camButton_clicked()
{
    try
        {
            std::string filedir = "C:\\Users\\79645\\";

            std::string filename = ui->cameraname->text().toStdString();

            std::string file_n = filedir + filename;

            std::string confdir = "C:\\Users\\79645\\config.txt";
            LoadCameraCommand load_command(confdir, file_n);

            facade->exec(load_command);
            this->camera_count++;
            ui->combocameraBox->addItem(ui->cameraname->text());
        } catch (const CameraError &error)
        {
            QMessageBox::critical(NULL, "Ошибка", "Прежде чем добавлять модель, добавьте хотя бы одну камеру.");
            return;
        } catch (const FileError &error)
        {
            QMessageBox::critical(NULL, "Ошибка", "Что-то не так пошло при загрузке файла...");
            return;
        }

        //update_scene();
}

void MainWindow::on_pushButton_clicked()
{
    try
        {
            QString mod = ui->combocameraBox->currentText();

            if (mod == "")
            {
                QMessageBox::critical(NULL, "Ошибка", "Камера не выбрана");
                return;
            }
            int index = ui->combocameraBox->currentIndex();

            SetCameraCommand set_command(index);
            facade->exec(set_command);
            update_scene();
        } catch (const CameraError &error)
        {
            QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной модели");
            return;
        }
    update_scene();
}


void MainWindow::on_clear_Button_clicked()
{
    drawer->clearScene();
    int i = 0;
    for(auto obj: SceneManagerCreator().createManager()->getScene()->getObjects()->getObjects())
    {
        RemoveModelCommand remove_command(obj);
        facade->exec(remove_command);
        ui->combomodelBox->removeItem(i);
    }
    update_scene();
}


void MainWindow::on_set_model_button_clicked()
{
    QString mod = ui->combomodelBox->currentText();

    if (mod == "")
    {
        QMessageBox::critical(NULL, "Ошибка", "Модель не выбрана");
        return;
    }
    update_scene();
}


void MainWindow::on_delete_model_button_clicked()
{
    QString mod = ui->combomodelBox->currentText();

    if (mod == "")
    {
        QMessageBox::critical(NULL, "Ошибка", "Модель не выбрана");
        return;
    }
    int index = ui->combomodelBox->currentIndex();
    RemoveModelCommand rem_command(SceneManagerCreator().createManager()->getScene()->getObjects()->getObjects().at(index));
    facade->exec(rem_command);
    ui->combomodelBox->removeItem(index);
    update_scene();
}


void MainWindow::on_pushButton_2_clicked()
{
    QString mod = ui->combocameraBox->currentText();

    if (mod == "")
    {
        QMessageBox::critical(NULL, "Ошибка", "Камера не выбрана");
        return;
    }
    int index = ui->combocameraBox->currentIndex();
    RemoveCameraCommand rem_command(index);
    facade->exec(rem_command);
    ui->combocameraBox->removeItem(index);
    update_scene();
}


void MainWindow::on_move_up_cam_clicked()
{
    QString mod = ui->combocameraBox->currentText();

    if (mod == "")
    {
        QMessageBox::critical(NULL, "Ошибка", "Камера не выбрана");
        return;
    }
    int index = ui->combocameraBox->currentIndex();
    MoveCameraCommand m_command(index, 0, 10);
    facade->exec(m_command);
    update_scene();
}


void MainWindow::on_move_right_cam_clicked()
{
    QString mod = ui->combocameraBox->currentText();

    if (mod == "")
    {
        QMessageBox::critical(NULL, "Ошибка", "Камера не выбрана");
        return;
    }
    int index = ui->combocameraBox->currentIndex();
    MoveCameraCommand m_command(index, -10, 0);
    facade->exec(m_command);
    update_scene();
}


void MainWindow::on_move_left_cam_clicked()
{
    QString mod = ui->combocameraBox->currentText();

    if (mod == "")
    {
        QMessageBox::critical(NULL, "Ошибка", "Камера не выбрана");
        return;
    }
    int index = ui->combocameraBox->currentIndex();
    MoveCameraCommand m_command(index, 10, 0);
    facade->exec(m_command);
    update_scene();
}


void MainWindow::on_move_down_cam_clicked()
{
    QString mod = ui->combocameraBox->currentText();

    if (mod == "")
    {
        QMessageBox::critical(NULL, "Ошибка", "Камера не выбрана");
        return;
    }
    int index = ui->combocameraBox->currentIndex();
    MoveCameraCommand m_command(index, 0, -10);
    facade->exec(m_command);
    update_scene();
}

