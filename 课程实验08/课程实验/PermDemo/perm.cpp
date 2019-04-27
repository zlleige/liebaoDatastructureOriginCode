#include <iostream>

using namespace std;

int c1 = 0;
int c2 = 0;

void show(char *p, int m)
{
	for(int i=0; i<=m; i++)
		cout << p[i];
	cout << endl;
}

void Permutations(char *p, const int k, const int m)
{
	cout << "c1 = " << ++c1 << endl;
	if(k==m)
	{
		for(int i=0;i<=m; i++)
			cout << p[i];
		cout << endl;
	}
	else
	{
		for(int i=k; i<=m; i++)
		{
			cout << "递归前, 交换前: ";
			show(p,m);
			swap(p[k],p[i]);
			cout << "递归前, 交换后: ";
			show(p,m);
			Permutations(p,k+1,m);
			cout << "c2 = " << ++c2 << endl;
			cout << "递归后, 交换前: ";
			show(p,m);
			swap(p[k],p[i]);
			cout << "递归后，交换后: ";
			show(p,m);
		}
	}
}

int main()
{
	char s[] = "abc";
	Permutations(s,0,2);
	system("pause");
	return 0;
}