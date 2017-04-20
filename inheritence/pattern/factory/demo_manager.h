#ifndef FACTORYMANAGER_H
#define FACTORYMANAGER_H

#include "spaceship.h"
#include "builder_battleship.h"
#include "builder_transport.h"

class FactoryManager
{
public:
    FactoryManager();

    void runDemo()
    {
        SpaceShip *battleShip = new SpaceShip();
        this->builderBattleShip->build(*battleShip);

        std::cout << std::endl << "Building..." << std::endl;
        battleShip->fly();
    }

private:

    BuilderBattleShip *builderBattleShip;
    BuilderTransport *builderTransport;
};

#endif // FACTORYMANAGER_H
