//============================================================================
/// \file
/// \ingroup    g_applib
/// \brief      Contains the Tile definition
/// \details    In this example it's only the simple class CalenadarDate
/// \copyright  GNU General Public License (GPL) Version 3
//============================================================================
#ifndef TILE_H
#define TILE_H
#include <QString>

/// Diese Klasse beschreibt ein Feld des Schachbrett
/// Inhaelt drei Getter()

class Tile{
public:
    Tile(bool frei=true, unsigned int wert=0);

    bool getFrei();
    int getWert();

    void setWert(unsigned int wert);
    void setFrei(bool freiWert);

private:
    bool frei;          ///<Valid argument true or false
    int wert;           ///<Valid argument from 0 to 2048

};

#endif // TILE_H
