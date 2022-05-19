QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    draw/drawers/qtdrawer.cpp \
    managers/draw/drawmanager.cpp \
    managers/transform/transformmanager.cpp \
    object/invisible/camera/camera.cpp \
    object/composite/composite.cpp \
    object/visible/model/modelstruct/connect.cpp \
    main.cpp \
    gui/mainwindow.cpp \
    object/visible/model/model.cpp \
    object/visible/model/modelstruct/modelstructure.cpp \
    object/visible/model/modelstruct/point.cpp \
    visitor/drawvisitor.cpp

HEADERS += \
    draw/factory/absgraphfactory.h \
    draw/drawers/basedrawer.h \
    draw/drawers/qtdrawer.h \
    draw/factory/graphsolution.h \
    draw/factory/qtfactory.h \
    exeptions/exeptions.h \
    managers/basemanager.h \
    managers/draw/drawmanager.h \
    managers/transform/transformmanager.h \
    object/invisible/camera/camera.h \
    object/composite/composite.h \
    object/visible/model/modelstruct/connect.h \
    object/invisible/invisibleobject.h \
    gui/mainwindow.h \
    object/visible/model/model.h \
    object/visible/model/modelstruct/modelstructure.h \
    object/object.h \
    object/visible/model/modelstruct/point.h \
    object/visible/visibleobject.h \
    visitor/drawvisitor.h \
    visitor/visitor.h

FORMS += \
    gui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
