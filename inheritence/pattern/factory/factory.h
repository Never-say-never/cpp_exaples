#ifndef FACTORY_H
#define FACTORY_H

#include "space_objects/ships/iunit.h"
#include "ispaceship.h"

class Factory
{
public:
    Factory();

    virtual IUnit* create(ISpaceShip::Engin T) = 0;
    virtual IUnit* create(ISpaceShip::Shell T) = 0;

};

#endif // FACTORY_H
