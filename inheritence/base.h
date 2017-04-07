#ifndef BASE
#define BASE

#include <stdio.h>

/**
 * @brief The Base Interface
 */
class Base
{
public:
    virtual void toString() = 0;
    virtual size_t getHash() = 0;

    virtual void valCall() & = 0;
    virtual void valCall() && = 0;

    virtual ~Base() {}

protected:
    size_t hash;
};
#endif // BASE

