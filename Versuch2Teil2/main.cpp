//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

int fib(int n)
{
	int prevFib = 1;
	int currFib = 1;
	if(n == 0)
	{
		return 0;
	}
	if(n == 1)
	{
		return 1;
	}
	for (int i = 0; i <= n; i++)
	{
		int newFib = prevFib + currFib ;
		prevFib = newFib ;
		currFib = prevFib ;
	}
	return currFib ;
}

int main ()
{
	std :: cout << " Fibonacci - Zahlen :" << std :: endl ;
	for (int i = 1; i <= 12 ; i ++)
	{
		std :: cout << "f(" << i << ") = " << fib (i) << std :: endl ;
	}
	return 0;
}
