#include <iostream>

using namespace std;

int main()
{
	int a, b;
	a = 1;
	b = 10;
	cout << "ʹ��std::swap����: " << endl;
	cout << "a = " << a << ", b = " << b << endl;
	std::swap(a,b);
	cout << "a = " << a << ", b = " << b << endl;
	return 0;
}