#ifndef BUILDER_BUTTLESHIP
#define BUILDER_BUTTLESHIP

#include "builder.h"
#include "ispaceship.h"
#include "factory_engine.h"
#include "factory_shell.h"

class BuilderBattleShip : public Builder
{
public:
    FactoryShell *factoryShell;
    FactoryEngin *factoryEngin;

    // Builder interface
public:

    BuilderBattleShip(FactoryShell *factoryShell, FactoryEngin *factoryEngin):
        factoryShell(nullptr),
        factoryEngin(nullptr)
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
        return this->factoryEngin->create(ISpaceShip::Engin::SPEED);
    }

    /**
     * @brief configureShell
     * @return
     */
    IUnit* configureShell() override
    {
        return this->factoryShell->create(ISpaceShip::Shell::HEAVY);
    }

    /**
     * @brief build
     * @param ship
     */
    void build(ISpaceShip &ship) override
    {
        // setup space ship enging
        ship.setEnging(this->configureEngin());

        // setup spaceship shell
        ship.setShell(this->configureShell());
    }
};

#endif // BUILDER_BUTTLESHIP

