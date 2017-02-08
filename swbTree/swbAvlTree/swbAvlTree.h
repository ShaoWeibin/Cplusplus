/** 
 * FileName: swbAvlTree.h
 * Author: ShaoWeibin
 * Data: 2013-11-28
 * Description: AVL(Adelson-Velskii and Landis) Tree
 * History:
 * CopyRight(C) 2013, ShaoWeibin
 */

template<typename Comparable>
class swbAvlTree
{
private:
	struct AvlNode
	{
		Comparable element;
		AvlNode* left;
		AvlNode* right;
		int height;

		AvlNode( const Comparable& e, AvlNode* lt, AvlNode* rt, int h = 0 )
			: element(e), left(lt), right(rt), height(h) { }
	};

	/** 
	 * AVL tree root.
	 */
	AvlNode* root;

public:
	swbAvlTree() : root(NULL) { }
	swbAvlTree( const swbAvlTree& rhs ) : root(NULL) { *this = rhs; }
	~swbAvlTree() { makeEmpty(); }

	/** 
	 * Deep copy.
	 */
	const swbAvlTree& operator= ( const swbAvlTree& rhs )
	{
		if (&rhs != this)
		{
			makeEmpty();
			root = clone(rhs.root);
		}

		return *this;
	}

public:
	/** 
	 * Return true if tree is empty.
	 */
	bool isEmpty( ) const { return NULL == root; }

	/** 
	 * method to make tree empty.
	 */
	void makeEmpty( ) { makeEmpty(root); }

	/** 
	 * Return the height of tree.
	 */
	int height( ) const { return height(root); }

	/** 
	 * Return true if x is found in the tree.
	 */
	bool contains( const Comparable& x ) const { return contains(x, root); }

	/** 
	 * Find minimum element.
	 */
	const Comparable& findMin( ) const { return findMin(root)->element; } 

	/** 
	 * Find maximum element.
	 */
	const Comparable& findMax( ) const { return findMax(root)->element; } 

	/** 
	 * Insert x into the tree; dupliccates are ignored.
	 */
	void insert( const Comparable& x ) { insert(x, root); }

	/** 
	 * Remove x from the tree. Nothing is done if x is not found.
	 */
	void remove( const Comparable& x ){ remove(x, root); }

	/** 
	 * method to print tree.
	 */
	void prefixPrint( ) const { prefixPrint(root); }
	void infixPrint( ) const { infixPrint(root); }
	void postfixPrint( ) const { postfixPrint(root); }

private:
	void makeEmpty( AvlNode* & t )
	{
		if (NULL != t)
		{
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}

		t = NULL;
	}

	/** 
	 * Internal method to test if an item is in a subtree.
	 * x is item to search for.
	 * t is the node that roots the subtree.
	 */
	bool contains( const Comparable& x, AvlNode* t ) const
	{
		if (NULL == t) return false;
		else if (x < t->element)
			return contains(x, t->left);
		else if (x > t->element)
			return contains(x, t->right);
		else return true;  // Match
	}

	/** 
	 * Internal method to find the minimum item in a subtree t.
	 * Return the node containing the minimum item.
	 */
	AvlNode* findMin( AvlNode* t ) const
	{
		/************************************************************************/
		/****************************Recursive***********************************/
		if (NULL == t) return NULL;
		if (NULL == t->left) return t;

		return findMin(t->left);
		/************************************************************************/

		/************************************************************************/
		/*****************************Non-Recursive******************************/
		/*if (NULL != t)
			while (NULL != t->left)
				t = t->left;

		return t;*/
		/************************************************************************/
	}

	/** 
	 * Internal method to find the maximum item in a subtree t.
	 * Return the node containing the maximum item.
	 */
	AvlNode* findMax( AvlNode* t ) const
	{
		/************************************************************************/
		/****************************Recursive***********************************/
		if (NULL == t) return NULL;
		if (NULL == t->right) return t;

		return findMax(t->right);
		/************************************************************************/

		/************************************************************************/
		/*****************************Non-Recursive******************************/
		/*if (NULL != t)
			while (NULL != t->right)
				t = t->right;

		return t;*/
		/************************************************************************/
	}

	/** 
	 * Return the height of node t or -1 if t is NULL.
	 */
	int height( AvlNode* t ) const
	{ return NULL == t ? -1 : t->height; }

	/** 
	 * Internal method to insert into a subtree.
	 * x is the item to insert.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.
	 */
	void insert( const Comparable& x, AvlNode* & t )
	{ 
		if (NULL == t)
			t = new AvlNode(x, NULL, NULL);
		else if (x < t->element)
		{
			insert(x, t->left);
			if (2 == height(t->left) - height(t->right))
			{
				if (x < t->left->element)
					rotateWithLeftChild(t);
				else
					doubleWithLeftChild(t);
			}
		}
		else if (x > t->element)
		{
			insert(x, t->right);
			if (2 == height(t->right) - height(t->left))
			{
				if (x > t->right->element)
					rotateWithRightChild(t);
				else
					doubleWithRightChild(t);
			}
		}
		else
			;  // Duplicate; do nothing

		t->height = max(height(t->left), height(t->right)) + 1;
	}

