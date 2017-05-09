#ifndef FACTORYMANAGER_H
#define FACTORYMANAGER_H

#include "spaceship.h"
#include "builder_battleship.h"
#include "builder_transport.h"
#include "view/viewspace.h"
#include <QTime>
#include <QTimer>
#include <QObject>

class FactoryManager
{
public:
    FactoryManager();
    ~FactoryManager();

    ViewSpace *v;
    QTimer *timer;

    void runDemo()
    {
        qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

        std::cout << std::endl << "Building..." << std::endl;
        SpaceShip *battleShip = new SpaceShip();
        this->builderBattleShip->build(*battleShip);
        std::cout << std::endl << "Done..." << std::endl;

        std::cout << std::endl << "Fly..." << std::endl;
        battleShip->fly();
        std::cout << std::endl << "Done..." << std::endl;

        // draw space
        this->v = new ViewSpace;
        this->v->setGeometry(100, 100, 840, 840);

        this->v->addShip(battleShip);

        this->v->move(2500, 100);
        this->v->show();

        this->timer = new QTimer();
        QObject::connect(this->timer, SIGNAL(timeout()), this->v->scene, SLOT(advance()));
        this->timer->start(1000 / 10);
    }

private:

    BuilderBattleShip *builderBattleShip;
    BuilderTransport *builderTransport;
};

#endif // FACTORYMANAGER_H
