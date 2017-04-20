#ifndef SHIP_SHELL
#define SHIP_SHELL

#include <QString>
#include "space_objects/ships/ishipshell.h"

class ShipShell : public IShipShell
{
private:
    int hitPoints;

public:
    ShipShell(const int& hitPoints)
    {
        this->hitPoints = hitPoints;
    }

    ~ShipShell() {}

    // IShipShell interface
public:
    int getHitPoints() override
    {
        return this->hitPoints;
    }

    // IUnit interface
public:
    std::string print() override
    {
        QString str("ShipEnging{");
        str.append("hitPoints:" + QString::number(this->hitPoints));
        str.append("}");

        return str.toStdString();
    }
};

#endif // SHIP_SHELL

