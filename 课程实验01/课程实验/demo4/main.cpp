#include <iostream>

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

using namespace std;

int main()
{
	int a, b, temp;
	a = 1;
	b = 10;

	cout << "使用宏定义函数: " << endl;
	cout << "a = " << a << ", b = " << b << endl;
	SWAP(a,b,temp);
	cout << "a = " << a << ", b = " << b << endl;

	return 0;
}