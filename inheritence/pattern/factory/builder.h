#ifndef BUILDER
#define BUILDER

#include "ispaceship.h"
#include "space_objects/ships/ishipenging.h"
#include "space_objects/ships/ishipshell.h"

class Builder
{
public:
    virtual IUnit* configureEngin() = 0;
    virtual IUnit* configureShell() = 0;
    virtual void build(ISpaceShip &ship) = 0;
};

#endif // BUILDER

