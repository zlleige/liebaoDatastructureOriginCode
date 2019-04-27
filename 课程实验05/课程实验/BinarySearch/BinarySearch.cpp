#include <iostream>

using namespace std;

int BinarySearch(int *a, const int x, const int n);
int BinSearch(int *a, const int x, const int n);


int main()
{
	int x[] = {1,2,3,4,5,6,7,8,9,10};
	int 结果;
	int num;
	num = 6;
	结果 = BinSearch(x, num, 10);

	if(结果 < 0)
		cout << "没找到! " << endl;
	else
		cout << "在x[" << 结果 << "]找到" << num << endl;

	return 0;
}

int BinSearch(int *a, const int x, const int n)
{
	int left = 0, right = n-1;
	while(left<=right)
	{
		int middle = (left + right)/2;
		if(x < a[middle]) right = middle-1;
		else if(x > a[middle]) left=middle+1;
		else return middle;
	}
	return -1;
}

int BinarySearch(int *a, const int x, const int n)
{
	int low, high, mid;
	low = 0, high = n-1;

	while(low<=high)
	{
		mid = (low + high) / 2;
		if(a[mid] == x)
			return mid;
		else if(a[mid] < x)
			low = mid+1;
		else if(a[mid] > x)
			high = mid - 1;
	}

	return -1;
}