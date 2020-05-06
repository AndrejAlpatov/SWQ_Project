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

/*#define NOT_ONLY_WINDOWS
#ifndef NOT_ONLY_WINDOWS
#include <windows.h>
#include <conio.h> //fuer Windows Version
#endif*/

#ifndef PLAYINGFIELD_H
#define PLAYINGFIELD_H

#include<time.h>
#include<iostream>
#include <QString>
#include"TextUI.h"
#include "Tile.h"

using namespace std;

/// Diese Klasse beschreibt ein Feld des Schachbrett
/// Inhaelt drei Getter()
/// The definition of invalid dates will be rejected by throwing
/// an appropriate exception

class PlayingField{

public:
    PlayingField(wistream & is = wcin, wostream & os = wcout);

    void ausgabe();                     //Ausgabe des Bretts
    void start();                       // Start of the game
    void run();                         ///< Start of reading kommands
    int * freiFeldSuche();              //Koordinaten vom freien Feld suchen

    void setAlleFelderBesetzt();        //For Test freiFeldSuche()
    void setEinFeldFrei();              //For Test freiFeldSuche()

private:
    Tile ** SpielFeld;                  //Brett als Zweidimensionales Array
    int richtung;                       ///<Gueltige Werte (0..4)
    wistream & input;                   //for test input stream
    wostream & output;                  //for test output stream
    TextUI ui;                          /// \todo UI&ui NICHT VERGESSEN ZU INITIALISIEREN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    unsigned int zufallZahl();          //Zufallzahlgenerator (2 oder 4) fuer ein freis Feld
    void setWerteAnFelder(int * arr);   //Set Werte an Feld
    void gameOver();                    //Ende des Spiels
    void move();                        //Move
    int onKeyboardPush();               //Bearbeitung des Tastedrucks
    void obFreifeldGibt();              //Ueberpruefung ob mindestens ein Feld frei ist
    void winPruefung();                 //Ueberpruefung ob das Ziel des Spoels schon erreicht ist

};

#endif // PLAYINGFIELD_H
