#include <iostream>

using namespace std;

void doA()
{
	cout << "Hello" << endl;
	doA();
}

void 老奶奶讲故事()
{
	cout << "从前有座山，山里有座庙，庙里有一个老和尚，老和尚在给小和尚讲故事: " << endl;	
	老奶奶讲故事();
}

// n! = n x (n-1)!
long 阶乘(int n)
{
	if(n==0)
		return 1;
	else
		return n * 阶乘(n-1);
}

long 阶乘2(int n)
{
	long 结果 = 1;
	for(int i=n; i>0; i--)
		结果 = 结果 * i;
	return 结果;
}

int main()
{
	//doA();
	//老奶奶讲故事();
	//cout << 阶乘(5) << endl;
	//cout << 阶乘2(5) << endl;
	for(int num=0; num < 10; num++)
	{
		cout << "递归: " << num << "! = " << 阶乘(num) << endl;
		cout << "迭代: " << num << "! = " << 阶乘2(num) << endl;
	}

	return 0;
}