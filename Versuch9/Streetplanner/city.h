#ifndef CITY_H
#define CITY_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

class City
{
public:
   City(QString name, int x, int y);
   void draw(QGraphicsScene& scene) const;
private:
   QString name;
   int x;
   int y;
};

#endif // CITY_H
