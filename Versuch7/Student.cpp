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

//bool cmp(const Student &a, const Student &b)
//{
//	return a < b;
//}

/**
 * @fn	bool Student::operator<(const Student& right) const
 *
 * @brief	Less-than comparison operator.
 *
 * @param	right	The right Student.
 *
 * @return	True if the Student Number of this instance is smaller than the right's.
 */
bool Student::operator <(const Student& right) const
{
	return this->matNr < right.matNr;
}

/**
 * @fn	bool Student::operator>(const Student& right)
 *
 * @brief	Greater-than comparison operator.
 *
 * @param	right	The right student.
 *
 * @return	True if the Student Number of this instance is greater than the right's.
 */
bool Student::operator >(const Student& right)
{
	return this->getMatNr() > right.matNr;
}

/**
 * @fn	bool Student::operator==(const Student& right)
 *
 * @brief	Equality operator.
 *
 * @param	right	The the student to compare this instance to.
 *
 * @return	True if the Students are considered equivalent, that is if their Student Numbers are equal.
 */
bool Student::operator ==(const Student& right)
{
	return this->getMatNr() == right.matNr;
}

/**
 * @fn	bool Student::equals(Student s2)
 *
 * @brief	Tests if this Student is considered equal to another.
 *
 * @param	s2	The student to compare to this instance.
 *
 * @return	True if the objects are considered equal, false if they are not.
 */
bool Student::equals(Student s2)	//deprecated. Use operator == instead
{
#ifdef _MSC_VER
#pragma message ("This function is deprecated. Use the operator '==' instead!")
#else
#pragma warning  "This function is deprecated. Use the operator '==' instead!"
#endif
	//Students are considered to be equal if all attributes are equal.
	return this->address == s2.getAddress() && this->dateOfBirth == s2.getDateOfBirth() && this->matNr == s2.getMatNr() && this->name == s2.name;
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
 * @fn	std::ostream& Student::print(std::ostream& out)
 *
 * @brief	Prints this Student.
 *
 * @param	out		The stream to print to.
 *
 * @return	A reference to the same stream.
 */
std::ostream& Student::print(std::ostream& out)
{
    out << this->getName() << ", MatNr. " << this->getMatNr() << " geb. am "
              << this->getDateOfBirth() << " wohnhaft in " << this->getAddress()
              << std::endl;
	return out;
}