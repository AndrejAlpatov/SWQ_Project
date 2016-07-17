# Sample qmake project file

TEMPLATE = subdirs
#CONFIG = ordered
SUBDIRS = app-main \
	  app-lib \
          unittest \
	  googletest

app-main.depends = app-lib
unittest.depends = app-lib googletest

OTHER_FILES = ../README.md \
    ../doc/doxygen/Doxyfile \
    ../doc/doxygen/mainpage.dox \
    ../doc/doxygen/license.dox \

TRANSLATIONS += ../resources/translations/de_DE.ts \
                ../resources/translations/fr_FR.ts \
		../resources/translations/en_US.ts

OTHER_FILES += $$TRANSLATIONS
