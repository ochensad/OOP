/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QPushButton *TurnButton;
    QDoubleSpinBox *doubleSpinBox_fz;
    QDoubleSpinBox *doubleSpinBox_fy;
    QDoubleSpinBox *doubleSpinBox_fx;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *download_figure_button;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_kx;
    QDoubleSpinBox *doubleSpinBox_ky;
    QDoubleSpinBox *doubleSpinBox_kz;
    QPushButton *pushButton_zoom;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_dx;
    QDoubleSpinBox *doubleSpinBox_dy;
    QDoubleSpinBox *doubleSpinBox_dz;
    QPushButton *pushButton_move;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 650);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 261, 661));
        QPalette palette;
        frame->setPalette(palette);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        TurnButton = new QPushButton(frame);
        TurnButton->setObjectName(QString::fromUtf8("TurnButton"));
        TurnButton->setGeometry(QRect(30, 200, 201, 31));
        doubleSpinBox_fz = new QDoubleSpinBox(frame);
        doubleSpinBox_fz->setObjectName(QString::fromUtf8("doubleSpinBox_fz"));
        doubleSpinBox_fz->setGeometry(QRect(90, 160, 131, 22));
        doubleSpinBox_fy = new QDoubleSpinBox(frame);
        doubleSpinBox_fy->setObjectName(QString::fromUtf8("doubleSpinBox_fy"));
        doubleSpinBox_fy->setGeometry(QRect(90, 130, 131, 22));
        doubleSpinBox_fx = new QDoubleSpinBox(frame);
        doubleSpinBox_fx->setObjectName(QString::fromUtf8("doubleSpinBox_fx"));
        doubleSpinBox_fx->setGeometry(QRect(90, 100, 131, 22));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 100, 21, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 130, 21, 21));
        label_2->setFont(font);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 160, 21, 21));
        label_3->setFont(font);
        download_figure_button = new QPushButton(frame);
        download_figure_button->setObjectName(QString::fromUtf8("download_figure_button"));
        download_figure_button->setGeometry(QRect(29, 20, 201, 31));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 60, 111, 31));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        label_4->setFont(font1);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 240, 171, 31));
        label_5->setFont(font1);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 280, 21, 16));
        label_6->setFont(font);
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 310, 37, 16));
        label_7->setFont(font);
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(50, 340, 31, 21));
        label_8->setFont(font);
        doubleSpinBox_kx = new QDoubleSpinBox(frame);
        doubleSpinBox_kx->setObjectName(QString::fromUtf8("doubleSpinBox_kx"));
        doubleSpinBox_kx->setGeometry(QRect(90, 280, 131, 22));
        doubleSpinBox_ky = new QDoubleSpinBox(frame);
        doubleSpinBox_ky->setObjectName(QString::fromUtf8("doubleSpinBox_ky"));
        doubleSpinBox_ky->setGeometry(QRect(90, 310, 131, 22));
        doubleSpinBox_kz = new QDoubleSpinBox(frame);
        doubleSpinBox_kz->setObjectName(QString::fromUtf8("doubleSpinBox_kz"));
        doubleSpinBox_kz->setGeometry(QRect(90, 340, 131, 22));
        pushButton_zoom = new QPushButton(frame);
        pushButton_zoom->setObjectName(QString::fromUtf8("pushButton_zoom"));
        pushButton_zoom->setGeometry(QRect(30, 380, 201, 31));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(90, 420, 121, 31));
        label_9->setFont(font1);
        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(50, 462, 37, 20));
        label_10->setFont(font);
        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(50, 490, 37, 21));
        label_11->setFont(font);
        label_12 = new QLabel(frame);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(50, 521, 37, 21));
        label_12->setFont(font);
        doubleSpinBox_dx = new QDoubleSpinBox(frame);
        doubleSpinBox_dx->setObjectName(QString::fromUtf8("doubleSpinBox_dx"));
        doubleSpinBox_dx->setGeometry(QRect(90, 460, 131, 22));
        doubleSpinBox_dy = new QDoubleSpinBox(frame);
        doubleSpinBox_dy->setObjectName(QString::fromUtf8("doubleSpinBox_dy"));
        doubleSpinBox_dy->setGeometry(QRect(90, 490, 131, 22));
        doubleSpinBox_dz = new QDoubleSpinBox(frame);
        doubleSpinBox_dz->setObjectName(QString::fromUtf8("doubleSpinBox_dz"));
        doubleSpinBox_dz->setGeometry(QRect(90, 520, 131, 22));
        pushButton_move = new QPushButton(frame);
        pushButton_move->setObjectName(QString::fromUtf8("pushButton_move"));
        pushButton_move->setGeometry(QRect(30, 560, 201, 31));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(265, 1, 731, 621));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        TurnButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214 \321\204\320\270\320\263\321\203\321\200\321\203", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Fx", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Fy", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Fz", nullptr));
        download_figure_button->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\320\270 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "kx", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "ky", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "kz", nullptr));
        pushButton_zoom->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\204\320\270\320\263\321\203\321\200\321\203", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "dx", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "dy", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "dz", nullptr));
        pushButton_move->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270 \321\204\320\270\320\263\321\203\321\200\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
