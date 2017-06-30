#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student
{
public:
	Student();
	Student(unsigned int matNr, std::string name, std::string dateOfBirth, std::string address);
	unsigned int getMatNr();
	std::string getName();
	std::string getDateOfBirth();
	std::string getAddress();
	bool equals(Student s2);
	std::ostream& print(std::ostream& out);
	bool Student::operator <(const Student& right) const;
	bool Student::operator >(const Student& right);
	bool Student::operator ==(const Student& right);
private:
    unsigned int matNr;
    std::string name;
    std::string dateOfBirth;
    std::string address;
};

//bool cmp(const Student &a, const Student &b);

#endif
