/*
 * Praktikum Informatik 1 MMXVII
 * Versuch 08: Taschenrechner
 *
 * Datei:  taschenrechner.cpp
 * Inhalt: Hauptprogramm
 */

#include <iostream>
#include "expression.h"
#include "const.h"
#include "result.h"
#include "add.h"
#include "mul.h"
#include "sub.h"
#include "div.h"

	void testConst();
	void testResult();
	void testAddConst();
	void testMulAddConst();
	void testSubMulAddConst();
	void finalTest();

 /**
 * @fn	int main()
 *
 * @brief	Main entry-point for this application.
 *
 * @return	Exit-code for the process - 0 for success, else an error code.
 */
int main()
{
	// Implementieren Sie zuerst die Klassen Const und Result und testen Sie das Ergebnis.

	//testConst();																						//passed
	//testResult();																						//passed

																										// Erg�nzen Sie ihr Programm nach und nach um weitere Rechenoperationen
	testAddConst();																						//passed
	testMulAddConst();																					//passed
	testSubMulAddConst();																				//passed
	std::cout << "Der finale Test: kommt noch..." << std::endl;											//passed
	finalTest();																						//passed

	std::cin.get();
	return 0;
}


/**
 * @fn	void testConst()
 *
 * @brief	Tests the const class.
 */
void testConst()
{
	Const c(4);
	c.print();
	std::cout << " = " << c.evaluate() << std::endl;
}

/**
 * @fn	void testResult()
 *
 * @brief	Tests the result class.
 */
void testResult()
{
	Result res ( new Const(4) );
	res.print();
	std::cout << " = " << res.evaluate() << std::endl;
}

/**
 * @fn	void testAddConst()
 *
 * @brief	Tests the add&const classes.
 */
void testAddConst()
{
	Result res (new Add (
				new Const(7),
				new Const(8)
				)
			);
	res.print();
	std::cout << " = " << res.evaluate() << std::endl;
}

/**
 * @fn	void testMulAddConst()
 *
 * @brief	Tests mul&add&const classes.
 */
void testMulAddConst()
{
	Result res (	new Add (
					new Const(4),
					new Mul (
						new Const(9),
						new Const(5)
					)
				)
			);
	res.print();
	std::cout << " = " << res.evaluate() << std::endl;
}

/**
 * @fn	void testSubMulAddConst()
 *
 * @brief	Tests sub&mul&add&const classes.
 */
void testSubMulAddConst()
{
	Result res (new Add (
					new Const(4),
					new Mul (
						new Const(9),
						new Sub (
							new Const(7),
							new Const(2)
						)
					)
				)
			);
	res.print();
	std::cout << " = " << res.evaluate() << std::endl;
}

/**
 * @fn	void finalTest()
 *
 * @brief	Tests Everything in a final test.
 */
void finalTest()
{

	Result res (new Add (
					new Const(4),
					new Mul (
						new Const(9),
						new Sub (
							new Const(7),
							new Div (
								new Const(10),
								new Const(5)
								)
							)
						)
					)
		   );

	res.print();
	std::cout << " = ";
	std::cout << res.evaluate();
	std::cout << std::endl;

// Das Ergebnis sollte etwa so aussehen:
// (4 + (9 * (7 - (10 / 5)))) = 49

}
