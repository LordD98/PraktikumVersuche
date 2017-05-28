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

int main()
{
	Vektor v_test = Vektor(1.0, 4.0, 2.0);
	v_test.ausgabe();
	cout << "Länge des Vektors: " << v_test.length() << endl;
	cout << "Skalarprodukt mit (0, 1, 3): " << v_test.scalarProd(Vektor(0.0, 1.0, 3.0)) << endl;
	cout << "Add (1, 1, 1): " << endl;
	v_test = v_test.add(Vektor(1.0, 1.0, 1.0));
	v_test.ausgabe();
	v_test = v_test.sub(Vektor(1.0, 1.0, 1.0));
	cout << "Subtract (1, 1, 1): " << endl;
	v_test.ausgabe();
	cout << "Winkel zu (3, 3/2, 5/2): " << v_test.angle(Vektor(3.0, 3.0 / 2.0, 5.0 / 2.0)) << endl;
	cout << "Ist der Vektor orthogonal zu (5,1,0)?" << v_test.ortho(Vektor(5.0, 1.0, 0.0)) << endl;
	cout << "Rotiere den Vektor -90° um die Z-Achse:" << endl;
	v_test.rotateAroundZ(-PI/2.0);
	v_test.ausgabe();

	return 0;
}
