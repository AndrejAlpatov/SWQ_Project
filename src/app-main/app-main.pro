# qmake project file to build the application

TARGET = helloworld
TEMPLATE = app

QT -= gui

CONFIG += console
CONFIG -= app_bundle

SOURCES += app-main.cpp
OTHER_FILES += appmain.dox
RESOURCES += ../../resources/resources.qrc

DEPENDENCY_LIBRARIES += app-lib         # used in includes.pri
include(../qmake/includes.pri)

