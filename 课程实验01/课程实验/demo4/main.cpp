#include <iostream>

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

using namespace std;

int main()
{
	int a, b, temp;
	a = 1;
	b = 10;

	cout << "ʹ�ú궨�庯��: " << endl;
	cout << "a = " << a << ", b = " << b << endl;
	SWAP(a,b,temp);
	cout << "a = " << a << ", b = " << b << endl;

	return 0;
}