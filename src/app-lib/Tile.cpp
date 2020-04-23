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
    this->wert=wert;
}

void Tile::setFrei(bool freiWert)
{
    frei=freiWert;
}
