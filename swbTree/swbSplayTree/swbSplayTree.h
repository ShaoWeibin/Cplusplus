/** 
 * FileName: swbSplayTree.h
 * Author: ShaoWeibin
 * Data: 2013-12-23
 * Description: Splay Tree
 * History:
 * CopyRight(C) 2013, ShaoWeibin
 */
#ifndef SWB_SPLAY_TREE
#define SWB_SPLAY_TREE

template <typename Comparable>
class swbSplayTree
{
	struct BinaryNode
	{
		Comparable element;
		BinaryNode* left;
		BinaryNode* right;

		BinaryNode( const Comparable& theElement = Comparable(), BinaryNode* lt = NULL, BinaryNode* rt = NULL )
			: element(theElement), left(lt), right(rt) { }
	};

	BinaryNode* root;
	BinaryNode* nullNode;

public:
	swbSplayTree( )
	{
		nullNode = new BinaryNode;
		nullNode->left = nullNode->right = nullNode;
		root = nullNode;
	}

	swbSplayTree( const swbSplayTree& rhs )
	{
		nullNode = new BinaryNode;
		nullNode->left = nullNode->right = nullNode;
		root = nullNode;

		*this = rhs;
	}

	~swbSplayTree( )
	{
		makeEmpty();
		delete nullNode;
	}

	const swbSplayTree& operator= ( const swbSplayTree& rhs )
	{
		if (&rhs != this)
		{
			makeEmpty();
			root = clone(rhs.root);
		}

		return *this;
	}



	/** 
	 * Find minimum element.
	 */
	const Comparable& findMin( ) const { return findMin(root)->element; } 

	/** 
	 * Find maximum element.
	 */
	const Comparable& findMax( ) const { return findMax(root)->element; } 

	/** 
	 * Find node containing the item.
	 */
	BinaryNode* find(const Comparable& x) const { return find(x, root); }

	/** 
	 * Return true if x is found in the tree.
	 */
	bool contains( const Comparable& x ) const { return contains(x, root); }
	
	/** 
	 * Return true if tree is empty.
	 */
	bool isEmpty( ) const { return nullNode == root; }

	/** 
	 * method to make tree empty.
	 */
	void makeEmpty( ) { makeEmpty(root); }

	/** 
	 * method to print tree.
	 */
	void prefixPrint( ) const { prefixPrint(root); }
	void infixPrint( ) const { infixPrint(root); }
	void postfixPrint( ) const { postfixPrint(root); }

	/** 
	 * Insert x into the tree; dupliccates are ignored.
	 */
	void insert( const Comparable& x ) { insert(x, root); }

	/** 
	 * Remove x from the tree. Nothing is done if x is not found.
	 */
	void remove( const Comparable& x ){ remove(x, root); }

private:
	/** 
	 * Internal method to find the minimum item in a subtree t.
	 * Return the node containing the minimum item.
	 */
	BinaryNode* findMin( BinaryNode* t ) const
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
	BinaryNode* findMax( BinaryNode* t ) const
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
	 * Internal method to find the node in a subtree t.
	 * Return the node containing the item.
	 */
	BinaryNode* find( const Comparable& x, BinaryNode* & t )
	{
		splay(x, t);
		if (t->element == x)
			return t;
		else 
			return NULL;
	}

	/** 
	 * Internal method to make subtree empty.
	 */
	void makeEmpty( BinaryNode* & t )
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
	bool contains( const Comparable& x, BinaryNode* t ) const
	{
		if (NULL == t) return false;
		else if (x < t->element)
			return contains(x, t->left);
		else if (x > t->element)
			return contains(x, t->right);
		else return true;  // Match
	}

	/** 
	 * Internal method to print subtree.
	 */
	void prefixPrint( BinaryNode* t ) const 
	{
		if (NULL != t)
		{
			printf("%d ", t->element);
			prefixPrint(t->left);
			prefixPrint(t->right);
		}
	}

