# this qmake project file generates the unit test application

TARGET = unit-test
TEMPLATE = app

QT += testlib
QT -= gui

CONFIG += console
CONFIG -= app_bundle    # for Mac users
CONFIG += testcase      # adds make target for 'make check'

HEADERS += \
    AutoTest.h \
    Helpers.h

SOURCES += \
    testmain.cpp \
    testVersionInfo.cpp \
    testQttestBehaviour.cpp

DEPENDENCY_LIBRARIES += app-lib         # used in includes.pri
include(../qmake/includes.pri)
