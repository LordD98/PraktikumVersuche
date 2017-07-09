/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei:  div.cpp
* Inhalt: Sourcedatei Abstrakte Klasse Div
*/

#include "div.h"
#include <iostream>

/**
 * @fn	Div::Div(Expression *l, Expression *r)
 *
 * @brief	Constructor.
 *
 * @param	l	An Expression to process.
 * @param	r	An Expression to process.
 */
Div::Div(Expression *l, Expression *r) : left(l), right(r)
{
#ifdef PRINT_INIT
	std::cout << "Created Div Expression" << std::endl;
#endif
}

/**
 * @fn	Div::~Div()
 *
 * @brief	Destructor.
 */
Div::~Div()
{
#ifdef PRINT_DESTR
	std::cout << "Deleted Div Expression" << std::endl;
#endif
}

/**
 * @fn	double Div::evaluate() const
 *
 * @brief	Gets the result of the division
 *
 * @return	A double.
 */
double Div::evaluate() const
{
	return this->left->evaluate() / this->right->evaluate();
}

/**
 * @fn	void Div::print() const
 *
 * @brief	Prints this instance.
 */
void Div::print() const
{
	std::cout << "(";
	this->left->print();
	std::cout << "/";
	this->right->print();
	std::cout << ")";
}
