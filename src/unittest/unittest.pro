# this qmake project file generates the unit test application

TARGET = unit-test
TEMPLATE = app

QT += testlib
QT -= gui

CONFIG += console
CONFIG -= app_bundle    # for Mac users
CONFIG += testcase      # adds make target for 'make check'

HEADERS += \
    Helpers.h

SOURCES += \
    testmain.cpp \
    testVersionInfo.cpp \
    testGoogleTestBehaviour.cpp \
    testGoogleMockBehaviour.cpp

INCLUDEPATH += $$_PRO_FILE_PWD_/../googletest/googlemock/include \
    $$_PRO_FILE_PWD_/../googletest/googletest/include \

DEPENDENCY_LIBRARIES += googletest \    # used in includes.pri
    app-lib
include(../qmake/includes.pri)
