/**
* @file Vektor.cpp
*
* Provides function definitions for the class Vektor
*/


//
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//

//Some includes for some useful functions
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#ifndef Vektor_H
#define Vektor_H

//defines:
#define PI 3.141592653589793238
#define EARTH_RADIUS 6371000.0		//(in m)
#define DOUBLE_MAX 1e300
#define DIM 3
#define EPSILON 1e-10
#define EPSCMP
#define ROUND
//#define VEKTOR_TEST

//declarations
class Vektor
{
   public:
    Vektor(double x, double y, double z);
    ~Vektor();

    double getX() const;
    double getY() const;
    double getZ() const;
      
    Vektor sub(const Vektor& input) const;
    Vektor add(const Vektor& input) const;
    
    double length() const;
    bool ortho(const Vektor& input) const;
    double scalarProd(const Vektor& input) const;
    double angle(const Vektor& input) const;
    
	void rotateAroundZ(const double rad);
	void transformWithMatrix(const double transformationMatrix[DIM][DIM]);
    
    void ausgabe() const;
	void kurzeAusgabe() const;
	string toString() const;

	void roundV();


private:
    double x;
    double y;
    double z;
	double transformationMatrix[DIM][DIM] = { {0,0,0},{0,0,0},{0,0,0} };

};

double roundD(double d);

#endif
