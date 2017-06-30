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
	void print();
private:
    unsigned int matNr;
    std::string name;
    std::string dateOfBirth;
    std::string address;
};

#endif
