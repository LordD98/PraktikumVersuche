
#include <iostream>

int fib(int n);

using namespace std;

int main()
{
	for (int i = 0; i <= 25; i++)
	{
		cout << fib(i) << endl;
	}

	int i;
	i = fib(47);				//fib(42) took 24.448 ms = 24,5 s, value = 267914296			//runtime: O(2^n)

 	getchar();					//fib(47) gives -1323752223
	return 0;
}

int fib(int n)
{
	if (n < 0)
		throw invalid_argument("Number must be negative!");
	else if (n <= 1)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}