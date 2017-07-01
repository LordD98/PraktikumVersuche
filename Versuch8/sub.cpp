/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei:  sub.cpp
* Inhalt: Sourcedatei Abstrakte Klasse Sub
*/

#include "sub.h"
#include <iostream>

Sub::Sub(Expression *l, Expression *r) : left(l), right(r)
{
#ifdef PRINT_INIT
	std::cout << "Created Sub Expression" << std::endl;
#endif
}


Sub::~Sub()
{
#ifdef PRINT_DESTR
	std::cout << "Deleted Sub Expression" << std::endl;
#endif
}

double Sub::evaluate() const
{
	return this->left->evaluate() - this->right->evaluate();
}

void Sub::print() const
{
	std::cout << "(";
	this->left->print();
	std::cout << "-";
	this->right->print();
	std::cout << ")";
}
