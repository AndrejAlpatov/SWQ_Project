//============================================================================
/// \file
/// \ingroup    g_applib
/// \brief
/// \details    In this example it's only the simple class CalenadarDate
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================
#ifndef TEXTUI_H
#define TEXTUI_H
#include <iostream>
#include"UI.h"
using namespace std;

/// Diese Klasse ist füt Aufgabe 5.7 erstellt

class TextUI: public UI{
public:
    TextUI(wistream & is = wcin, wostream & os = wcout);
    void sayWelcome();                 ///< Outputstream with version number
    void sayGoodBye();                 ///< Outputstream with Good bye
    void showError(wstring const & message);
    wstring getInputLine(std::wstring const & prompt);
    wstring getFilledInputLine(std::wstring const &prompt, std::wstring const &errorMessage);

private:
    wistream & input;
    wostream & output;

};

#endif //TEXTUI_H
