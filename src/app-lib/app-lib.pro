# qmake project file to build the static library app-lib

include(../qmake/common.pri)
include(../qmake/version.pri)

QT -= gui
TARGET = app-lib
TEMPLATE = lib
CONFIG += staticlib

HEADERS += app-lib.h \
    PlayingField.h \
    TextUI.h \
    Tile.h \
    VersionInfo.h \

SOURCES += \
    PlayingField.cpp \
    TextUI.cpp \
    Tile.cpp \
    VersionInfo.cpp \

OTHER_FILES += applib.dox

# Currently qmake (version 3.0) does not remove a library
# target if the destination directory is not the build directory,
# so we try to add this. Unfortunately it may be non-platform-portable
# as we need to guess the real filename.
# See target 'distclean' in build/app-lib/Makefile
QMAKE_DISTCLEAN += $${DESTDIR}/$${QMAKE_PREFIX_STATICLIB}$${TARGET}.$${QMAKE_EXTENSION_STATICLIB}
