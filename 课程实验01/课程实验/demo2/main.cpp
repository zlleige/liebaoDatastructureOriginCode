#include <iostream>

using namespace std;

void swap(int x, int y);

int main()
{
	int a,b;
	a = 1;
	b = 10;
	
	cout << "һ�����ɹ���swap����: " << endl;
	cout << "a = " << a << ", b = " << b << endl;

	//a��b����δ���ȥ��?
	//��ֵ����: ��a,b����һ��������ȥ
	swap(a,b); //���ݲ����ķ�ʽ

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