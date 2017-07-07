/** @mainpage
 *
 * Praktikum Informatik 1@n
 * Versuch 5 Teil 2: Dynamische Datenstrukturen
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
#include "Student.h"
#include "List.h"

/**
 * @fn	int main()
 *
 * @brief	Main entry-point for this application.
 *
 * @return	Exit-code for the process - 0 for success, else an error code.
 */
int main()
{
    List studentList;
    Student student = Student();

    char abfrage;
    std::cout << "Wollen sie den Stack selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;

    if (abfrage != 'j')
    {
    	student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
    	studentList.enqueue_head(student);
    	student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wüllnerstr.9");
    	studentList.enqueue_head(student);
    	student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
    	studentList.enqueue_head(student);
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinzufügen" << std::endl
                  << "(2): Datenelement abhängen" << std::endl
				  << "(3): Datenbank ausgeben" << std::endl
				  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
				  << "(5): Datenelement löschen" << std::endl
				  << "(6): Datenelement hinten ergänzen" << std::endl
                  << "(7): Beenden" << std::endl << std::endl;
        std::cin >> abfrage;


		unsigned int matNr = 0;
		std::string name = "";
		std::string dateOfBirth = "";
		std::string address = "";
		ListElem *cursor = NULL;
        
		switch (abfrage)
        {
            case '1':
				{
					std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
					std::cin.ignore(10, '\n');    // ignore character '\n', which still is in the buffer
					getline(std::cin, name);      // get entire line, including whitespace
					std::cout << "Geburtsdatum: ";
					getline(std::cin, dateOfBirth);
					std::cout << "Adresse: ";
					getline(std::cin, address);
					std::cout << "Matrikelnummer: ";
					std::cin >> matNr;

					student = Student(matNr, name, dateOfBirth, address);

					studentList.enqueue_head(student);
				}
				break;
            case '2':
            	{
					Student delElem = Student();
					bool success = false;
					success = studentList.dequeue(delElem);

					if(success)
					{
						std::cout << "Das letzte Datenelemt wird entfernt\n";
						delElem.print();
					}
					else
					{
						std::cout << "Der Stack ist leer!\n";
					}
            	}
                break;

            case '3':
                std::cout << "Inhalt der Liste:\n";
                studentList.print_forwards();
                break;

			case '4':
				std::cout << "Inhalt der Liste rueckwaerts:\n";
				studentList.print_backwards();
				break;

			case '5':
				std::cout << "Matrikelnummer des zu loeschenden Studenten eingeben:" << std::endl;
				std::cin >> matNr;
				cursor = studentList.getFirst();
				do 
				{
					if (cursor->getData().getMatNr() == matNr)
					{
						break;
					}
					cursor = cursor->getNext();
				} while (cursor != NULL);

				studentList.remove(cursor);

				std::cout << "Loeschen erfolgreich!\n";
				break;

			case '6':

				std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
				std::cin.ignore(10, '\n');    // ignore character '\n', which still is in the buffer
				getline(std::cin, name);      // get entire line, including whitespace
				std::cout << "Geburtsdatum: ";
				getline(std::cin, dateOfBirth);
				std::cout << "Adresse: ";
				getline(std::cin, address);
				std::cout << "Matrikelnummer: " << std::flush;
				std::cin >> matNr;

				student = Student(matNr, name, dateOfBirth, address);

				studentList.enqueue_tail(student);
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
