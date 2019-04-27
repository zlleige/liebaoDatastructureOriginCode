#include <iostream>

using namespace std;

void swap(int x, int y);

int main()
{
	int a,b;
	a = 1;
	b = 10;
	
	cout << "一个不成功的swap方法: " << endl;
	cout << "a = " << a << ", b = " << b << endl;

	//a和b是如何传进去的?
	//按值传递: 把a,b拷贝一个，传进去
	swap(a,b); //传递参数的方式

	cout << "a = " << a << ", b = " << b << endl;
	return 0;
}

void swap(int x, int y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;
}