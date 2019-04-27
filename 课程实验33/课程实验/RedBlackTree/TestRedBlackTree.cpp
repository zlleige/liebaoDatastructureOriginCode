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
	
	//cout << t.header->right->element << endl;

	if(!t.isEmpty()) cout << "��������ǿյ�" << endl;

	t.makeEmpty();
	if(t.isEmpty()) cout << "������ǿյ�" << endl;

	t.insert(200);
	t.insert(100);
	t.insert(90);
	t.insert(50);
	t.insert(80);
	t.insert(70);
	t.insert(60);

	if(t.findMin().get() == 50) cout << "�ҵ�����С����" << endl;

	cout << "����: " << t.findMax().get() << endl;

	Cref<int> r = t.find(80);

	if(r.isNull())
	{
		cout << "û�ҵ�!" << endl;
	}
	else
	{
		cout << "�ҵ�: " << r.get() << endl;
	}

	cout << "OK" << endl;
	system("pause");
	return 0;
}