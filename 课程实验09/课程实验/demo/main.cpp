#include <iostream>

using namespace std;

template<class T>
void InsertionSort(T *a, int n);

template<class T>
void InsertionSort_2(T *a, int n);

template<class T>
void Insert(const T& e, T *a, int i);

int main()
{
	double x[] = {2.2, 4.5, 6.6, 8, 0, 1,3,5,7,9};
	int y[] = {0,2,4,6,8,0,1,3,5,7,9};
	InsertionSort(x,10);
	InsertionSort_2(y,10);

	for(int i=1;i<=10;++i)
		cout << y[i] << endl;

	return 0;
}

template<class T>
void InsertionSort(T *a, int n)
{
	int in, out;
	// 开始时out=0这个人已经出去了
	for(out=1;out<n;++out)
	{
		T temp = a[out];
		in = out;
		while(in>0 && a[in-1]>=temp)
		{
			a[in] = a[in-1];
			--in;
		}
		a[in] = temp;
	}
}

template<class T>
void InsertionSort_2(T *a, int n)
{
	//a[0]用来保存排序使用，不能保存原始数据
	for(int j=2; j<=n; ++j) 
	{
		T temp = a[j];
		Insert(temp,a,j-1);
		//a[0] = temp;
		//int i = j-1;
		//while(temp <a[i])
		//{
		//	a[i+1] = a[i];
		//	i--;
		//}
		//a[i+1] = temp;
	}
}

template<class T>
void Insert(const T& e, T *a, int i)
{
	a[0] = e;
	while(e<a[i])
	{
		a[i+1] = a[i];
		i--;
	}
	a[i+1] = e;
}
