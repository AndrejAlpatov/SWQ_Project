#include "Tile.h"
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
        throw std::invalid_argument("Wert is ausserhalb Gueltigkeitsbereich");
    }
    this->wert=wert;
}

void Tile::setFrei(bool freiWert)
{
    frei=freiWert;
}
