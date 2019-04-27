#ifndef ���������_H
#define ���������_H

#include <iostream>

enum Boolean {FALSE, TRUE};

template<class Type>
class Element
{
public:
	Type key;
	//��Ӹ��������
};

template<class Type> class BST; //ǰ������

template<class Type>
class BstNode //���ڵ�
{
	friend class BST<Type>;
//private:
public:
	Element<Type> data;
	BstNode* LeftChild;
	BstNode* RightChild;
	void display(int i);
};

template<class Type>
class BST
{
public:
	BST(BstNode<Type> *init = 0)
	{
		root = init;
	}

	Boolean Insert(const Element<Type>& x);
	//Ҫ���� Delete
	//Ҫ���� InOrder
	//		 PreOrder
	//		 PostOrder
	BstNode<Type>* Search(const Element<Type>& x);
	BstNode<Type>* Search(BstNode<Type>*, const Element<Type>&);
	BstNode<Type>* IterSearch(const Element<Type>&);
	void display()
	{
		cout << "\n";
		if(root)
			root->display(1);
		else
			cout << "����һ�ÿ���\n";
	}
private:
	BstNode<Type> *root;
};

template<class Type>
void BstNode<Type>::display(int i)
{
	std::cout << "Position: " << i << ", data.key = " << data.key << "\n";
	if(LeftChild) LeftChild->display(2*i);
	if(RightChild) RightChild->display(2*i+1);
}

template<class Type>
Boolean BST<Type>::Insert(const Element<Type> &x)
{
	BstNode<Type> *p = root;
	BstNode<Type> *q = 0; //qָ��p�ĸ��ڵ�
	//insert֮ǰҪ�Ȳ���
	while(p)
	{
		q = p;
		if(x.key == p->data.key) return FALSE; //�����ظ���ʧ�ܷ���FALSE
		if(x.key < p->data.key) 
			p = p->LeftChild;
		else 
			p = p->RightChild;
	}

	//�ҵ���λ�þ���q
	p = new BstNode<Type>;
	p->LeftChild = p->RightChild = 0;
	p->data = x;
	if(!root) root = p;
	else if(x.key < q->data.key) q->LeftChild = p;
	else q->RightChild = p;
	return TRUE;
}


template<class Type>
BstNode<Type>* BST<Type>::Search(const Element<Type> &x)
{
	return Search(root,x);
}

template<class Type>
BstNode<Type>* BST<Type>::Search(BstNode<Type> * b, const Element<Type> &x)
{
	if(!b) return 0;
	if(x.key == b->data.key) return b;
	if(x.key < b->data.key) return Search(b->LeftChild,x);
	return Search(b->RightChild,x);
}

template<class Type>
BstNode<Type>* BST<Type>::IterSearch(const Element<Type> &x)
{
	for(BstNode<Type>* t = root; t; )
	{
		if(x.key == t->data.key) return t;
		if(x.key < t->data.key)
			t = t->LeftChild;
		else
			t = t->RightChild;
	}
	return 0;
}

#endif