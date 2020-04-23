//============================================================================
/// \file
/// \ingroup    g_main
/// \brief      Contains the application's main function.
/// \details    In this file, a 2048 game is launched with fully implemented game logic
///
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================

#include "app-lib/app-lib.h"
#include <QCoreApplication>
#include <QTranslator>
#include <QLocale>
#include <iostream>
using namespace std;

/// Install Translator if possible.
/// This little function keeps main() better readable.
/// Search the Qt Creator Help for the section "Writing Source Code for Translation".
void installTranslator(QCoreApplication & app, QTranslator & translator)
{
    QString localeName = QLocale::system().name();

    if( ! translator.load(":/translations/" + localeName) ) {
        cerr << "Sorry, could not load translation for <"
             << localeName.toStdString() << ">" << endl;
        return;
    }

    if( ! app.installTranslator(&translator) ) {
        cerr << "Sorry, could not install translator for <"
             << localeName.toStdString() << ">" << endl;
    }
}

/// Our little main() function.
/// Not much is happening here, it's just a "hello world". We just
/// create a QCoreApplication and a Translator object here and say
/// "hello" (but in the current system locale).
int main( int argc, char ** argv )
{
    QCoreApplication app(argc, argv);
    QTranslator translator;

    installTranslator(app, translator);

    QString hello = QObject::tr("Hello Application World!");
   // cout <<  hello.toStdString() << endl
      //    << "Version: " << VersionInfo::getVersion().toStdString()
      //    << " (" << VersionInfo::getBuildTag().toStdString() << ")" << endl;
    //cout << "Branch: " << VersionInfo::getBranchName().toStdString() << endl;

    PlayingField a;
    a.start();

}
