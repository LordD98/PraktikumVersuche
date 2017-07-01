/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei:  result.h
* Inhalt: Headerdatei Abstrakte Klasse Result
*/

#include "expression.h"

#ifndef RESULT_H
#define RESULT_H

class Result : public Expression
{
public:
	Result(Expression *exp);
	virtual ~Result();
	double evaluate() const;	// calculates and returns the value of expression
	void print() const;			// returns the mathematical expression as string
private:
	Expression *expression;
};

#endif
