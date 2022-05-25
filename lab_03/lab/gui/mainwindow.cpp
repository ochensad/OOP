#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "command/cameracommands.h"
#include "object/invisible/camera/camera.h"
#include "command/modelcommands.h"
#include "command/cameracommands.h"
#include <memory>
#include "loader/filecameraloader.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->registration();
    ui->graphicsView->setScene(scene.get());

    auto b = make_shared<Camera>() ;
    SceneManagerCreator().createManager()->getScene()->addCamera(b);

    SetCameraCommand com(0);
    facade->exec(com);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::unique_ptr<AbsGraphFactory> MainWindow::createQtDrawerCreator()
{
    scene = std::shared_ptr<QGraphicsScene>(new QGraphicsScene());
    std::shared_ptr<QPen> pen (new QPen(Qt::red));
    //std::shared_ptr<QBrush> brush (new QBrush(Qt::white));

    return std::unique_ptr<AbsGraphFactory>(new QtFactory(scene, pen));
}

void MainWindow::registration()
{
    std::string configName = "C:\\Users\\79645\\config.txt";

    GraphLibConfig conf(configName);
    conf.readConfig();
    std::string ls = conf.getLoadSource();
    std::string fr = conf.getFrame();
    cout << fr;

    GraphSolution graphicsSolution;
    graphicsSolution.registration("qt", &MainWindow::createQtDrawerCreator);

    std::shared_ptr<AbsGraphFactory>factory(graphicsSolution.create(this, fr));
    drawer = factory->createGraphics();

    if (ls != "file")
    {
        std::string s = "Неизвестный загрузчик";
        throw FileError(s);
    }

    loader = std::make_shared<FileLoader>();
    loader_cam = std::make_shared<FileCameraLoader>();
}

void MainWindow::update_scene()
{
    drawer->clearScene();

    for(auto obj: SceneManagerCreator().createManager()->getScene()->getObjects()->getObjects())
    {
        DrawSceneCommand draw_command(drawer, obj);
        facade->exec(draw_command);
    }
}

void MainWindow::on_loadButton_clicked()
{
    try
        {
            std::string filedir = "C:\\Users\\79645\\";

            std::string filename = ui->model_name->text().toStdString();

            std::string file_n = filedir + filename;

            cout << file_n;

            LoadModelCommand load_command(loader, file_n);

            facade->exec(load_command);
            this->model_count++;
            ui->combomodelBox->addItem(QString::fromStdString(to_string(model_count)));
        } catch (const CameraError &error)
        {
            QMessageBox::critical(NULL, "Ошибка", "Прежде чем добавлять модель, добавьте хотя бы одну камеру.");
            return;
        } catch (const FileError &error)
        {
            QMessageBox::critical(NULL, "Ошибка", "Что-то не так пошло при загрузке файла...");
            return;
        }

        update_scene();
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
            int index = atoi(mod.toStdString().c_str());
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
            int index = atoi(mod.toStdString().c_str());

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
            int index = atoi(mod.toStdString().c_str());

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

            cout << file_n;

            LoadCameraCommand load_command(loader_cam, file_n);

            facade->exec(load_command);
            this->camera_count++;
            ui->combocameraBox->addItem(QString::fromStdString(to_string(camera_count)));
        } catch (const CameraError &error)
        {
            QMessageBox::critical(NULL, "Ошибка", "Прежде чем добавлять модель, добавьте хотя бы одну камеру.");
            return;
        } catch (const FileError &error)
        {
            QMessageBox::critical(NULL, "Ошибка", "Что-то не так пошло при загрузке файла...");
            return;
        }

        update_scene();
}


void MainWindow::on_pushButton_2_clicked()
{
    drawer->clearScene();
    int i = 0;
    for(auto obj: SceneManagerCreator().createManager()->getScene()->getObjects()->getObjects())
    {
        RemoveModelCommand remove_command(obj);
        facade->exec(remove_command);
        ui->combomodelBox->removeItem(i);
    }
}


void MainWindow::on_pushButton_clicked()
{
    try
        {
            QString mod = ui->combocameraBox->currentText();

            if (mod == "")
            {
                QMessageBox::critical(NULL, "Ошибка", "Модель не выбрана");
                return;
            }
            int index = atoi(mod.toStdString().c_str());

            SetCameraCommand set_command(index);
            facade->exec(set_command);
            update_scene();
        } catch (const CameraError &error)
        {
            QMessageBox::critical(NULL, "Ошибка", "Не загружено ни одной модели");
            return;
        }
}

