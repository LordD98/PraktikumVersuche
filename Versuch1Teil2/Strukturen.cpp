/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

struct Person
{
	string sNachname, sVorname;
	int iGeburtsjahr, iAlter;
} nBenutzer;

void printPerson(Person p);

int main()
{
	string sTemp[2];
	cout << "Geben Sie Vornamen und Namen ein:" << endl;
	cin.getline();
	cout << "In welchem Jahr wurden Sie geboren?" << endl;
	cin >> nBenutzer.iGeburtsjahr;
	cout << "Geben Sie ihr Alter ein:" << endl;
	cin >> nBenutzer.iAlter;

	int splitIndex = sTemp[1].find(' ', 0);
	sTemp[0] = sTemp[1].substr(0, splitIndex);
	sTemp[1] = sTemp[1].substr(splitIndex + 1, sTemp[0].length() - splitIndex);
	nBenutzer.sVorname = sTemp[0];
	nBenutzer.sNachname = sTemp[1];

	printPerson(nBenutzer);

	getchar();
	getchar();
	return 0;
}

void printPerson(Person p)
{
	cout << endl;
	cout << "Name der Person: " << p.sVorname + " " + p.sNachname << endl;
	cout << p.sVorname << " wurde " << p.iGeburtsjahr << " geboren und ist jetzt " << p.iAlter << " Jahre alt." << endl;
	cout << endl;
	return;
}