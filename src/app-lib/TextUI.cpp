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

void TextUI::sayGoodBye()
{
    output<<L"\nThank you for your wasted time.";

}

void TextUI::showError(const wstring &message)
{
    output<< L"\n" <<message <<endl;
}

wstring TextUI::getInputLine(const wstring &prompt)
{
    output << prompt + L": ";   //dafür: EXPECT_EQ(outputStream.str(), expectedOutput);      statt prompt + L": ", kann man prompt << L": "
   // return L"";                  //dafür:  EXPECT_TRUE(line.empty());
    wstring line;
    getline(input, line);

    return  line;//Gibt zurück die erste Line vom Eingabestrom (input)
}
