#ifndef ABSSPACESHIP
#define ABSSPACESHIP

#include "space_objects/ships/ship_shell.h"
#include "space_objects/ships/ship_enging.h"
#include "data_structures.h"
#include "ispaceship.h"
#include <iostream>

class SpaceShip : public ISpaceShip
{
private:
    IUnit *shell;
    IUnit *engin;

    Point *point;

    Point *createDefaultPoint(int x, int y)
    {
        Point defaultPoint(0,0);
        return &defaultPoint;
    }

public:
    SpaceShip():
        shell(),
        engin()
    {
        this->point = this->createDefaultPoint(0,0);
    }

    SpaceShip(int x, int y):
        shell(0),
        engin(0)
    {
        this->point = this->createDefaultPoint(x,y);
    }

    /**
     * @brief setShell
     * @param shell
     */
    void setShell(IUnit *shell) override
    {
        this->shell = shell;
    }

    /**
     * @brief setEnging
     * @param engin
     */
    void setEnging(IUnit *engin) override
    {
        this->engin = engin;
    }

    ~SpaceShip();

    // ISpaceShip interface
public:
    void fly() override
    {
        std::cout << this->shell->print() << std::endl;
        std::cout << this->engin->print() << std::endl;

        this->point->print();
    }
};

#endif // ABSSPACESHIP

