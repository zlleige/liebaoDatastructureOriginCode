#include <iostream>

using namespace std;

int SequentialSearch(int *a, const int n, const int x);

int main()
{
	int m[] = {2,4,6,8,0,1,3,5,7,9};
	int ���;

	int num = 75;

	��� = SequentialSearch(m,10,num);

	if(��� < 0)
		cout << "û�ҵ�!" << endl;
	else
		cout << "��m[" << ��� << "]���ҵ�" << num << endl;

	return 0;
}

int SequentialSearch(int *a, const int n, const int x)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(a[i] == x)
			return i;
	}
	if(i==n) return -1;
}