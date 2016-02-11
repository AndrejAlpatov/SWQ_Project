# Sample qmake project file

TEMPLATE = subdirs
#CONFIG = ordered
SUBDIRS = app-lib \
          app-main \
          unittest

app-main.depends = app-lib
unittest.depends = app-lib

OTHER_FILES = ../README.md
