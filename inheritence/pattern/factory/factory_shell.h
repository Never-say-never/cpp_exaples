#ifndef FACTORYSHELL
#define FACTORYSHELL

#include "factory.h"
#include "ispaceship.h"
#include "iostream"

class FactoryShell : public Factory
{
public:
    FactoryShell()
    {

    }

    ~FactoryShell() {}

    // Factory interface
public:

    /**
     * @brief create
     * @return
     */
    IUnit *create(ISpaceShip::Shell T) override
    {
        IUnit *unit;

        switch (T) {
        case ISpaceShip::Shell::HEAVY:
            {
                ShipShell *shell = new ShipShell(600);
                unit = shell;
                std::cout << unit->print() << std::endl;
                break;
            }
        case ISpaceShip::Shell::LIGHT:
            {
                ShipShell *shell = new ShipShell(170);
                unit = shell;
                std::cout << unit->print() << std::endl;
                break;
        }
        default:
            {
                ShipShell *shell = new ShipShell(170);
                unit = shell;
                std::cout << unit->print() << std::endl;
                break;
            }
        }

        return unit;
    }

    // Factory interface
public:
    IUnit *create(ISpaceShip::Engin T) override
    {
        return NULL;
    }
};

#endif // FACTORYSHELL

