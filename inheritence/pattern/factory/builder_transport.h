#ifndef BUILDER_TRANSPORT
#define BUILDER_TRANSPORT

#include "builder.h"
#include "ispaceship.h"
#include "factory_engine.h"
#include "factory_shell.h"

class BuilderTransport : public Builder
{
public:
    FactoryShell *factoryShell;
    FactoryEngin *factoryEngin;

// Builder interface
public:

    BuilderTransport(FactoryShell *factoryShell, FactoryEngin *factoryEngin):
        factoryShell(0),
        factoryEngin(0)
    {
        this->factoryEngin = factoryEngin;
        this->factoryShell = factoryShell;
    }

    /**
     * @brief configureEngin
     * @return
     */
    IUnit* configureEngin() override
    {
        return this->factoryEngin->create(ISpaceShip::Engin::POWERFUL);
    }

    /**
     * @brief configureShell
     * @return
     */
    IUnit* configureShell() override
    {
        return this->factoryShell->create(ISpaceShip::Shell::LIGHT);
    }

    /**
     * @brief build
     * @param ship
     */
    void build(ISpaceShip &ship) override
    {
        // setup space ship enging
        IUnit* u = this->configureEngin();
        ship.setEnging(u);

        // setup spaceship shell
        ship.setShell(this->configureShell());
    }

};

#endif // BUILDER_TRANSPORT

