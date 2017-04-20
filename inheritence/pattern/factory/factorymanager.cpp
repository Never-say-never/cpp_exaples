#include "demo_manager.h"

FactoryManager::FactoryManager()
{
    FactoryEngin *fEngin = new FactoryEngin();
    FactoryShell *fShell = new FactoryShell();

    this->builderBattleShip = new BuilderBattleShip(fShell, fEngin);
    this->builderTransport  = new BuilderTransport(fShell, fEngin);
}

