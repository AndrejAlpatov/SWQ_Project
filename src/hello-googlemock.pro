# Sample qmake project file

TEMPLATE = subdirs
#CONFIG = ordered
SUBDIRS = app-main \
	  app-lib \
          unittest \
	  gmock

app-main.depends = app-lib
unittest.depends = app-lib gmock

OTHER_FILES = ../README.md
