/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei:  mul.cpp
* Inhalt: Sourcedatei Abstrakte Klasse Mul
*/

#include "mul.h"
#include <iostream>

Mul::Mul(Expression *l, Expression *r) : left(l), right(r)
{
#ifdef PRINT_INIT
	std::cout << "Created Mul Expression" << std::endl;
#endif
}


Mul::~Mul()
{
#ifdef PRINT_DESTR
	std::cout << "Deleted Mul Expression" << std::endl;
#endif
}

double Mul::evaluate() const
{
	return this->left->evaluate() * this->right->evaluate();
}

void Mul::print() const
{
	std::cout << "(";
	this->left->print();
	std::cout << "*";
	this->right->print();
	std::cout << ")";
}
