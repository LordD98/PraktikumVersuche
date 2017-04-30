//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int iEins, iZwei, iSumme, iQuotient;
	double dSumme, dQuotient ,dSummeCast, dQuotientCast;
	string sVorname, sNachname, sVornameName, sNameVorname;

	cout << "Erste Zahl eingeben: ";
	cin >> iEins;
	cout << "Zweite Zahl eingeben: ";
	cin >> iZwei;

	iSumme = iEins + iZwei;
	iQuotient = iEins / iZwei;

	cout << "Die folgenden Berechnungen wurden mit dem Datentyp \"int\" ausgefuehrt." << endl;
	cout << "Die Summe ist: " << iSumme << " (int)" << endl;
	cout << "Der ganzzahlige Quotient ist: " << iQuotient << " (int)" << endl;

	dSumme = static_cast<double>(iEins + iZwei);
	dQuotient = static_cast<double>(iEins / iZwei);

	cout << "Die Summe ist: " << iSumme << " (double)" << endl;
	cout << "Der ganzzahlige Quotient ist: " << iQuotient << " (double)" << endl;

	dSummeCast = static_cast<double>(iEins) + static_cast<double>(iZwei);
	dQuotientCast = static_cast<double>(iEins) / static_cast<double>(iZwei);

	cout << "Die folgenden Berechnungen wurden mit dem Datentyp \"double\" ausgefuehrt." << endl;
	cout << "Die Summe ist: " << dSumme << " (double)" << endl;
	cout << "Der ganzzahlige Quotient ist: " << iQuotient << " (double)" << endl;

	cout << "Bitte Vornamen eingeben:" << endl;
	cin >> sVorname;
	cout << "Bitte Nachnamen eingeben:" << endl;
	cin >> sNachname;
	sVornameName = sVorname + " " + sNachname;
	sNameVorname = sNachname + ", " + sVorname;
	cout << "Hallo " << sVornameName << " oder " << sNameVorname << endl << endl;

	{
		int iFeld[] = { 1, 2 };		//iFeld[0] = 1, iFeld[1] = 2
		cout << "Neues Array angelegt." << endl << "Name: \"iFeld\"" << endl << "Anzahl der Elemente: 2" << endl;
		cout << "Elemente:" << endl;
		for each (int i in iFeld)
		{
			cout << "iField[" << i-1 << "] ist " << i << endl;
		}
		

	}

	getchar();
	getchar();
	return 0;
}