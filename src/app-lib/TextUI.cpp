//============================================================================
/// \file
/// \ingroup    g_applib
/// \brief      Contents TestUI implemetetion
/// \details    In this example it's only the simple class CalenadarDate
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================
#include "TextUI.h"
#include "VersionInfo.h"
#include <iostream>

TextUI::TextUI(wistream &is, wostream &os): input(is), output(os)
{
}

void TextUI::sayWelcome()
{
    output << L"Welcome to 2048"<<endl;//ohne "L" geht es auch
    output << L"Version: " << VersionInfo::getVersion().toStdWString()
       << L" (" << VersionInfo::getBuildTag().toStdWString() << ")" << endl;
}
