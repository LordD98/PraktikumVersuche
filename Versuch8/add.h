/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei:  add.h
* Inhalt: Headerdatei Abstrakte Klasse Add
*/

#include "expression.h"

#ifndef ADD_H
#define ADD_H

class Add : public Expression
{
public:
	Add(Expression *l, Expression *r);
	virtual ~Add();
	double evaluate() const;	// calculates and returns the value of expression
	void print() const;			// returns the mathematical expression as string
private:
	Expression*  left;
	Expression* right;
};

#endif