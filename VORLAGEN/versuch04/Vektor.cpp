//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <cmath>
#include <iostream>

using namespace std;

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

void Vektor::rotateAroundZ(const double rad)
{
	rotationMatrix[0][0] = cos(rad);
	rotationMatrix[0][1] = -sin(rad);
	rotationMatrix[0][2] = 0;
	rotationMatrix[1][0] = sin(rad);
	rotationMatrix[1][1] = cos(rad);
	rotationMatrix[1][2] = 0;
	rotationMatrix[2][0] = 0;
	rotationMatrix[2][1] = 0;
	rotationMatrix[2][2] = 1;

	this->transformWithMatrix(rotationMatrix);
}

void Vektor::transformWithMatrix(const double transformationMatrix[DIM][DIM])
{
	x = x*transformationMatrix[0][0] + y*transformationMatrix[0][1] + z*transformationMatrix[0][2];
	y = x*transformationMatrix[1][0] + y*transformationMatrix[1][1] + z*transformationMatrix[1][2];
	z = x*transformationMatrix[2][0] + y*transformationMatrix[2][1] + z*transformationMatrix[2][2];
}

double Vektor::angle(const Vektor &input) const
{
	return 360.0/2.0/PI * acos(this->scalarProd(input)/(this->length()*input.length()));
}

double Vektor::scalarProd(const Vektor& input) const
{
	return input.x*this->x + input.y*this->y + input.z*this->z;
}

bool Vektor::ortho(const Vektor &input) const
{
	if (this->scalarProd(input)  == 0)
		return true;
	else return false;
}

Vektor Vektor::add(const Vektor &input) const
{
	return Vektor(x + input.x, y + input.y, z + input.z);
}

Vektor Vektor::sub(const Vektor &input) const
{
	return Vektor(x-input.x, y-input.y, z-input.z);
}

double Vektor::length() const
{
	return sqrt(this->scalarProd(*this));
}

void Vektor::ausgabe() const
{
	cout << "Vektor:" << endl;
	cout << "X-Koordinate: " << x << endl;
	cout << "Y-Koordinate: " << y << endl;
	cout << "Z-Koordinate: " << z << endl;

}

double Vektor::getX() const
{
	return x;
}

double Vektor::getY() const
{
	return y;
}

double Vektor::getZ() const
{
	return z;
}