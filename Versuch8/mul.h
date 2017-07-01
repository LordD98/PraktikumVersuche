/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei:  mul.h
* Inhalt: Headerdatei Abstrakte Klasse Mul
*/

#include "expression.h"

#ifndef MUL_H
#define MUL_H

class Mul : public Expression
{
public:
	Mul(Expression *l, Expression *r);
	virtual ~Mul();
	double evaluate() const;	// calculates and returns the value of expression
	void print() const;			// returns the mathematical expression as string
private:
	Expression* left;
	Expression* right;
};

#endif