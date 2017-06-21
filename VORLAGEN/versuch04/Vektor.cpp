//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

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
	double tempX = x, tempY = y, tempZ = z;
	x = tempX*transformationMatrix[0][0] + tempY*transformationMatrix[0][1] + tempZ*transformationMatrix[0][2];
	y = tempX*transformationMatrix[1][0] + tempY*transformationMatrix[1][1] + tempZ*transformationMatrix[1][2];
	z = tempX*transformationMatrix[2][0] + tempY*transformationMatrix[2][1] + tempZ*transformationMatrix[2][2];
	this->roundV();
}

double Vektor::angle(const Vektor &input) const
{
	return roundD(acos(this->scalarProd(input)/(this->length()* input.length())) / (2.0*PI) * 360.0);
}

double Vektor::scalarProd(const Vektor& input) const
{
	return input.x*this->x + input.y*this->y + input.z*this->z;
}

bool Vektor::ortho(const Vektor &input) const
{
#ifdef EPSCMP
	if (fabs(this->scalarProd(input)) < EPSILON)
#else
	if (this->scalarProd(input) == 0)
#endif
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

void Vektor::kurzeAusgabe() const
{
	cout << "(" << x << ", " << y << ", " << z << ")" << endl;
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

string Vektor::toString() const
{
	std::ostringstream strs;
	strs << "(" << x << ", " << y << ", " << z << ")";
	return strs.str();
}

void Vektor::roundV()
{
#ifdef ROUND
	this->x = roundD(x);
	this->y = roundD(y);
	this->z = roundD(z);
#endif
}


double roundD(double d)
{
	for (int i = -10; i <= 10; i++)
	{
		if (fabs(d - static_cast<double>(i)) < EPSILON)
			return static_cast<double>(i);
	}
	return d;
}