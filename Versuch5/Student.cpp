/**
 * @file	Student.cpp.
 *
 * @brief	Implements the Student class.
 */
#include <iostream>
#include "Student.h"

/**
 * @fn	Student::Student(unsigned int matNr, std::string name, std::string dateOfBirth, std::string address)
 *
 * @brief	The Constructor for the class Student.
 *
 * @param	matNr	   	The Student Number.
 * @param	name	   	The name.
 * @param	dateOfBirth	The date of birth.
 * @param	address	   	The address.
 */
Student::Student(unsigned int matNr, std::string name, std::string dateOfBirth, std::string address) :
matNr(matNr), name(name), dateOfBirth(dateOfBirth), address(address)
{

}

/**
 * @fn	Student::Student()
 *
 * @brief	Default constructor.
 */
Student::Student() : matNr(0), name(""), dateOfBirth(""), address("")
{

}

/**
 * @fn	unsigned int Student::getMatNr()
 *
 * @brief	Gets the student Number.
 *
 * @return	The student Number.
 */
unsigned int Student::getMatNr()
{
	return this->matNr;
}

/**
 * @fn	std::string Student::getName()
 *
 * @brief	Gets the name.
 *
 * @return	The name.
 */
std::string Student::getName()
{
	return this->name;
}

/**
 * @fn	std::string Student::getDateOfBirth()
 *
 * @brief	Gets date of birth.
 *
 * @return	The date of birth.
 */
std::string Student::getDateOfBirth()
{
	return this->dateOfBirth;
}

/**
 * @fn	std::string Student::getAddress()
 *
 * @brief	Gets the address.
 *
 * @return	The address.
 */
std::string Student::getAddress()
{
	return this->address;
}

/**
 * @fn	void Student::print()
 *
 * @brief	Prints this instance.
 */
void Student::print()
{
    std::cout << this->getName() << ", MatNr. " << this->getMatNr() << " geb. am "
              << this->getDateOfBirth() << " wohnhaft in " << this->getAddress()
              << std::endl;
}
