/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei:  const.cpp
* Inhalt: Sourcedatei Abstrakte Klasse Const
*/

#include "const.h"
#include <iostream>

/**
 * @fn	Const::Const(double val)
 *
 * @brief	Constructor.
 *
 * @param	val	The value.
 */
Const::Const(double val) : value(val)
{
#ifdef PRINT_INIT
	std::cout << "Created Const Expression" << std::endl;
#endif
}

/**
 * @fn	Const::~Const()
 *
 * @brief	Destructor for the Const expression.
 */
Const::~Const()
{
#ifdef PRINT_DESTR
	std::cout << "Deleted Const Expression" << std::endl;
#endif
}

/**
 * @fn	double Const::evaluate() const
 *
 * @brief	Gets the value of the const.
 *
 * @return	The value.
 */
double Const::evaluate() const
{
	return this->value;
}

/**
 * @fn	void Const::print() const
 *
 * @brief	Prints this instance.
 */
void Const::print() const
{
	std::cout << this->value;
}