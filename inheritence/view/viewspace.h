#ifndef VIEWSPACE_H
#define VIEWSPACE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include "pattern/factory/spaceship.h"

class DiagramScene;
class QGraphicsView;
class ViewSpace : public QMainWindow
{
    Q_OBJECT

    void setupSpace();
public:
    ViewSpace();
    void addShip(SpaceShip *ship);
    void run();

    QGraphicsScene *scene;
    QGraphicsView *view;
    QWidget *w;

};

#endif // VIEWSPACE_H
