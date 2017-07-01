/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei:  div.h
* Inhalt: Headerdatei Abstrakte Klasse Div
*/

#include "expression.h"

#ifndef DIV_H
#define DIV_H

class Div : public Expression
{
public:
	Div(Expression *l, Expression *r);
	virtual ~Div();
	double evaluate() const;	// calculates and returns the value of expression
	void print() const;			// returns the mathematical expression as string
private:
	Expression* right;
	Expression* left;
};

#endif