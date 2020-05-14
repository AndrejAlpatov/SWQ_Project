#include "Tile.h"
using namespace std;

Tile:: Tile(bool frei, unsigned int wert)
{
    this->frei=frei;
    this->wert=wert;
}

bool Tile::getFrei()
{
    return frei;
}

int Tile::getWert()
{
    return wert;
}

void Tile::setWert(unsigned int wert)
{
    if(wert>2048){
        throw invalid_argument("Wert is ausserhalb Gueltigkeitsbereich");
    }
    this->wert=wert;
}

void Tile::setFrei(bool freiWert)
{
    frei=freiWert;
}
