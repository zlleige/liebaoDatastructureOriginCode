#include <iostream>

using namespace std;

void swap(int &rx, int &ry);

int main()
{
	int a,b;
	a = 1;
	b = 10;
	cout << "������: " << endl;
	cout << "a = " << a << ", b = " << b << endl;

	swap(a,b);

	cout << "a = " << a << ", b = " << b << endl;
	return 0;
}

//            ���þ��Ǳ���
void swap(int &rx, int &ry)
{
	int tmp;
	tmp = rx;
	rx = ry;
	ry = tmp;
}