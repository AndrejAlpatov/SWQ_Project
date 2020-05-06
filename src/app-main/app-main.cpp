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
#include "googletest/gtest/gtest.h"


/// My little main() function.
/// Not much is happening here, it's just a "hello world". We just
/// create a QCoreApplication and a Translator object here and say
/// "hello" (but in the current system locale).
int main( int argc, char ** argv )
{
    QCoreApplication app(argc, argv);


    wistringstream input;
    PlayingField a(input);
    //a.start();
    a.run();

}
