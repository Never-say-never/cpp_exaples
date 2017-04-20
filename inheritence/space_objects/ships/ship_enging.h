#ifndef SHIP_ENGING
#define SHIP_ENGING

#include <QString>
#include "space_objects/ships/ishipenging.h"

class ShipEnging : public IShipEnging
{
private:
    int power;
    float speed;

public:

    ShipEnging(const int& power, const float& speed)
    {
        this->power = power;
        this->speed = speed;
    }

    ~ShipEnging() {}

    // IShipEnging interface
public:
    int getPower() override
    {
        return this->power;
    }

    float getSpeed() override
    {
        return this->speed;
    }

    // IUnit interface
public:
    std::string print() override
    {
        QString str("ShipEnging{");
        str.append("power:" + QString::number(this->power) + ", ");
        str.append("speed:" + QString::number(this->speed));
        str.append("}");

        return str.toStdString();
    }
};

#endif // SHIP_ENGING

