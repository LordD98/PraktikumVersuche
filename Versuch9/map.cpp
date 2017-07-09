#include "map.h"
#include <vector>
#include "city.h"
#include <QString>
#include <QGraphicsScene>
#include <QDebug>
#include <cmath>
#include <algorithm>

Map::Map()
{

}

/**
 * @brief Adds a city to the map
 *
 * The class map contains a list (a vector) of cities.
 * If the map doesn't already contain the given city,
 * this function adds it to the list.
 *
 * @param The city to be added
 */
void Map::addCity(City* city)
{
    //add city to the list if it is not already in the list
    if(std::find_if(this->cities.begin(), this->cities.end(),
                    //lambda expression:
                    [city](City* obj)
                    {
                        return obj->getName() == city->getName();
                    }) == this->cities.end())
    {
        this->cities.push_back(city);
    }
    else
    {
        qDebug() << QString("Die Stadt %1 existiert bereits auf dieser Karte").arg(city->getName());
    }
}

/**
 * @brief Adds a street to the map if it isn't on there
 * @param The street to be added
 * @return false if the street cant be added
 */
bool Map::addStreet(Street * street)
{
    //Does the map contain the cities?
    if(this->find_city(street->getCity1()->getName()) != NULL && this->find_city(street->getCity2()->getName()) != NULL)
    {
        //Dont add the street if it already exists
        if(std::find_if(this->streets.begin(), this->streets.end(),
                     //lambda expression:
                     [street](Street* obj)
                     {
                         return (obj->getCity1()->getName() == street->getCity1()->getName() &&
                         obj->getCity2()->getName() == street->getCity2()->getName()) ||
                        (obj->getCity1()->getName() == street->getCity2()->getName() &&
                        obj->getCity2()->getName() == street->getCity1()->getName());
                     }) == this->streets.end())
        {
            //Add street
            this->streets.push_back(street);
        }
        else
        {
             qDebug() << QString("Die Straße zwischen %1 und %2 existiert bereits auf dieser Karte").arg(street->getCity1()->getName()).arg(street->getCity2()->getName());
             return false;
        }
        return true;
    }
    return false;
}

/**
 * @brief Finds a city with the specified name
 * @param city_name The name of the city to be found
 * @return A pointer to the city / NULL (if it isn't found)
 */
City* Map::find_city(const QString city_name) const
{
    //Loop over all cities
    std::vector<City*>::const_iterator it;
    for(it = this->cities.begin(); it != this->cities.end();it++)
    {
        City* cityPointer = *it;
        if(cityPointer->getName() == city_name)
            return cityPointer;
    }
    return NULL;
}

/**
 * @brief Draws the whole map onto a given QGraphicsscene
 * @param scene The scene to draw on
 */
void Map::draw(QGraphicsScene &scene)
{
    //Clear scene
    qDebug() << QString("Szene wird gelöscht");
    scene.clear();


    //Draw all cities
    qDebug() << QString("Male alle Städte");
    for(std::vector<City*>::iterator it = this->cities.begin(); it != this->cities.end(); it++)
    {
        City* cityPointer = *it;
        cityPointer->draw(scene);
    }

    qDebug() << QString("Male alle Straßen");

    //Draw all streets
    for(std::vector<Street*>::iterator streetIt = this->streets.begin();streetIt != this->streets.end();streetIt++)
    {
        Street* streetPointer = *streetIt;
        streetPointer->draw(scene);
    }
}

/**
 * @brief Search for all streets connected to the given city.
 * @param The city
 * @return A list of all streets which are connected to the given city.
 */
std::vector<Street*> Map::get_street_list(const City* city) const
{
    std::vector<Street*> streetList;

    std::vector<Street*>::const_iterator streetIt;
    for(streetIt = this->streets.begin(); streetIt != this->streets.end(); streetIt++)
    {
        Street* streetPointer = *streetIt;
        if(streetPointer->getCity1() == city || streetPointer->getCity2() == city)
            streetList.push_back(streetPointer);
    }
    return streetList;
}

/**
 * @brief Look for the city being at the other end of a given street.
 * @param street The street
 * @param city   The city
 * @return A pointer to the opposite city / NULL (If the given city has no connection to the given street)
 */
City* Map::get_opposite_city(const Street* street, const City* city) const
{
    if(street->getCity1() == city)
        return street->getCity2();
    else if(street->getCity2() == city)
        return street->getCity1();
    else return NULL;
}

/**
 * @brief Calculates the length of a street.
 * @param street The street
 * @return length of the street
 */
double Map::get_length(const Street* street) const
{
    double dx = abs(street->getCity1()->getX() - street->getCity2()->getX());
    double dy = abs(street->getCity1()->getY() - street->getCity2()->getY());
    return sqrt(dx*dx + dy*dy);
}

/**
 * @brief Returns a list conataining the pointers to all cities on this map
 * @return A list of the pointers to all cities on this map
 */
std::vector<City*> Map::getCities()
{
    return this->cities;
}
