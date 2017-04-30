
#include <iostream>

int fib(int n);

using namespace std;

int main()
{
	for (int i = 0; i <= 25; i++)
	{
		cout << fib(i) << endl;
	}

	getchar();
	return 0;
}

int fib(int n)
{
	if (n < 0)
		throw invalid_argument("Number must be greater than or equal to 0");
	else if (n <= 1)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}