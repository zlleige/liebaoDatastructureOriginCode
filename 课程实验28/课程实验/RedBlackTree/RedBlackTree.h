#ifndef RED_BLACK_TREE_H_
#define RED_BLACK_TREE_H_

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

	typedef RedBlackNode<Comparable> Node;
private:
	Node *header;
	Node *nullNode;
};

template <class Comparable>
class RedBlackNode
{
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


#endif