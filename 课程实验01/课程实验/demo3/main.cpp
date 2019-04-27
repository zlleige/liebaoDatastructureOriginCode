#include <iostream>

using namespace std;

void swap(int *px, int *py);

int main()
{
	int a,b;
	a = 1;
	b = 10;
	cout << "传指针的方法: " << endl;

	cout << "a = " << a << ", b = " << b << endl;

	//   拷贝的指针(地址)
	swap(&a,&b);
	cout << "a = " << a << ", b = " << b << endl;

	return 0;
}

void swap(int *px, int *py)
{
	int temp;

	temp = *px;
	*px = *py;
	*py = temp;
}