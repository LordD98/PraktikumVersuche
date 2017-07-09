#include "city.h"
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QDebug>

/**
 * @brief Constructor for the class City
 * @param name  The name of the City
 * @param x     x-position of the City
 * @param y     y-position of the City
 */
City::City(QString name, int x, int y) : name(name), x(x), y(y)
{

}

/**
 * @brief Draws this city on a given QGraphicsScene
 * @param QGraphicsScene scene
 */
void City::draw(QGraphicsScene& scene)
{
    qDebug() << QString("Male Stadt '%1'").arg(this->name);
    QGraphicsTextItem* text = new QGraphicsTextItem;
    text->setPos(this->x-25, this->y-30);
    text->setPlainText(this->name);
    scene.addItem(text);
    scene.addEllipse(this->x-1, this->y-1, 3.0, 3.0, QPen(Qt::red), QBrush(Qt::SolidPattern));
    return;
}

/**
 * @brief Returns the x-position of this city
 * @return x-position
 */
int City::getX()
{
    return this->x;
}

/**
 * @brief Returns the y-position of this city
 * @return y-position
 */
int City::getY()
{
    return this->y;
}

/**
 * @brief Returns the name of this city
 * @return QString name
 */
QString City::getName()
{
    return this->name;
}
