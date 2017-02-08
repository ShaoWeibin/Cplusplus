/** 
 * FileName: swbBinarySearchTree.h
 * Author: ShaoWeibin
 * Data: 2013-11-20
 * Description: Binary Search Tree
 * History:
 * CopyRight(C) 2013, ShaoWeibin
 */

#ifndef SWB_BINARY_SEARCH_TREE_H
#define SWB_BINARY_SEARCH_TREE_H

template<typename Comparable>
class swbBinarySearchTree
{
private:
	/** 
	 * Binary node struct.
	 */
	struct BinaryNode
	{
		Comparable element;
		BinaryNode* left;
		BinaryNode* right;

		BinaryNode( const Comparable& theElement, BinaryNode* lt, BinaryNode* rt )
			: element(theElement), left(lt), right(rt) { }
	};

	/** 
	 * Binary search tree root.
	 */
	BinaryNode* root;

public:
	swbBinarySearchTree( ) : root(NULL) { }
	swbBinarySearchTree( const swbBinarySearchTree& rhs ) : root(NULL) { *this = rhs; }
	~swbBinarySearchTree( ) { makeEmpty(); }

	/** 
	 * Deep copy.
	 */
	const swbBinarySearchTree& operator= ( const swbBinarySearchTree& rhs )
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
	 * Return true if x is found in the tree.
	 */
	bool contains( const Comparable& x ) const { return contains(x, root); }
	
	/** 
	 * Return true if tree is empty.
	 */
	bool isEmpty( ) const { return NULL == root; }

	/** 
	 * method to print tree.
	 */
	void prefixPrint( ) const { prefixPrint(root); }
	void infixPrint( ) const { infixPrint(root); }
	void postfixPrint( ) const { postfixPrint(root); }

	/** 
	 * method to make tree empty.
	 */
	void makeEmpty( ) { makeEmpty(root); }

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

	/*
	** Count nodes number.
	*/
	int countNodes(BinaryNode* t)
	{
		if (NULL == t) return 0;
		return 1 + countNodes(t->left) + countNodes(t->right);
	}

	/*
	** Count Leave node number.
	*/
	int countLeaves(BinaryNode* t)
	{
		if (NULL == t) return 0;
		else if (NULL == t->left && NULL == t->right)
			return 1;

		return countLeaves(t->left) + countLeaves(t->right);
	}

	/*
	** Count Full node number.
	*/
	int countFull(BinaryNode* t)
	{
		if (NULL == t) return 0;
		int isFull = (NULL != t->left && NULL != t->right) ? 1 : 0;
		return isFull + countFull(t->left) + countFull(t->right);
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
	 * Internal method to insert into a subtree.
	 * x is item to insert.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.
	 */
	void insert( const Comparable& x, BinaryNode* & t ) const
	{
		if (NULL == t)
			t = new BinaryNode(x, NULL, NULL);
		else if (x < t->element)
			insert(x, t->left);
		else if (x > t->element)
			insert(x, t->right);
		else 
			;  // Duplicate; do nothing
	}

	/** 
	 * Internal method to remove from a subtree.
	 * x is the item to remove.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.
	 */
	void remove( const Comparable& x, BinaryNode* & t ) const
	{
		if (NULL == t) return;  // Item not found; do nothing.

		if (x < t->element)
			remove(x, t->left);
		else if (x > t->element)
			remove(x, t->right);
		else if (NULL != t->left && NULL != t->right)  // Two children
		{
			t->element = findMin(t->right)->element;
			remove(t->element, t->right);
		}
		else  // One children or no Children.
		{
			BinaryNode* oldNode = t;
			t = (NULL != t->left) ? t->left : t->right;
			delete oldNode;
		}
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

#endif  // SWB_BINARY_SEARCH_TREE_H