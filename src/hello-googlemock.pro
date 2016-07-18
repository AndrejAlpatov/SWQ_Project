# Sample qmake project file

TEMPLATE = subdirs
SUBDIRS = app-main \
	  app-lib \
          unittest \
	  googletest

app-main.depends = app-lib
unittest.depends = app-lib googletest

OTHER_FILES = ../README.md \
    ../LICENSE.txt \
    ../doc/doxygen/Doxyfile \
    ../doc/doxygen/mainpage.dox \
    ../doc/doxygen/license.dox \

