#include <iostream>

using namespace std;

void SelectSort(int *a, const int n);

int main()
{
	int x[] = {1,3,5,7,9,0,2,4,6,8};
	SelectSort(x,10);

	for(int k=0; k<10; k++)
		cout << x[k] << endl;

	return 0;
}

void SelectSort(int *list, const int n)
{
	//           i<n
	for(int i=0; i<n-1; i++)
	{
		int min = i; //min就是毛巾,毛巾是数组的下标
		for(int j=i+1; j<n; j++)
		{
			if(list[j] < list[min])
				min = j;
		}
		swap(list[i],list[min]);
	}
}