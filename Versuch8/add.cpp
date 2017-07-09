/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei:  add.cpp
* Inhalt: Sourcedatei Abstrakte Klasse Add
*/

#include "add.h"
#include <iostream>

/**
 * @fn	Add::Add(Expression *l, Expression *r)
 *
 * @brief	Constructor.
 *
 * @param 	l	An Expression to process.
 * @param 	r	An Expression to process.
 */
Add::Add(Expression *l, Expression *r) : left(l), right(r)
{
#ifdef PRINT_INIT
	std::cout << "Created Add Expression" << std::endl;
#endif
}

/**
 * @fn	Add::~Add()
 *
 * @brief	Destructor for Add expression.
 */
Add::~Add()
{
#ifdef PRINT_DESTR
	std::cout << "Deleted Add Expression" << std::endl;
#endif
}

/**
 * @fn	double Add::evaluate() const
 *
 * @brief	Gets the result of the Addition.
 *
 * @return	A double.
 */
double Add::evaluate() const
{
	return this->left->evaluate() + this->right->evaluate();
}

/**
 * @fn	void Add::print() const
 *
 * @brief	Prints this instance.
 */
void Add::print() const
{
	std::cout << "(";
	this->left->print();
	std::cout << "+";
	this->right->print();
	std::cout << ")";
}