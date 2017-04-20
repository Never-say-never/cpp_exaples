#ifndef ABSBASE_H
#define ABSBASE_H

#include <base.h>
#include <stdio.h>
#include <string>
#include <iostream>

class AbsBase : public Base
{
public:

    AbsBase()
    {
        hash = (size_t) this;
    }

    void valCall() & override
    {
        std::cout << "valCall() &" << std::endl;
    }

    void valCall() && override
    {
        std::cout << "valCall() &&" << std::endl;
    }

protected:

    virtual std::string gerDataReversCopy() = 0;
};

#endif // ABSBASE_H
