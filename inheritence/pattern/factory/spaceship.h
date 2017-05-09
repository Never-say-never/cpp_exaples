#ifndef ABSSPACESHIP
#define ABSSPACESHIP

#include "space_objects/ships/ship_shell.h"
#include "space_objects/ships/ship_enging.h"
#include "data_structures.h"
#include "ispaceship.h"
#include <iostream>
#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOption>
#include <math.h>

class SpaceShip : public ISpaceShip, public QGraphicsItem
{

private:
    IUnit *shell;
    IUnit *engin;

    Point point;
    QColor color;
    int rad;

    Point createDefaultPoint(int x, int y)
    {
        Point defaultPoint;
        return defaultPoint;
    }

public:

    SpaceShip():
        shell(nullptr),
        engin(nullptr),
        point(),
        color(qrand() % 256, qrand() % 256, qrand() % 256),
        rad(10)
    {
        this->point = this->createDefaultPoint(10,10);
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

    /**
     * @brief getPoint
     * @return
     */
    Point getPoint()
    {
        return this->point;
    }

    ~SpaceShip() {}

    // ISpaceShip interface
public:
    void fly() override
    {
        std::cout << this->shell->print() << std::endl;
        std::cout << this->engin->print() << std::endl;
        std::cout << this->point.x  << " - " << this->point.y << std::endl;
    }

    // QGraphicsItem interface
public:
    QRectF boundingRect() const Q_DECL_OVERRIDE
    {
        return QRectF(-18 - this->rad, -22 - this->rad,
                      36 + this->rad, 60 + this->rad);
    }

    QPainterPath shape() const Q_DECL_OVERRIDE
    {
        QPainterPath path;
        path.addRect(-10, -20, 20, 40);
        return path;
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) Q_DECL_OVERRIDE
    {
        // Body
        painter->setBrush(color);
        painter->drawEllipse(-10, -20, 20, 40);

        // Eyes
        painter->setBrush(Qt::white);
        painter->drawEllipse(-10, -17, 8, 8);
        painter->drawEllipse(2, -17, 8, 8);

        // Nose
        painter->setBrush(Qt::black);
        painter->drawEllipse(QRectF(-2, -22, 4, 4));

        // Tail
        QPainterPath path(QPointF(0, 20));
        path.cubicTo(-5, 22, -5, 22, 0, 25);
        path.cubicTo(5, 27, 5, 32, 0, 30);
        path.cubicTo(-5, 32, -5, 42, 0, 35);
        painter->setBrush(Qt::NoBrush);
        painter->drawPath(path);
    }

protected:
    bool back;
    void advance(int step) Q_DECL_OVERRIDE
    {
        if(!step)
            return;

        std::cout << "next : " << std::endl;
        std::cout << "rotation : " << rotation() << std::endl;
        std::cout << "pos [ " << pos().x() << "," << pos().y()  << " ]" << std::endl;

        if(pos().x() <= 0 ) {
            std::cout << "board < x" << std::endl;
            setPos(mapToParent(5, 0));

        } else if(pos().x() >= 100 ) {
            std::cout << "board > x" << std::endl;
            setPos(mapToParent(0, 5));

        } else {
            setPos(mapToParent(5, 0));
        }
    }
};

#endif // ABSSPACESHIP

