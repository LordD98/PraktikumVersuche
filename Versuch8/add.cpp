/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei:  add.cpp
* Inhalt: Sourcedatei Abstrakte Klasse Add
*/

#include "add.h"
#include <iostream>

Add::Add(Expression *l, Expression *r) : left(l), right(r)
{
#ifdef PRINT_INIT
	std::cout << "Created Add Expression" << std::endl;
#endif
}


Add::~Add()
{
#ifdef PRINT_DESTR
	std::cout << "Deleted Add Expression" << std::endl;
#endif
}

double Add::evaluate() const
{
	return this->left->evaluate() + this->right->evaluate();
}

void Add::print() const
{
	std::cout << "(";
	this->left->print();
	std::cout << "+";
	this->right->print();
	std::cout << ")";
}