# qmake project includes for generating binary translation files
#
# NOTE: All paths are relative to the including project files!

TRANSLATIONS += ../resources/translations/de_DE.ts \
                ../resources/translations/fr_FR.ts \
                ../resources/translations/en_US.ts

# Avoid warnings by qmake about non existing *.qm files at the first qmake run.
# Relies on bash, even on Windows ...!
for( tsfile, TRANSLATIONS ) {
    qmfile = $$replace(tsfile,.ts,.qm)
    system( bash -c \'[ \"$$qmfile\" -nt \"$$tsfile\" ] || lrelease \"$$tsfile\" -qm \"$$qmfile\"\' )
}

# Embed compiled resources into application
RESOURCES += ../resources/resources.qrc

# qmake "compiler" to generate *.qm in dependence of *.ts changes
# idea from http://stackoverflow.com/questions/4366898/how-to-specify-auto-generated-resource-files-to-qmake
# and http://www.freehackers.org/thomas/2009/03/10/fixing-qmake-missing-rule-for-ts-qm/
# adapted with modifications acc
QMAKE_EXTRA_COMPILERS += lrelease
lrelease.input = TRANSLATIONS
lrelease.output = ${QMAKE_FILE_PATH}/${QMAKE_FILE_BASE}.qm
lrelease.commands = lrelease ${QMAKE_FILE_IN} -qm ${QMAKE_FILE_PATH}/${QMAKE_FILE_BASE}.qm
lrelease.CONFIG += no_link target_predeps
