#ifndef ISHIPENGING
#define ISHIPENGING

#include "space_objects/ships/iunit.h"

class IShipEnging : public IUnit
{
public:
    virtual int getPower() = 0;
    virtual float getSpeed() = 0;
    virtual std::string print() = 0;
};

#endif // ISHIPENGING

