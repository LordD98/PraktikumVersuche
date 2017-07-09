#include "street.h"
#include <QString>
#include <QGraphicsScene>
#include <QDebug>

Street::Street(City* city1, City* city2) : city1(city1), city2(city2)
{

}

/**
 * @brief Draws the street between two cities
 * @param scene     The QGraphicsscene to draw on
 */
void Street::draw(QGraphicsScene& scene)
{
    qDebug() << QString("Male Straße zwischen den Städten %1 und %2").arg(this->city1->getName()).arg(this->city2->getName());
    scene.addLine(this->city1->getX(), this->city1->getY(), this->city2->getX(), this->city2->getY());
 }

/**
 * @brief Draws the street in bold red
 *
 * @param scene     The QGraphicsscene to draw on
 */
void Street::drawRed(QGraphicsScene& scene)
{
    qDebug() << QString("Male Straße zwischen den Städten %1 und %2").arg(this->city1->getName()).arg(this->city2->getName());
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::red);
    scene.addLine(this->city1->getX(),this->city1->getY(),this->city2->getX(),this->city2->getY(),pen);
  }

/**
 * @brief returns city 1
 * @return city 1
 */
City* Street::getCity1() const
{
    return this->city1;
}

/**
 * @brief returns city 2
 * @return city 2
 */
City* Street::getCity2() const
{
    return this->city2;
}