	/** 
	 * Internal method to remove a subtree.
	 * x is the item to remove.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.
	 */
	void remove( const Comparable& x, AvlNode* & t )
	{ 
		if (NULL == t) return;  // Item not found; do nothing.

		if (x < t->element)
		{
			remove(x, t->left);

			if (2 == height(t->right) - height(t->left))
			{
				rotateWithRightChild(t);
			}
		}
		else if (x > t->element)
		{
			remove(x, t->right);

			if (2 == height(t->left) - height(t->right))
			{
				rotateWithLeftChild(t);
			}
		}
		else if (NULL != t->left && NULL != t->right)
		{
			t->element = findMin(t->right)->element;
			remove(t->element, t->right);

			if (2 == height(t->left) - height(t->right))
			{
				rotateWithLeftChild(t);
			}
		}
		else  // One children or no Children.
		{
			AvlNode* oldNode = t;
			t = (NULL != t->left) ? t->left : t->right;
			delete oldNode;

			if (NULL == t) return;
		}

		t->height = max(height(t->left), height(t->right)) + 1;
	}

	/** 
	 * Rotate binary tree node with left child.
	 * For AVL trees, this is a single rotation for case 1.
	 * Update heights, then set new root.
	 */
	void rotateWithLeftChild( AvlNode* & k2 )
	{ 
		AvlNode* k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;

		k2->height = max(height(k2->left), height(k2->right)) + 1;
		k1->height = max(height(k1->left), k2->height) + 1;
		k2 = k1;
	}

	/** 
	 * Rotate binary tree node with right child.
	 * For AVL trees, this is a single rotation for case 4.
	 * Update heights, then set new root.
	 */
	void rotateWithRightChild( AvlNode* & k1 )
	{ 
		AvlNode* k2 = k1->right;
		k1->right = k2->left;
		k2->left = k1;

		k1->height = max(height(k1->left), height(k1->right)) + 1;
		k2->height = max(height(k2->right), k1->height) + 1;
		k1 = k2;
	}

	/** 
	 * Double rotate binary tree node: first left child
	 * with its right child; then node k3 with new left child.
	 * For AVL tree, this is a double rotation for case 2.
	 * Update heights, then set new root.
	 */
	void doubleWithLeftChild( AvlNode* & k3 )
	{ 
		rotateWithRightChild(k3->left);
		rotateWithLeftChild(k3);

		/*AvlNode *k1, *k2;
		k1 = k3->left;
		k2 = k1->right;

		k1->right = k2->left;
		k3->left = k2->right;
		k2->left = k1;
		k2->right = k3;

		k1->height = max(height(k1->left), height(k1->right)) + 1;
		k3->height = max(height(k3->left), height(k3->right)) + 1;
		k2->height = max(height(k1), height(k3)) + 1;*/
	}

	/** 
	 * Double rotate binary tree node: first right child
	 * with its left child; then node k1 with new right child.
	 * For AVL tree, this is a double rotation for case 3.
	 * Update heights, then set new root.
	 */
	void doubleWithRightChild( AvlNode* & k1 )
	{ 
		rotateWithLeftChild(k1->right);
		rotateWithRightChild(k1);

		/*AvlNode *k2, *k3;
		k3 = k1->right;
		k2 = k3->left;

		k3->left = k2->right;
		k1->right = k2->left;
		k2->left = k1;
		k2->right = k3;

		k1->height = max(height(k1->left), height(k1->right)) + 1;
		k3->height = max(height(k3->left), height(k3->right)) + 1;
		k2->height = max(height(k1), height(k3)) + 1;*/
	}

	/** 
	 * Internal method to print subtree.
	 */
	void prefixPrint( AvlNode* t ) const 
	{
		if (NULL != t)
		{
			printf("%d ", t->element);
			prefixPrint(t->left);
			prefixPrint(t->right);
		}
	}

	void infixPrint( AvlNode* t ) const 
	{
		if (NULL != t)
		{
			infixPrint(t->left);
			printf("%d ", t->element);
			infixPrint(t->right);
		}
	}

	void postfixPrint( AvlNode* t ) const 
	{
		if (NULL != t)
		{
			postfixPrint(t->left);
			postfixPrint(t->right);
			printf("%d ", t->element);
		}
	}

	/** 
	 * Internal method to clone subtree.
	 */
	AvlNode* clone( AvlNode* t ) const
	{
		if ( NULL == t) return NULL;
		
		return new AvlNode(t->element, clone(t->left), clone(t->right));
	}
};
