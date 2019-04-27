#ifndef RED_BLACK_TREE_H_
#define RED_BLACK_TREE_H_

#include "Except.h"

template <class Comparable>
class RedBlackTree;

template <class Comparable>
class RedBlackNode;

template <class Comparable>
class RedBlackTree
{
public:
	RedBlackTree(const Comparable & negInf);
	~RedBlackTree();

	enum {RED,BLACK};

	void insert(const Comparable & x);

	typedef RedBlackNode<Comparable> Node;
//private: 为了测试，临时变成public
public:
	Node *header;
	Node *nullNode;

	Node *current;
	Node *parent;	//父节点
	Node *grand;	//祖父节点
	Node *great;	//曾祖父节点

	void rotateWithLeftChild(Node * & k2) const;
	void rotateWithRightChild(Node * & k1) const;
	
	void doubleRotateWithLeftChild(Node * & k3) const;
	void doubleRotateWithRightChild(Node * & k1) const;

	void handleReorient(const Comparable & item);
	RedBlackNode<Comparable> * rotate(const Comparable & item, Node *parent) const;
};

template <class Comparable>
class RedBlackNode
{
//private: 为了测试，临时变成public
public:
	Comparable		element;
	RedBlackNode	*left;
	RedBlackNode	*right;
	int				color;

	RedBlackNode(const Comparable & theElement = Comparable(),
				RedBlackNode *lt = NULL,
				RedBlackNode *rt = NULL,
				int c = RedBlackTree<Comparable>::BLACK)
				: element(theElement),left(lt),right(rt),color(c){}

	friend class RedBlackTree<Comparable>;
};

template <class Comparable>
RedBlackTree<Comparable>::RedBlackTree(const Comparable & negInf)
{
	nullNode = new Node();
	nullNode->left = nullNode->right = nullNode;
	header = new Node(negInf);
	header->left = header->right = nullNode;
}

template <class Comparable>
RedBlackTree<Comparable>::~RedBlackTree()
{
	delete nullNode;
	delete header;
}

template <class Comparable>
void RedBlackTree<Comparable>::insert(const Comparable & x)
{
	current = parent = grand = header;
	nullNode->element = x;

	while(current->element != x)
	{
		great = grand; grand = parent; parent = current;
		current = x < current->element ? current->left : current->right;

		if(current->left->color == RED && current->right->color == RED)
			handleReorient(x);
	}

	if(current != nullNode)
		throw DuplicateItemException();
	
	current = new Node(x,nullNode,nullNode);
	if(x < parent->element)
		parent->left = current;
	else
		parent->right = current;

	handleReorient(x);
}

template <class Comparable>
void RedBlackTree<Comparable>::rotateWithLeftChild(Node * & k2) const
{
	Node *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2 = k1;
}

template <class Comparable>
void RedBlackTree<Comparable>::rotateWithRightChild(Node * & k1) const
{
	Node *k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1 = k2;
}

template <class Comparable>
void RedBlackTree<Comparable>::doubleRotateWithLeftChild(Node * & k3) const
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}

template <class Comparable>
void RedBlackTree<Comparable>::doubleRotateWithRightChild(Node * & k1) const
{
	rotateWithLeftChild(k1->right);
	rotateWithRightChild(k1);
}

template <class Comparable>
void RedBlackTree<Comparable>::handleReorient(const Comparable & item)
{
	//变色
	current->color = RED;
	current->left->color = BLACK;
	current->right->color = BLACK;

	if(parent->color == RED)
	{
		grand->color = RED;
		if(item < grand->element != item < parent->element)
			parent = rotate(item,grand);
		current = rotate(item,great);
		current->color = BLACK;
	}
	header->right->color = BLACK;
}

template <class Comparable>
RedBlackNode<Comparable> * RedBlackTree<Comparable>::rotate(const Comparable & item, Node * theParent) const
{
	if(item < theParent->element)
	{
		item < theParent->left->element ?
			rotateWithLeftChild(theParent->left) :
			rotateWithRightChild(theParent->left);
			return theParent->left;
	}
	else
	{
		item < theParent->right->element ?
			rotateWithLeftChild(theParent->right) :
			rotateWithRightChild(theParent->right);
			return theParent->right;
	}
}
#endif