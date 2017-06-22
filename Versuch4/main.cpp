/**
 * @file main.cpp
 *
 *  
 */

/**
* @mainpage Versuch4
*
* Dokumentation des Versuches 4 im Rahmen des Praktikums Informatik 1.
*
*/

 
//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <iomanip>
#include "Vektor.h"

using namespace std;

double sichtweite(double height, double step /*, double margin */);


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
int main()
{
#ifdef VEKTOR_TEST
	//Konstruktoren:
	Vektor v_test = Vektor(1.0, 2.5, 7.0);
	Vektor v2 = Vektor(0.0, 1.0, 3.0);
	Vektor v3 = Vektor(2.0, 4.0, 6.0);
	Vektor v4 = Vektor(1.0, 1.0, 1.0);
	Vektor v5 = Vektor(5.0, 2.0, -1.0);

	//Eigentliches Programm:
	v_test.ausgabe();																				//	Ausgabe v_test
	cout << "Laenge des Vektors: " << v_test.length() << endl;										//	Länge v_test
	cout << "Skalarprodukt mit " << v2.toString() << ": " << v_test.scalarProd(v2) << endl;			//	Skalarpodukt mit v2
	cout << "Addiere "<< v4.toString() <<": " << endl;												//	Ausgabe v4
	v_test = v_test.add(v4);																		//	v_test = v_test + v4
	v_test.kurzeAusgabe();																			//	Ausgabe der Summe
	v_test = v_test.sub(v4);																		//	v_test = v_test - v4
	cout << "Subtrahiere " << v4.toString() << ": " << endl;										//	Ausgabe v4
	v_test.kurzeAusgabe();																			//	Ausgabe der Differenz
	cout << "Winkel zu " << v3.toString() << ": " << v_test.angle(v3) << " Grad." << endl;			//	Winkel zu v3
	string res = v_test.ortho(v5) ? "Ja" : "Nein";													//
	cout << "Ist der Vektor orthogonal zu " << v5.toString() << "?" << endl << res << endl;			//	v_test orthogonal zu v5?
	cout << "Rotiere den Vektor -90 Grad um die Z-Achse:" << endl;									//	
	v_test.rotateAroundZ(-PI/2.0);																	//	Rotation um die Z-Achse
	v_test.ausgabe();																				//	Ausgabe v_test

	//Destruktoren:
	~v_test;
	~v2;
	~v3;
	~v4;
	~v5;
#endif

	sichtweite(1.8, PI/2 / 1000000.0 /*, 1e-6 */ );		//We cannot go smaller than 1e9 (with powers of ten), because 1e9 exceeds the value range of the int "maxSteps"

	cin.get();
	return 0;

}

/*!
* @fn	double sichtweite(double height, double step)
*
* @brief	 Computes the distance from your eyes to the horizon in meters
*
* This function computes the distance to the farthest point you can see (the horizon) in meters.
* It rotates a temporary vector representing the earth's radius away from you to the horizon
* and checks if the line of sight from your eyes to the tip of that vector and the vector are orthogonal.
* If they are, the funtion prints out and returns the length of that vector and prints out additional information.
*
* @param height		The height of your eyes over the ground in meters
* @param step		The difference of the angle between two iterations of the loop in radians
*
* @return  The distance to the horizon in meters
*/
double sichtweite(double height, double step /*, double margin */ )
{
	//set up all variables used:
	Vektor	vErdradius = Vektor(0.0, EARTH_RADIUS, 0.0),
			vBeobachter = Vektor(0.0, EARTH_RADIUS + height, 0.0),
			vSicht = Vektor(0.0, 0.0, 0.0)
	;
	int iSteps = 0,
		maxSteps = static_cast<int>(PI / 2.0 / step)							//you cannot see farther than 90°
	;
	double	length = 0.0,
			prevDotP = DOUBLE_MAX
	;

	// step over one quarter of the earth's radius to find the point,
	// where the angle between the line from our eyes to the horizon (that point) and the earth's radius at that point
	// is exactly (closest) to 90 degrees or equivalent where the dot product is zero (closest to zero)
	for (iSteps; iSteps < maxSteps; iSteps++)
	{
		vSicht = vErdradius.sub(vBeobachter);
		//because of our increment not being inifinetely small,
		//we are not guaranteed to find an angle where the dot product is zero 
		//so if the dot product is bigger than the previous one, we have found the minimum
		if (vSicht.scalarProd(vErdradius) > prevDotP  /* || fabs(vTemp.scalarProd(vErdradius)) < margin || fabs(90 - vTemp.angle(vErdradius)) < margin */)
			break;

		//update the prevDotP and rotate the vector vErdradius one step further:
		prevDotP = fabs(vSicht.scalarProd(vErdradius));
		vErdradius.rotateAroundZ(-step);
	}

	if (iSteps == maxSteps)		//if iSteps equals maxSteps, something went wrong
		return -1.0;			//so we return a negative number

	//save the computed length:
	length = vErdradius.sub(vBeobachter).length();

	//print all information and return:
	cout << "Sie koennen " << length / 1000 << " Km weit sehen." << endl;
	cout << "Sie sind " << height << " Meter hoch." << endl;
	cout << "Der Winkel betraegt " << vBeobachter.angle(vErdradius) << " Grad." << endl;
	cout << "Anzahl der Schritte : " << iSteps << endl;
	return length;
}
