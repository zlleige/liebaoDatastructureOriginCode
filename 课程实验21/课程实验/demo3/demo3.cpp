#include <iostream>
#include <list>

using namespace std;

void PrintListContents(const list<int>& listInput);

int main()
{
	std::list<int> a;

	a.push_front(5);
	a.push_front(9);
	a.push_front(21);
	a.push_front(16);
	a.push_front(8);
	
	PrintListContents(a);

	a.sort();

	PrintListContents(a);

	a.reverse();
	PrintListContents(a);

	return 0;
}

void PrintListContents(const list<int>& listInput)
{
	cout << endl;
	cout << "{ ";
	std::list<int>::const_iterator iter;
	for(iter = listInput.begin(); iter != listInput.end(); ++iter)
		cout << *iter << " ";
	cout << "}" << endl;

}