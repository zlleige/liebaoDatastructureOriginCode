#include <iostream>

using namespace std;

int main()
{
	int a, b, tmp;

	a = 1;
	b = 10;

	cout << "a = " << a << ", b = " << b << endl;

	tmp = a;
	a = b;
	b = tmp;

	cout << "a = " << a << ", b = " << b << endl;
	return 0;
}