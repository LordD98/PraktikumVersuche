/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei:  mul.cpp
* Inhalt: Sourcedatei Abstrakte Klasse Mul
*/

#include "mul.h"
#include <iostream>

/**
 * @fn	Mul::Mul(Expression *l, Expression *r)
 *
 * @brief	Constructor.
 *
 * @param	l	An Expression to process.
 * @param	r	An Expression to process.
 */
Mul::Mul(Expression *l, Expression *r) : left(l), right(r)
{
#ifdef PRINT_INIT
	std::cout << "Created Mul Expression" << std::endl;
#endif
}

/**
 * @fn	Mul::~Mul()
 *
 * @brief	Destructor.
 */
Mul::~Mul()
{
#ifdef PRINT_DESTR
	std::cout << "Deleted Mul Expression" << std::endl;
#endif
}

/**
 * @fn	double Mul::evaluate() const
 *
 * @brief	Gets the result of the Multiplication.
 *
 * @return	The procduct.
 */
double Mul::evaluate() const
{
	return this->left->evaluate() * this->right->evaluate();
}

/**
 * @fn	void Mul::print() const
 *
 * @brief	Prints this instance.
 */
void Mul::print() const
{
	std::cout << "(";
	this->left->print();
	std::cout << "*";
	this->right->print();
	std::cout << ")";
}
