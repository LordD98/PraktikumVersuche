/**
* @file Vektor.cpp
*
* Provides functions for the class Vektor
*/

//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////


#include "Vektor.h"


/*!
* @fn	Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
*
* @brief	Initializes a new Vektor
*
* This function creates a new vector and initializes it with the specified coordinates 
*
* @param inX	The x-coordinate of the new vector 
* @param inY	The y-coordinate of the new vector 
* @param inZ	The z-coordinate of the new vector 
* 				
* @return	A new vector, initialized with the given values
*/
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

/**
* @brief Standard destructor for the class "Vektor"
*
* Frees the memory of an instance of the class Vektorthis->this->rotationMatrix
* 
*/
Vektor::~Vektor()
{

}

/*!
* @fn	void Vektor::rotateAroundZ(const double rad)
*
* @brief	Performs a rotation around the z-axis
*
* This fuction sets up the transformation matrix and executes the rotation
* 
* @param rad The value of the angle in radians
* 			   
*/
void Vektor::rotateAroundZ(const double rad)
{
	//prepare the transformation matrix:
	this->transformationMatrix[0][0] = cos(rad);
	this->transformationMatrix[0][1] = -sin(rad);
	this->transformationMatrix[0][2] = 0;
	this->transformationMatrix[1][0] = sin(rad);
	this->transformationMatrix[1][1] = cos(rad);
	this->transformationMatrix[1][2] = 0;
	this->transformationMatrix[2][0] = 0;
	this->transformationMatrix[2][1] = 0;
	this->transformationMatrix[2][2] = 1;

	//perform the transformation:
	this->transformWithMatrix(this->transformationMatrix);
}

/*!
* @fn	void Vektor::transformWithMatrix(const double matrix[DIM][DIM])
*
* @brief	An auxilliary function which performs a linear transformation on the vector
*
* This function performs a linear transformation specified by the given matrix on the vector (this)
* by perfoming a matrix-vector product, updating the vector and rounding it.
*
* @param matrix[DIM][DIM]		The transformation matrix which holds the information of the linear transformation
*
*/
void Vektor::transformWithMatrix(const double matrix[DIM][DIM])
{	
	//save the old values:
	double oldX = this->x, oldY = this->y, oldZ = this->z;
	//perform the multiplication:
	this->x = oldX*matrix[0][0] + oldY*matrix[0][1] + oldZ*matrix[0][2];
	this->y = oldX*matrix[1][0] + oldY*matrix[1][1] + oldZ*matrix[1][2];
	this->z = oldX*matrix[2][0] + oldY*matrix[2][1] + oldZ*matrix[2][2];
	//round the vector:
	this->roundV();
}

/*!
* @fn	double Vektor::angle(const Vektor &input) const
*
* @brief	Calculates the angle (degrees) beween two vectors
*
* This function calculates the angle in degrees between the two vectors "this" and "input" by using the formula
* a = arccos( <v1,v2> / (abs(v1) * abs(v2)) ),
* which is a property of the dot product.
* Additionally, the angle is rounded (if it is close enough to an integer).
*
* @param input	the second vector
*
* @return  The (rounded) angle between the two vectors
*/
double Vektor::angle(const Vektor &input) const
{
	return roundD(acos(this->scalarProd(input)/(this->length() * input.length())) / (2.0*PI) * 360.0);
}

/*!
* @fn	double Vektor::scalarProd(const Vektor& input) const
*
* @brief	Calculates the dot product between the two vectors
*
* Calculates the dot product between two vectors according to the formula <v1, v2> = sqrt(x1*x2 + y1*y2 + z1*z2)
*
* @param input The second vector
*
* @return	The dot product between the two vectors
*/
double Vektor::scalarProd(const Vektor& input) const
{
	return input.x*this->x + input.y*this->y + input.z*this->z;
}

/*!
* @fn	bool Vektor::ortho(const Vektor &input) const
*
* @brief	Checks if two vectors are orthogonal
*
* This function checks if two vectors are orthogonal by comparing the absolute value of the dot product
* between the two vectors to the macro EPSILON (if the macro EPSCMP is defined),
* because of the possible inaccuracy of the floating-point representation of the vector's elements
* (otherwise it just checks if the dot product is zero).
*
* @param input	The second vector
*
* @return		True if the vector (this) is orthogonal to the input argument vector
*/
bool Vektor::ortho(const Vektor &input) const
{
#ifdef EPSCMP
	if (fabs(this->scalarProd(input)) < EPSILON)
#else
	if (this->scalarProd(input) == 0.0)
#endif
		return true;
	else return false;
}

