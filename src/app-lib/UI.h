//============================================================================
/// \file
/// \ingroup    g_applib
/// \brief      The interface definition of abstract class UI
/// \details
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================
#ifndef UI_H
#define UI_H
#include <iostream>
#include "string"
using namespace std;

/// Diese Klasse ist für Aufgabe 5.7.4.2 erstellt
//Обязательно запустить erstellen->qmake ausführen иначе не компилируется

class UI{
public:
    virtual void sayWelcome() = 0;                 ///< Outputstream with version number
    virtual void sayGoodBye() = 0;                 ///< Outputstream with Good bye
    virtual void showError(wstring const & message) = 0;
    virtual wstring getInputLine(std::wstring const & prompt) = 0;
    virtual wstring getFilledInputLine(std::wstring const &prompt, std::wstring const &errorMessage) = 0;

    virtual ~UI(){

    }

private:


};

#endif //UI_H