	void infixPrint( BinaryNode* t ) const 
	{
		if (NULL != t)
		{
			infixPrint(t->left);
			printf("%d ", t->element);
			infixPrint(t->right);
		}
	}

	void postfixPrint( BinaryNode* t ) const 
	{
		if (NULL != t)
		{
			postfixPrint(t->left);
			postfixPrint(t->right);
			printf("%d ", t->element);
		}
	}

	/** 
	 * Internal method to insert into a subtree.
	 * x is the item to insert.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.
	 */
	void insert( const Comparable& x, BinaryNode* & t )
	{ 
		static BinaryNode* newNode = NULL;

		if (NULL == newNode)
			newNode = new BinaryNode;
		newNode->element = x;

		if (nullNode == t)
		{
			newNode->left = newNode->right = nullNode;
			t = newNode;
		}
		else
		{
			splay(x, t);
			if (x < t->element)
			{
				newNode->left = t->left;
				newNode->right = t;
				t->left = nullNode;
				t = newNode;
			}
			else if (x > t->element)
			{
				newNode->right = t->right;
				newNode->left = t;
				t->right = nullNode;
				t = newNode;
			}
			else return;
		}
		newNode = NULL;  // So next insert will call new.
	}
	
	/** 
	 * Internal method to remove from a subtree.
	 * x is the item to remove.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.
	 */
	void remove( const Comparable& x, BinaryNode* & t )
	{
		BinaryNode* newNode;

		if (NULL == t) return;  // Item not found; do nothing.
		
		splay(x, t);
		if (t->element == x)
		{
			if (NULL == t->left)
				newNode = t->right;
			else
			{
				newNode = t->left;
				splay(x, newNode);
				newNode->right = t->right;
			}
			delete t;
			t = newNode;
		}
	}

	/** 
	 * Rotate binary tree node with left child.
	 * For AVL trees, this is a single rotation for case 1.
	 * Update heights, then set new root.
	 */
	void rotateWithLeftChild( BinaryNode* & k2 )
	{ 
		BinaryNode* k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;

		k2 = k1;
	}

	/** 
	 * Rotate binary tree node with right child.
	 * For AVL trees, this is a single rotation for case 4.
	 * Update heights, then set new root.
	 */
	void rotateWithRightChild( BinaryNode* & k1 )
	{ 
		BinaryNode* k2 = k1->right;
		k1->right = k2->left;
		k2->left = k1;

		k1 = k2;
	}

	/** 
	 * Internal method to perform a top-down splay.
	 * The last accessed node becomes the new root.
	 * This method may be overridden to use a different
	 * splaying algorithm, however, the splay tree code
	 * depends on the accessed item going to the root.
	 * x is the target item to splay around.
	 * t is the root of the subtree to splay.
	 */
	void splay( const Comparable& x, BinaryNode* & t )
	{
		BinaryNode *leftTreeMax, *rightTreeMin;
		static BinaryNode header;

		header.left = header.right = nullNode;
		leftTreeMax = rightTreeMin = &header;

		nullNode->element = x;  // Guarantee a match.

		for (; ;)
		{
			if (x < t->element)
			{
				if (x < t->left->element)
					rotateWithLeftChild(t);
				if (nullNode == t->left)
					break;
				// Link Right
				rightTreeMin->left = t;
				rightTreeMin = t;
				t = t->left;
			}
			else if (x > t->element)
			{
				if (x > t->right->element)
					rotateWithRightChild(t);
				if (nullNode == t->right)
					break;
        // Link Left
				leftTreeMax->right = t;
				leftTreeMax = t;
				t = t->right;
			}
			else break;
		}

		leftTreeMax->right = t->left;
		rightTreeMin->left = t->right;
		t->left = header.right;
		t->right = header.left;
	}

	/** 
	 * Internal method to clone subtree.
	 */
	BinaryNode* clone( BinaryNode* t ) const
	{
		if ( NULL == t) return NULL;
		
		return new BinaryNode(t->element, clone(t->left), clone(t->right));
	}
};

#endif  // SWB_SPLAY_TREE