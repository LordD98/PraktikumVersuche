#ifndef MAP_H
#define MAP_H

#include "city.h"
#include <vector>

class Map
{
public:
    Map();
    void addCity(City*);
    void draw(QGraphicsScene& scene);
private:
    std::vector<City*> cities;
};

#endif // MAP_H
