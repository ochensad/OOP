QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    builder/camerabuilder.cpp \
    config/config.cpp \
    draw/drawers/qtdrawer.cpp \
    facade/facade.cpp \
    loader/filecameraloader.cpp \
    loader/fileloader.cpp \
    managers/draw/drawmanager.cpp \
    managers/draw/drawmanagercreator.cpp \
    managers/load/loadmanager.cpp \
    managers/load/loadmanagercreator.cpp \
    managers/scene/scenemanager.cpp \
    managers/scene/scenemanagercreator.cpp \
    managers/transform/transformmanager.cpp \
    builder/modelbuilder.cpp \
    managers/transform/transformmanagercreator.cpp \
    object/invisible/camera/camera.cpp \
    object/composite/composite.cpp \
    object/visible/model/modelstruct/connect.cpp \
    main.cpp \
    gui/mainwindow.cpp \
    object/visible/model/model.cpp \
    object/visible/model/modelstruct/modelstructure.cpp \
    object/visible/model/modelstruct/point.cpp \
    scene/scene.cpp \
    visitor/drawvisitor.cpp

HEADERS += \
    builder/basecamerabuilder.h \
    command/basecommand.h \
    command/cameracommands.h \
    command/scenecommands.h \
    config/config.h \
    facade/facade.h \
    loader/absloadcontroller.h \
    loader/baseloader.h \
    builder/basebuilder.h \
    builder/camerabuilder.h \
    draw/factory/absgraphfactory.h \
    draw/drawers/basedrawer.h \
    draw/drawers/qtdrawer.h \
    draw/factory/graphsolution.h \
    draw/factory/qtfactory.h \
    exeptions/exeptions.h \
    loader/cameraloader.h \
    loader/filecameraloader.h \
    loader/fileloader.h \
    loader/modelloader.h \
    managers/basemanager.h \
    managers/draw/drawmanager.h \
    managers/draw/drawmanagercreator.h \
    managers/load/loadmanager.h \
    managers/load/loadmanagercreator.h \
    managers/scene/scenemanager.h \
    managers/scene/scenemanagercreator.h \
    managers/transform/transformmanager.h \
    builder/modelbuilder.h \
    managers/transform/transformmanagercreator.h \
    command/modelcommands.h \
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
    scene/scene.h \
    visitor/drawvisitor.h \
    visitor/visitor.h

FORMS += \
    gui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


