//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <climits>

using std::invalid_argument;

int fib(int n)
{
	int prevFib = 0;
	int currFib = 1;
	if (n < 0)
	{
		throw invalid_argument("n must not be negative!");
	}
	else if(n < 2)
	{
		return n;
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			int newFib = prevFib + currFib;
			prevFib = currFib;
			currFib = newFib;
		}
		return currFib;
	}
}

int main ()
{
	std :: cout << " Fibonacci - Zahlen :" << std :: endl ;
	for (int i = 1; i <= 12 ; i ++)
	{
		std :: cout << "f(" << i << ") = " << fib (i) << std :: endl ;
	}

	int i;
	i = fib(47);		//fib(42) took <= 1ms, value = 267914296					//runtime O(n)

	getchar();			//fib(47) gives -1323752223
	
	unsigned long long maxfib = 12200160415121876738;
	INT_MAX;			//max value of signed int; gratest fib smaller than that is fib(46) = 1836311903
	ULLONG_MAX;			//changing the type of fib-function to usigned long long gives a max. value of 2^64-1; gratest fib smaller than that is fib(93) = 12200160415121876738
	return 0;
}
