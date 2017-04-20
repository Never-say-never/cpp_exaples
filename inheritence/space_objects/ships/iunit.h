#ifndef IUNIT
#define IUNIT

#include "string"

class IUnit
{
public:
    virtual ~IUnit() {}
    virtual std::string print() = 0;
};

#endif // IUNIT

