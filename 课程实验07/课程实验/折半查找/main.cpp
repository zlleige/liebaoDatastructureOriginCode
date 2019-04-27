#include <iostream>

using namespace std;

int BinarySearch_I(int *a, const int x, const int n);
int BinarySearch_R(int *a, const int x, const int left, const int right);

int main()
{
	int m[] = {1,2,3,4,5,6,7,8,9};
	int ���;
	int num = 7;
	if((��� = BinarySearch_R(m,num,0,8))<0)
	{
		cout << "�ݹ��㷨: û�ҵ�!" << endl;
	}else{
		cout << "�ݹ��㷨: ��m[" << ��� << "]�ҵ�" << num << endl;
	}


	if((��� = BinarySearch_I(m,num,9))<0)
	{
		cout << "�����㷨: û�ҵ�!" << endl;
	}else{
		cout << "�����㷨: ��m[" << ��� << "]�ҵ�" << num << endl;
	}

	return 0;
}

int BinarySearch_I(int *a, const int x, const int n)
{
	int left = 0, right = n-1;
	while(left <= right)
	{
		int middle = (left+right)/2;
		if(x<a[middle]) right = middle-1;
		else if(x>a[middle]) left = middle + 1;
		else return middle;
	}
	return -1;
}

int BinarySearch_R(int *a, const int x, const int left, const int right)
{
	if(left<=right)
	{
		int middle = (left+right)/2;
		if(x<a[middle]) return BinarySearch_R(a,x,left,middle-1);
		else if(x>a[middle]) return BinarySearch_R(a,x,middle+1,right);
		else return middle;
	}
	return -1;
}