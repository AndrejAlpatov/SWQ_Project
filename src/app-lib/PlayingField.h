//============================================================================
/// \file
/// \ingroup    g_applib
/// \brief      Contains the application library  interface definition.
/// \details    In this example it's playing field header file
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================
#ifndef PLAYINGFIELD_H
#define PLAYINGFIELD_H
#include "Tile.h"
#include<time.h>
#include<iostream>
#include <windows.h>
#include <conio.h>
#include <QString>

using namespace std;

/// Diese Klasse beschreibt ein Feld des Schachbrett
/// Inhaelt drei Getter()
/// The CalenderDate takes care of correct date entry
/// The definition of invalid dates will be rejected by throwing
/// an appropriate exception

class PlayingField{

public:
    PlayingField();
    void ausgabe();                     //Ausgabe des Bretts

private:
    Tile ** SpielFeld;//Brett als Zweidimensionales Array
    int richtung;     //Gueltige Werte (0..4)

    unsigned int zufallZahl();          //Zufallzahlgenerator (2 oder 4) fuer ein freis Feld
    int * freiFeldSuche();              //Koordinaten vom freien Feld suchen
    void setWerteAnFelder(int * arr);   //Set Werte an Feld
    void gameOver();                    //Ende des Spiels
    void move();
    int onKeyboardPush();
    void obFreifeldGibt();
    void winPruefung();

};

#endif // PLAYINGFIELD_H
