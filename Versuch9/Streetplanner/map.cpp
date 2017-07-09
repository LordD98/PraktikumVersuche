#include "map.h"

Map::Map()
{

}

void Map::draw(QGraphicsScene& scene)
{
    std::vector<City*>::iterator it;
    for (it = this->cities.begin(); it != this->cities.end(); it++)
    {
        (*it)->draw(scene);
    }
}

void Map::addCity(City* city)
{
    this->cities.push_back(city);
}
