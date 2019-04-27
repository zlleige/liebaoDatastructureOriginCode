#include <iostream>

using namespace std;

void swap(int &rx, int &ry);

int main()
{
	int a,b;
	a = 1;
	b = 10;
	cout << "传引用: " << endl;
	cout << "a = " << a << ", b = " << b << endl;

	swap(a,b);

	cout << "a = " << a << ", b = " << b << endl;
	return 0;
}

//            引用就是别名
void swap(int &rx, int &ry)
{
	int tmp;
	tmp = rx;
	rx = ry;
	ry = tmp;
}