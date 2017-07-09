/*
 * Praktikum Informatik 1 MMXVII
 * Versuch 8: Taschenrechner
 *
 * Datei:  expression.cpp
 * Inhalt: Sourcedatei Abstrakte Klasse Expression
 */

#include "expression.h"
#include <iostream>

/**
 * @fn	Expression::Expression()
 *
 * @brief	Default constructor.
 */
Expression::Expression()
{
#ifdef PRINT_INIT
	std::cout << "Created Expression" << std::endl;
#endif
}

/**
 * @fn	Expression::~Expression()
 *
 * @brief	Destructor.
 */
Expression::~Expression()
{
#ifdef PRINT_DESTR
	std::cout << "Deleted Expression" << std::endl;
#endif
}
