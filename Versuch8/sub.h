/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei: sub.h
* Inhalt: Headerdatei Abstrakte Klasse Sub
*/

#include "expression.h"

#ifndef SUB_H
#define SUB_H

class Sub : public Expression
{
public:
	Sub(Expression *l, Expression *r);
	virtual ~Sub();
	double evaluate() const;	// calculates and returns the value of expression
	void print() const;			// returns the mathematical expression as string
private:
	Expression* left;
	Expression* right;
};

#endif