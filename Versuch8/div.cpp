/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei:  div.cpp
* Inhalt: Sourcedatei Abstrakte Klasse Div
*/

#include "div.h"
#include <iostream>

Div::Div(Expression *l, Expression *r) : left(l), right(r)
{
#ifdef PRINT_INIT
	std::cout << "Created Div Expression" << std::endl;
#endif
}


Div::~Div()
{
#ifdef PRINT_DESTR
	std::cout << "Deleted Div Expression" << std::endl;
#endif
}

double Div::evaluate() const
{
	return this->left->evaluate() / this->right->evaluate();
}

void Div::print() const
{
	std::cout << "(";
	this->left->print();
	std::cout << "/";
	this->right->print();
	std::cout << ")";
}
