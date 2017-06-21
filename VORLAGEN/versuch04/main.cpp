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

double sichtweite(double height, double step, double margin);

int main()
{
	//Vektor v_test = Vektor(345345.0, 25.0, 700.0);
	//Vektor v2 = Vektor(0.0, 1.0, 3.0);
	//Vektor v3 = Vektor(32.0, 174.0, 678.0);
	//Vektor v4 = Vektor(1.0, 1.0, 1.0);
	//Vektor v5 = Vektor(5.0, 2.0, -1.0);

	//v_test.ausgabe();
	//cout << "Laenge des Vektors: " << v_test.length() << endl;
	//cout << "Skalarprodukt mit " << v2.toString() << ": " << v_test.scalarProd(v2) << endl;
	//cout << "Addiere "<< v4.toString() <<": " << endl;
	//v_test = v_test.add(v4);
	//v_test.kurzeAusgabe();
	//v_test = v_test.sub(v4);
	//cout << "Subtrahiere " << v4.toString() << ": " << endl;
	//v_test.kurzeAusgabe();
	//cout << "Winkel zu " << v3.toString() << ": " << v_test.angle(v3) << " Grad." << endl;
	//string res = v_test.ortho(v5) ? "Ja" : "Nein";
	//cout << "Ist der Vektor orthogonal zu " << v5.toString() << "?" << endl << res << endl;
	//cout << "Rotiere den Vektor -90 Grad um die Z-Achse:" << endl;
	//v_test.rotateAroundZ(-PI/2.0);
	//v_test.ausgabe();

	sichtweite(1.8, PI/2 / 1000000000.0, 1e-6);		//We cannot go smaller (with powers of ten), because 1000000000 exceeds the value range of the int "maxSteps"

	cin.get();
	return 0;

}

double sichtweite(double height, double step, double margin)
{
	Vektor vErdradius = Vektor(0.0, EARTH_RADIUS, 0.0), vBeobachter = Vektor(0.0, EARTH_RADIUS + height, 0.0), vTemp = Vektor(0.0,0.0,0.0);
	int iSteps, maxSteps = static_cast<int>(PI/2.0/step);										//you cannot see farther than 90°
	double length, temp = DOUBLE_MAX;
	for (iSteps = 0; iSteps < maxSteps; iSteps++)
	{
		vTemp = vErdradius.sub(vBeobachter);
		if (vTemp.scalarProd(vErdradius) > temp  /* || fabs(vTemp.scalarProd(vErdradius)) < margin || fabs(90 - vTemp.angle(vErdradius)) < margin */)
			break;
		temp = fabs(vTemp.scalarProd(vErdradius));
		vErdradius.rotateAroundZ(-step);
	}
	if (iSteps == maxSteps)
		return -1.0;


	length = vErdradius.sub(vBeobachter).length();
	/*double dTheta = fabs(acos(temp / (length*EARTH_RADIUS)));
	dTheta = fabs(vTemp.angle(vErdradius));*/
	cout << "Sie koennen " << length / 1000 << " Km weit sehen." << endl;
	cout << "Sie sind " << height << " Meter hoch." << endl;
	cout << "Der Winkel betraegt " << vBeobachter.angle(vErdradius) << " Grad." << endl;
	cout << "Anzahl der Schritte : " << iSteps << endl;
	return length;
}
