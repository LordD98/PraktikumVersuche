/*
* Praktikum Informatik 1 MMXVII
* Versuch 8: Taschenrechner
*
* Datei:  const.h
* Inhalt: Headerdatei Abstrakte Klasse Const
*/

#include "expression.h"

#ifndef CONST_H
#define CONST_H

class Const : public Expression
{
public:
	Const(double val);
	virtual ~Const();
	double evaluate() const;	// calculates and returns the value of expression
	void print() const;			// returns the mathematical expression as string
private:
	double value;
};

#endif
