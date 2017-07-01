/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei:  const.cpp
* Inhalt: Sourcedatei Abstrakte Klasse Const
*/

#include "const.h"
#include <iostream>


Const::Const(double val) : value(val)
{
#ifdef PRINT_INIT
	std::cout << "Created Const Expression" << std::endl;
#endif
}

Const::~Const()
{
#ifdef PRINT_DESTR
	std::cout << "Deleted Const Expression" << std::endl;
#endif
}

double Const::evaluate() const
{
	return this->value;
}

void Const::print() const
{
	std::cout << this->value;
}