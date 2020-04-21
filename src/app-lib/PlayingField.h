//============================================================================
/// \file
/// \ingroup    g_applib
/// \brief      PlayingFeld class
/// \details    In this file is playing field header file
/// \copyright  GNU General Public License (GPL) Version 3
/// \todo Destructor soll noch geschrieben werden
/// \todo Ausgabefunktion muss noch modifiziert werden
/// \todo Ausgabefunktion muss noch modifiziert werden
/// \todo winFruefung() Funktion muss noch modifiziert werden
/// \todo gameOver() muss noch modifiziert werden
/// \todo Noch einmal alle vorherige Kommentare ueberpruefen (auf Russisch loeschen)
//============================================================================
#ifndef PLAYINGFIELD_H
#define PLAYINGFIELD_H
#include "Tile.h"
#include<time.h>
#include<iostream>
//#include <windows.h>
#include <conio.h>
#include <QString>

using namespace std;

/// Diese Klasse beschreibt ein Feld des Schachbrett
/// Inhaelt drei Getter()
/// The definition of invalid dates will be rejected by throwing
/// an appropriate exception

class PlayingField{

public:
    PlayingField();
    void ausgabe();                     //Ausgabe des Bretts
    void start();

    void setAlleFelderBesetzt();        //For Test freiFeldSuche()
    void setEinFeldFrei();              //For Test freiFeldSuche()

    int * freiFeldSuche();              //Koordinaten vom freien Feld suchen

private:
    Tile ** SpielFeld;//Brett als Zweidimensionales Array
    int richtung;     ///<Gueltige Werte (0..4)

    unsigned int zufallZahl();          //Zufallzahlgenerator (2 oder 4) fuer ein freis Feld
    void setWerteAnFelder(int * arr);   //Set Werte an Feld
    void gameOver();                    //Ende des Spiels
    void move();
    int onKeyboardPush();
    void obFreifeldGibt();
    void winPruefung();

};

#endif // PLAYINGFIELD_H
