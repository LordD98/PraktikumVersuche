/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei:  sub.cpp
* Inhalt: Sourcedatei Abstrakte Klasse Sub
*/

#include "sub.h"
#include <iostream>

/**
 * @fn	Sub::Sub(Expression *l, Expression *r)
 *
 * @brief	Constructor.
 *
 * @param	l	An Expression to process.
 * @param	r	An Expression to process.
 */
Sub::Sub(Expression *l, Expression *r) : left(l), right(r)
{
#ifdef PRINT_INIT
	std::cout << "Created Sub Expression" << std::endl;
#endif
}

/**
 * @fn	Sub::~Sub()
 *
 * @brief	Destructor.
 */
Sub::~Sub()
{
#ifdef PRINT_DESTR
	std::cout << "Deleted Sub Expression" << std::endl;
#endif
}

/**
 * @fn	double Sub::evaluate() const
 *
 * @brief	Gets the result of the Subtraction.
 *
 * @return	A double.
 */
double Sub::evaluate() const
{
	return this->left->evaluate() - this->right->evaluate();
}

/**
 * @fn	void Sub::print() const
 *
 * @brief	Prints this instance.
 */
void Sub::print() const
{
	std::cout << "(";
	this->left->print();
	std::cout << "-";
	this->right->print();
	std::cout << ")";
}