/*!
* @fn	Vektor Vektor::add(const Vektor &input) const
*
* @brief	Adds one vector to another
*
* This function adds the given input vector to the vector (this)
* by performing an elementwise addition and returning the result in a new vector
*
* @param input The second summand
*
* @return	A new vector, being the sum of the vector (this) and the input vector
*/
Vektor Vektor::add(const Vektor &input) const
{
	return Vektor(x + input.x, y + input.y, z + input.z);
}

/*!
* @fn	Vektor Vektor::sub(const Vektor &input) const
*
* @brief	Subtracts one vector of another
*
* This function subtracts the given input vector from the vector (this)
* by performing an elementwise subtraction and returning the difference in a new vector
*
* @param input The subtractor
*
* @return	A new vector, being the difference between the vector (this) and the subtractor
*/
Vektor Vektor::sub(const Vektor &input) const
{
	return Vektor(this->x-input.x, this->y-input.y, this->z-input.z);
}

/*!
* @fn	double Vektor::length() const
*
* @brief	Calculates the length of the vector
*
* Calculates the length of the vector by taking the sqare-root of the dot product with itself
*
* @return	The length of the vector
*/
double Vektor::length() const
{
	return sqrt(this->scalarProd(*this));
}

/*!
* @fn	void Vektor::kurzeAusgabe() const
*
* @brief	Prints out a vector in a short form
*
* This funtion prints out a vector in a short form, the same as
* cout << Vektor::toString() << endl;,
* resulting in a format like ie. (1, 2, 3)
* 
*/
void Vektor::kurzeAusgabe() const
{
	cout << "(" << this->x << ", " << this->y << ", " << this->z << ")" << endl;
}

/*!
* @fn	void Vektor::ausgabe() const
*
* @brief	Prints out a vector
*
* This funtion prints out a vector in a long format
* 
*/
void Vektor::ausgabe() const
{
	cout << "Vektor:" << endl;
	cout << "X-Koordinate: " << this->x << endl;
	cout << "Y-Koordinate: " << this->y << endl;
	cout << "Z-Koordinate: " << this->z << endl;
}

/*!
* @fn	double Vektor::getX() const
*
* @brief	returns the x-coordinate of the vector
*
* @return	The x-coordinate of the vector
*/
double Vektor::getX() const
{
	return this->x;
}

/*!
* @fn	double Vektor::getY() const
*
* @brief	returns the y-coordinate of the vector
*
* @return	The y-coordinate of the vector
*/
double Vektor::getY() const
{
	return this->y;
}

/*!
* @fn	double Vektor::getZ() const
*
* @brief	returns the z-coordinate of the vector
*
* @return	The z-coordinate of the vector
*/
double Vektor::getZ() const
{
	return this->z;
}

/*!
* @fn	string Vektor::toString() const
*
* @brief	This function converts a vector to a string.
* 			
* This function converts a vector to a string by outputting the data into an ostringstream in the correct format
* and reading the content of the stream into a string.
* We're using ostringstream here because just converting the doubles into strings
* often leads to long tails of zeroes at the end of the numbers, which is not the case here.
* 
* @return	The vector in string form (ie. "(1, 2, 3)") 
*/
string Vektor::toString() const
{
	std::ostringstream strs;
	strs << "(" << x << ", " << y << ", " << z << ")";
	return strs.str();
}

/*!
* @fn	void Vektor::roundV()
*
* @brief	This function rounds a vector
*
* This function rounds a vector by rounding all of its elements with the roundD function,
* but only if the macro "ROUND" is defined
*
*/
void Vektor::roundV()
{
#ifdef ROUND
	this->x = roundD(x);
	this->y = roundD(y);
	this->z = roundD(z);
#endif
}


/*!
* @fn	double roundD(double d)
*
* @brief	An auxiliary function to round a double
*
* This function rounds a double if abs(d) <= 10,
* by stepping over all integers in that range
* and looking whether the double is close enough to it
*
* @param d	The double to be rounded
* 
* @return	The rounded value
*/
double roundD(double d)
{
	for (int i = -10; i <= 10; i++)
	{
		if (fabs(d - static_cast<double>(i)) < EPSILON)
			return static_cast<double>(i);
	}
	return d;
}