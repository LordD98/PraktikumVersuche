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
} nBenutzer, nKopieEinzeln, nKopieGesamt;

void printPerson(Person p);

int main()
{
	char buf[80];
	string str;
	cout << "Geben Sie Vornamen und Namen ein:" << endl;
	cin.getline(buf, 80);
	cout << "In welchem Jahr wurden Sie geboren?" << endl;
	cin >> nBenutzer.iGeburtsjahr;
	cout << "Geben Sie ihr Alter ein:" << endl;
	cin >> nBenutzer.iAlter;

	str = buf;
	int splitIndex;
	if (str.find(',') > 79)										//User can either give his name in the form "<first name> <last name>" or "<last name>, <first name>"
	{
		splitIndex = static_cast<int>(str.find(' ', 0));				//static cast to int not really necessary, but compiler gives a warning
		nBenutzer.sVorname = str.substr(0, splitIndex);
		nBenutzer.sNachname = str.substr(splitIndex + 1, str.length() - splitIndex - 1);
	}
	else																					
	{
		splitIndex = static_cast<int>(str.find(',', 0));				//static cast to int not really necessary, but compiler gives a warning
		nBenutzer.sNachname = str.substr(0, splitIndex);
		nBenutzer.sVorname = str.substr(splitIndex + 2, str.length() - splitIndex - 2);
	}
	printPerson(nBenutzer);

	nKopieEinzeln.iAlter = nBenutzer.iAlter;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.sVorname = nBenutzer.sVorname;

	nKopieGesamt = nBenutzer;

	printPerson(nKopieEinzeln);
	printPerson(nKopieGesamt);

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