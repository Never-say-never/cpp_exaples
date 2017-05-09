#include "viewspace.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QTime>
#include <QTimer>
#include <QObject>
#include <unistd.h>

#include <iostream>

ViewSpace::ViewSpace()
{
    std::cout << std::endl << "Create scene" << std::endl;

    this->scene = new QGraphicsScene(this);
    this->scene->setSceneRect(QRectF(0, 0, 800, 800));
    this->scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    this->setupSpace();

    this->view = new QGraphicsView(this->scene);
    this->view->setRenderHint(QPainter::Antialiasing);
    this->view->setCacheMode(QGraphicsView::CacheBackground);
    this->view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    this->view->setDragMode(QGraphicsView::ScrollHandDrag);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(this->view);

    this->w = new QWidget;
    this->w->setLayout(layout);

    setCentralWidget(this->w);
    setWindowTitle(tr("Diagramscene"));
}

/**
 * @brief ViewSpace::setupSpace
 */
void ViewSpace::setupSpace()
{
    this->scene->setBackgroundBrush(QBrush(QColor(39, 138, 171, 255)));
    this->scene->addLine(0, -5, 0, 800, QPen(QBrush(Qt::yellow),1));
    this->scene->addLine(-5, 0, 800, 0, QPen(QBrush(Qt::yellow),1));
}

/**
 * @brief ViewSpace::addShip
 * @param ship
 */
void ViewSpace::addShip(SpaceShip *ship)
{
    /*int rad = 5;
    this->scene->addEllipse(ship->getPoint().x - rad * 2,
                            ship->getPoint().y - rad * 2,
                            rad * 2,
                            rad * 2,
                            QPen(Qt::red),
                            QBrush(Qt::red));*/

    ship->setPos(ship->getPoint().x, ship->getPoint().y);
    this->scene->addItem(ship);

}
