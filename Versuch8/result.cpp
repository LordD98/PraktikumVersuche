/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei:  result.cpp
* Inhalt: Sourcedatei Abstrakte Klasse Result
*/

#include "result.h"
#include <iostream>


Result::Result(Expression *exp) : expression(exp)
{
#ifdef PRINT_INIT
	std::cout << "Created Result" << std::endl;
#endif
}

Result::~Result()
{
#ifdef PRINT_DESTR
	std::cout << "Deleted Result" << std::endl;
#endif
}

double Result::evaluate() const
{
	return this->expression->evaluate();
}

void Result::print() const
{
	this->expression->print();
}