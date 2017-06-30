#include <iostream>
#include "Student.h"

Student::Student(unsigned int matNr, std::string name, std::string dateOfBirth, std::string address) :
matNr(matNr), name(name), dateOfBirth(dateOfBirth), address(address)
{ }

Student::Student() : matNr(0), name(""), dateOfBirth(""), address("")
{ }

//bool cmp(const Student &a, const Student &b)
//{
//	return a < b;
//}

bool Student::operator <(const Student& right) const
{
	return this->matNr < right.matNr;
}

bool Student::operator >(const Student& right)
{
	return this->getMatNr() > right.matNr;
}

bool Student::operator ==(const Student& right)
{
	return this->getMatNr() == right.matNr;
}

bool Student::equals(Student s2)
{
	return this->address == s2.getAddress() && this->dateOfBirth == s2.getDateOfBirth() && this->matNr == s2.getMatNr() && this->name == s2.name;
}

unsigned int Student::getMatNr()
{
	return this->matNr;
}

std::string Student::getName()
{
	return this->name;
}

std::string Student::getDateOfBirth()
{
	return this->dateOfBirth;
}

std::string Student::getAddress()
{
	return this->address;
}

std::ostream& Student::print(std::ostream& out)
{
    out << this->getName() << ", MatNr. " << this->getMatNr() << " geb. am "
              << this->getDateOfBirth() << " wohnhaft in " << this->getAddress()
              << std::endl;
	return out;
}