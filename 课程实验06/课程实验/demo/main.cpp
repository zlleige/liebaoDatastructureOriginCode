#include <iostream>

using namespace std;

void doA()
{
	cout << "Hello" << endl;
	doA();
}

void �����̽�����()
{
	cout << "��ǰ����ɽ��ɽ��������������һ���Ϻ��У��Ϻ����ڸ�С���н�����: " << endl;	
	�����̽�����();
}

// n! = n x (n-1)!
long �׳�(int n)
{
	if(n==0)
		return 1;
	else
		return n * �׳�(n-1);
}

long �׳�2(int n)
{
	long ��� = 1;
	for(int i=n; i>0; i--)
		��� = ��� * i;
	return ���;
}

int main()
{
	//doA();
	//�����̽�����();
	//cout << �׳�(5) << endl;
	//cout << �׳�2(5) << endl;
	for(int num=0; num < 10; num++)
	{
		cout << "�ݹ�: " << num << "! = " << �׳�(num) << endl;
		cout << "����: " << num << "! = " << �׳�2(num) << endl;
	}

	return 0;
}