#ifndef ISPACESHIP
#define ISPACESHIP

#include "space_objects/ships/ship_enging.h"
#include "space_objects/ships/ship_shell.h"

class ISpaceShip
{
public:
    enum Shell { HEAVY, LIGHT };
    enum Engin { SPEED, POWERFUL };

    virtual void fly() = 0;

    virtual void setShell(IUnit *shell) = 0;
    virtual void setEnging(IUnit *engin) = 0;
};

#endif // ISPACESHIP

