#include <iostream>
#include "ThreeLetterList.h"

using namespace std;

class NodeB;

class NodeA
{
private:
	int data1; //����������
	char data2;
	float data3;

	NodeA *linka;
	NodeB *linkb;
};

class NodeB
{
private:
	int data;
	NodeB *link;
};

class List;

class Node //�ڵ�
{
friend class List; //��Ԫ��
private:
	int data; //�ڵ��������
	Node* link; //ָ����һ���ڵ��ָ��
};

class List //����
{
public:
	void test();
	void show();
private:
	Node* first;//ָ���һ���ڵ��ָ��
};

void List::show()
{
	cout << first->data << " -> "
		<< first->link->data << " -> "
		<< first->link->link->data << endl;
}

void List::test()
{
	Node *f = new Node();
	f->data = 44;
	f->link = 0;

	first = f;

	f = new Node();
	f->data = 72;
	f->link = 0;

	first->link = f;

	f = new Node();
	f->data = 210;
	f->link = 0;

	first->link->link = f;
}

int main()
{
	List a;
	a.test(); //���������ڵ�
	a.show();


	ThreeLetterList l;
	l.test();
	l.show();

	return 0;
}