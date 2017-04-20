#ifndef FACTORYENGIN
#define FACTORYENGIN

#include "factory.h"
#include "ispaceship.h"
#include "iostream"

class FactoryEngin : public Factory
{
public:
    FactoryEngin()
    {

    }

    ~FactoryEngin() {}

    // Factory interface
public:
    /**
     * @brief create
     * @return
     */
    IUnit *create(ISpaceShip::Engin T) override
    {
        IUnit *unit;

        switch (T) {
        case ISpaceShip::Engin::POWERFUL:
            {
                ShipEnging *engin = new ShipEnging(100, 10.0f);
                unit = engin;
                std::cout << unit->print() << std::endl;
                break;
            }
        case ISpaceShip::Engin::SPEED:
            {
                ShipEnging *engin = new ShipEnging(140, 12.0f);
                unit = engin;
                std::cout << unit->print() << std::endl;
                break;
            }
        default:
            {
                ShipEnging *engin = new ShipEnging(100, 10.0f);
                unit = engin;
                std::cout << unit->print() << std::endl;
                break;
            }
        }

        return unit;
    }

    IUnit *create(ISpaceShip::Shell T) override
    {
        return NULL;
    }
};

#endif // FACTORYENGIN

