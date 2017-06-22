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

int toAlphabet(int);

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
	cout << "Der ganzzahlige Quotient ist: " << iQuotient << " (double)" << endl << endl;

	cout << "Bitte Vornamen eingeben:" << endl;
	cin >> sVorname;
	cout << "Bitte Nachnamen eingeben:" << endl;
	cin >> sNachname;
	sVornameName = sVorname + " " + sNachname;
	sNameVorname = sNachname + ", " + sVorname;
	cout << "Hallo " << sVornameName << " oder " << sNameVorname << endl << endl;

	{
		int iFeld[] = { 1, 2 };							//iFeld[0] = 1, iFeld[1] = 2											//a)
		
		int spielfeld[2][3] = { 1, 2, 3, 4, 5, 6 };		//Indizes: spielfeld[0-1][0-2]											//b)

		cout << "Neues Array angelegt." << endl << "Name: \"iFeld\"" << endl << "Anzahl der Elemente: 2" << endl;				//c) .1
		cout << "Elemente:" << endl;
		for each (int i in iFeld)
		{
			cout << "iFeld[" << i - 1 << "] ist " << i << endl;
		}
		cout << endl;

		cout << "Neues Array angelegt." << endl << "Name: \"spielfeld\"" << endl << "Anzahl der Elemente: 2x3 = 6" << endl;		//c) .2
		cout << "Elemente:" << endl;
		for each (int i in spielfeld)																							
		{
			cout << "spielfeld[" << (i-1)/3 << "][" <<  (i-1) - ((i-1)/3) * 3 << "] ist " << i << endl;
		}
		cout << endl;
	
		const int iZweite = 1;
		cout << "iZweite ist " << iZweite << endl;

	}
	//cout << "iZweite ist " << iZweite << endl;						//?????

	int iName1, iName2;
	iName1 = sVorname[0];
	iName2 = sVorname[1];
	cout << "iName1: " << iName1 << endl << "iName2: " << iName2 << endl;

	int ch1 = toAlphabet(iName1), ch2 = toAlphabet(iName2);
	cout << "Position of first char of first name in alphabet is: " << ch1 << endl << "Position of secon char is: " << ch2 << endl << endl;


	getchar();
	getchar();
	return 0;
}

int toAlphabet(int letter)
{
	if (letter >= 97)
		return letter % 96;
	else return letter % 64;
}