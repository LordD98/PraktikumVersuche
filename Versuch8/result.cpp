/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei:  result.cpp
* Inhalt: Sourcedatei Abstrakte Klasse Result
*/

#include "result.h"
#include <iostream>

/**
 * @fn	Result::Result(Expression *exp)
 *
 * @brief	Constructor.
 *
 * @param	exp		The	new Expression.
 */
Result::Result(Expression *exp) : expression(exp)
{
#ifdef PRINT_INIT
	std::cout << "Created Result" << std::endl;
#endif
}

/**
 * @fn	Result::~Result()
 *
 * @brief	Destructor.
 */
Result::~Result()
{
#ifdef PRINT_DESTR
	std::cout << "Deleted Result" << std::endl;
#endif
}

/**
 * @fn	double Result::evaluate() const
 *
 * @brief	Gets the Result of the Underlying Expression.
 *
 * @return	A double.
 */
double Result::evaluate() const
{
	return this->expression->evaluate();
}

/**
 * @fn	void Result::print() const
 *
 * @brief	Prints all underlying Expressions.
 */
void Result::print() const
{
	this->expression->print();
}