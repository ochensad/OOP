#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "error_code.h"

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 590

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    error_code_t draw(void);
    void on_download_figure_button_clicked();

    void on_TurnButton_clicked();

    void on_pushButton_zoom_clicked();

    void on_pushButton_move_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
