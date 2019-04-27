#include <iostream>
#include "RedBlackTree.h"

using namespace std;

int main()
{
	const int NEG_INF = -99999;
	RedBlackTree<int> t(NEG_INF);

	t.insert(50);
	t.insert(40);
	t.insert(30);
	
	cout << t.header->right->element << endl;

	cout << "OK" << endl;
	system("pause");
	return 0;
}