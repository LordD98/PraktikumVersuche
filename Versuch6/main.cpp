/** @mainpage
 *
 * Praktikum Informatik 1@n
 * Versuch 6: STL
 *
 * *Die erklaerenden Texte wurden zum Teil von* wikipedia.org *uebernommen*@n
 * *Siehe hierzu die entsprechende* [Webseite][wikipedia].
 *
 * [wikipedia]: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
 */

/**
 * @file main.cpp
 *
 * content: main routine
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;

/**
 * @fn	int main()
 *
 * @brief	Main entry-point for this application.
 *
 * @return	Exit-code for the process - 0 for success, else an error code.
 */
int main()
{
    vector<Student> studentList;
    Student student = Student();

    char abfrage;
    std::cout << "Wollen sie den Stack selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;

    if (abfrage != 'j')
    {
    	student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
    	studentList.push_back(student);
    	student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
		studentList.push_back(student);
    	student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
    	studentList.push_back(student);
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinzuf�gen" << std::endl
                  << "(2): Datenelement abh�ngen" << std::endl
				  << "(3): Datenbank ausgeben" << std::endl
				  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
				  << "(5): Datenelement l�schen" << std::endl
				  << "(6): Datenelement hinten erg�nzen" << std::endl
                  << "(7): Beenden" << std::endl << std::endl;
        std::cin >> abfrage;


		unsigned int matNr = 0;
		std::string name = "";
		std::string dateOfBirth = "";
		std::string address = "";
		vector<Student>::iterator it;
		vector<Student>::reverse_iterator revIt;
        
		switch (abfrage)
        {
            case '1':
				{
					std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
					std::cin.ignore(10, '\n');    // ignore character '\n', which still is in the buffer
					getline(std::cin, name);      // get entire line, including whitespace
					std::cout << "Geburtsdatum: ";
					getline(std::cin, dateOfBirth);
					std::cout << "Adresse: ";
					getline(std::cin, address);
					std::cout << "Matrikelnummer: ";
					std::cin >> matNr;

					student = Student(matNr, name, dateOfBirth, address);

					studentList.insert(studentList.begin(), student);
				}
				break;
            case '2':
            	{
					Student delElem = Student();
					bool success = false;
					if (!studentList.empty())
					{
						success = true;
					}
					else
					{
						std::cout << "Der Stack ist leer!\n";
						break;
					}
					delElem = studentList.back();
					studentList.pop_back();
					std::cout << "Das letzte Datenelemt wird entfernt\n";
					delElem.print();
            	}
                break;

            case '3':
                std::cout << "Inhalt der Liste:\n";
				//print forwards
				for (it = studentList.begin(); it != studentList.end(); it++)
				{
					it->print();
				}
                break;

			case '4':
				std::cout << "Inhalt der Liste rueckwaerts:\n";
				//print backwards
				for (revIt = studentList.rbegin(); revIt != studentList.rend(); revIt++)
				{
					revIt->print();
				}
				break;

			case '5':
				std::cout << "Matrikelnummer des zu loeschenden Studenten eingeben:" << std::endl;
				std::cin >> matNr;
				/*
				it = studentList.begin();
				do 
				{
					if (it->getMatNr() == matNr)
					{
						break;
					}
					it++;
				} while (it != studentList.end());

				studentList.remove(cursor);
				*/

				studentList.erase(std::remove_if(studentList.begin(), studentList.end(), [matNr](Student s) { return s.getMatNr() == matNr; }));

				std::cout << "Loeschen erfolgreich!\n";
				break;

			case '6':

				std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
				std::cin.ignore(10, '\n');    // ignore character '\n', which still is in the buffer
				getline(std::cin, name);      // get entire line, including whitespace
				std::cout << "Geburtsdatum: ";
				getline(std::cin, dateOfBirth);
				std::cout << "Adresse: ";
				getline(std::cin, address);
				std::cout << "Matrikelnummer: " << std::flush;
				std::cin >> matNr;

				student = Student(matNr, name, dateOfBirth, address);

				studentList.insert(studentList.end(), student);
				break;

            case '7':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '7');

    return 0;
}
