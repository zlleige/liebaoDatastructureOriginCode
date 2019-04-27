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
	}

	if(current != nullNode)
		throw DuplicateItemException();
	
	current = new Node(x,nullNode,nullNode);
	if(x < parent->element)
		parent->left = current;
	else
		parent->right = current;
	//自动平衡 -> 红黑树
}

#endif