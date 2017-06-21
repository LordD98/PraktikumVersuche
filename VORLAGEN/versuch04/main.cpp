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
	Vektor v_test = Vektor(0.0, 1.0, 2.0);
	Vektor v2 = Vektor(0.0, 1.0, 3.0);
	Vektor v3 = Vektor(0.0, 1.0, 2.0);
	Vektor v4 = Vektor(1.0, 1.0, 1.0);
	Vektor v5 = Vektor(5.0, 2.0, -1.0);

	v_test.ausgabe();
	cout << "Länge des Vektors: " << v_test.length() << endl;
	cout << "Skalarprodukt mit " << v2.toString() << ": " << v_test.scalarProd(v2) << endl;
	cout << "Add "<< v4.toString() <<": " << endl;
	v_test = v_test.add(v4);
	v_test.kurzeAusgabe();
	v_test = v_test.sub(v4);
	cout << "Subtract " << v4.toString() << ": " << endl;
	v_test.kurzeAusgabe();
	cout << "Winkel zu " << v3.toString() << ": " << v_test.angle(v3) << endl;
	cout << "Ist der Vektor orthogonal zu " << v5.toString() << "? " << v_test.ortho(v5) << endl;
	cout << "Rotiere den Vektor -90 Grad um die Z-Achse:" << endl;
	v_test.rotateAroundZ(-PI/2.0);
	v_test.ausgabe();

	cin.get();
	return 0;
}
