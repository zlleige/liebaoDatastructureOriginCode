#include <iostream>
#include "������.h"

using namespace std;

int main()
{
	BinaryTree<char> tree;
	TreeNode<char> ��,��,��,��,a,b,c,d,e;

	��.data = '+';
	��.data = '-';
	��.data = '*';
	��.data = '/';
	a.data = 'A';
	b.data = 'B';
	c.data = 'C';
	d.data = 'D';
	e.data = 'E';

	tree.root = &��;
	��.leftChild = &��;
	��.rightChild = &e;
	��.leftChild = &��;
	��.rightChild = &d;
	��.leftChild = &��;
	��.rightChild = &c;
	��.leftChild = &a;
	��.rightChild = &b;

	cout << "�������: ";
	tree.InOrder();//�������
	cout << endl;

	cout << "ǰ�����: ";
	tree.PreOrder();
	cout << endl;

	cout << "�������: ";
	tree.PostOrder();
	cout << endl;

	cout << "�������: ";
	tree.LevelOrder();
	cout << endl;
	return 0;
}