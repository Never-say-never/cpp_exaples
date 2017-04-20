#ifndef ISHIPSHELL
#define ISHIPSHELL

#include "space_objects/ships/iunit.h"

class IShipShell : public IUnit
{
public:
    virtual int getHitPoints() = 0;
};

#endif // ISHIPSHELL
