/** 
 * FileName: swbSet.h
 * Author: ShaoWeibin
 * Data: 2013-12-06
 * Description: Set, using Binary Search Tree.
 * History:
 * CopyRight(C) 2013, ShaoWeibin
 */

#ifndef SWB_SET_H
#define SWB_SET_H

template<typename Comparable>
class swbSet
{
private:
	/************************************************************************/
	/****************************BinaryNode**********************************/
	struct BinaryNode
	{
		Comparable element;
		BinaryNode* left;
		BinaryNode* right;
		BinaryNode* parent;

		BinaryNode( ) : left(NULL), right(NULL), parent(NULL) { }
		BinaryNode( Comparable& e ) : element(e), left(NULL), right(NULL), parent(NULL) { }
		BinaryNode( const Comparable& e, BinaryNode* lt, BinaryNode* rt, BinaryNode* pt )
			: element(e), left(lt), right(rt), parent(pt) { }
	};
	/************************************************************************/

public:
	/************************************************************************/
	/***************************const_iterator*******************************/
	class const_iterator
	{
	public:
		const_iterator( ) : current(NULL) { }
		const_iterator( BinaryNode* p ) : current(p) { }

		/** 
		 * operator*
		 */ 
		const Comparable& operator* ( ) const { return retrieve(); }
		bool operator== ( const const_iterator& rhs ) const 
		{ return current == rhs.current; }
		bool operator!= ( const const_iterator& rhs ) const
		{ return !(*this == rhs); }

		/** 
		 * operator>
		 */ 
		bool operator> ( const const_iterator& rhs ) const
		{
			if (NULL == rhs.current)
				return false;
			else if (retrieve() > rhs.retrieve())
				return true;
			else
				return false;
		}

		/** 
		 * operator<
		 */
		bool operator< ( const const_iterator& rhs ) const
		{
			if (NULL == rhs.current)
				return false;
			else if (retrieve() < rhs.retrieve())
				return true;
			else
				return false;
		}

		/** 
		 * prefix operator++
		 */ 
		const_iterator& operator++ ( ) 
		{
			BinaryNode* t;

			if (NULL == current) return *this;

			if (current->right)
			{
				t = current->right;
				while (NULL != t->left)
					t = t->left;
				current = t;
			} 
			else
			{
				t = current->parent;
				while (t && t->element < current->element)
					t = t->parent;
				current = t;
			}

			return *this;
		}
		/** 
		 * suffix operator++
		 */ 
		const_iterator& operator++ ( int ) 
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}

	protected:
		Comparable& retrieve( ) const { return current->element; }

	protected:
		BinaryNode* current;

		friend class swbSet;
	};
	/************************************************************************/

	/************************************************************************/
	/*********************************iterator*******************************/
	class iterator : public const_iterator
	{
	public:
		iterator ( ) { }
		iterator (BinaryNode* p) : const_iterator(p) { }
		
		/** 
		 * operator*
		 */ 
		Comparable& operator* ( ) { return const_iterator::retrieve(); }
		const Comparable& operator* ( ) const { return const_iterator::operator *(); }

		/** 
		 * prefix operator++
		 */
		iterator& operator++ ( ) 
		{
			BinaryNode* t;

			if (NULL == current) return *this;

			if (current->right)
			{
				t = current->right;
				while (NULL != t->left)
					t = t->left;
				current = t;
			} 
			else
			{
				t = current->parent;
				while (t && t->element < current->element)
					t = t->parent;
				current = t;
			}

			return *this;
		}

		/** 
		 * suffix operator++
		 */
		iterator& operator++ ( int ) 
		{
			iterator old = *this;
			++(*this);
			return old;
		}

		friend class swbSet;
	};
	/************************************************************************/

	public:
		swbSet( ) : root(NULL), theSize(0) { }
		swbSet( const swbSet& rhs ) : root(NULL), theSize(0) 
		{ 
			*this = rhs; 
			theSize = rhs.theSize(); 
		}
		~swbSet( ) { clear(root); }

		/** 
		 * Deep copy.
		 */
		const swbSet& operator= ( const swbSet& rhs )
		{
			if (&rhs != this)
			{
				clear();
				root = clone(rhs.root);
			}

			return *this;
		}

	public:
		/** 
		* Return the size of tree.
		*/
		int size( ) const { return theSize; }

		/** 
		* Return true if tree is empty.
		*/
		bool empty( ) const { return size() == 0; }

		/** 
		 * method to make tree empty.
		 */
		void clear( ) { clear(root); }

		/** 
		 * Find maximum element.
		 */
		const Comparable& finMax( ) const { return finMax(root); }

		/** 
		 * Find minimum element.
		 */
		const Comparable& finMin( ) const { return finMin(root); }

		iterator begin ( )
		{
			BinaryNode* t = root;

			if (NULL == t) return iterator(t);

			while (t->left)
				t = t->left;

			return iterator(t);
		}

		const_iterator begin( ) const
		{
			BinaryNode* t = root;
			while (t->left)
				t = t->left;

			return const_iterator(t);
		}

		iterator end ( )
		{
			BinaryNode* t = root;

			if (NULL == t) return iterator(t);

			while (t->right)
				t = t->right;

			return ++iterator(t);
		}

		const_iterator end ( ) const
		{
			BinaryNode* t = root;
			while (t->right)
				t = t->right;

			return const_iterator(++t);
		}

		iterator insert( const Comparable& x )
		{
			++theSize;
			return insert(x, root, root);
		}

		iterator erase( const Comparable& x )
		{
			if (0 == size()) return end();

			return erase(x, root, root);
		}

		iterator erase( iterator& itr )
		{
			if (0 == size()) return end();

			return erase(itr, root, root);
		}

	private:
		void clear( BinaryNode* & t )
		{
			if (NULL != t)
			{
				clear(t->left);
				clear(t->right);
				delete t;
			}

			theSize = 0;
			t = NULL;
		}

		/** 
		 * Internal method to find the minimum item in a subtree t.
		 * Return the node containing the minimum item.
		 */
		BinaryNode* findMin( BinaryNode* t ) const
		{
			if (NULL == t) return NULL;
			if (NULL == t->left) return t;

			return findMin(t->left);
		}

		/** 
		 * Internal method to find the maximum item in a subtree t.
		 * Return the node containing the maximum item.
		 */
		BinaryNode* findMax( BinaryNode* t ) const
		{
			if (NULL == t) return NULL;
			if (NULL == t->right) return t;

			return findMax(t->right);
		}

		/** 
		 * Insert.
		 * p: parent node.
		 * Return insert position's iterator.
		 */
		iterator insert( const Comparable& x, BinaryNode* & t, BinaryNode* p )
		{
			if (NULL == t)
			{
				t = new BinaryNode(x, NULL, NULL, p);
				return iterator(t);
			}
			else if (x < t->element)
				return insert(x, t->left, t);
			else if (x > t->element)
				return insert(x, t->right, t);

			return iterator(t);
		}

		/** 
		 * erase
		 * p: parent node.
		 * Return the next of insert position's iterator.
		 */
		iterator erase( const Comparable& x, BinaryNode* & t, BinaryNode* p )
		{
			if (NULL == t) return end();

			iterator itr;

			if (x < t->element)
				erase(x, t->left, t);
			else if (x > t->element)
				erase(x, t->right, t);
			else if (NULL != t->left && NULL != t->right)  // Two children
			{
				t->element = findMin(t->right)->element;
				erase(t->element, t->right, t);
			}
			else  // One children or no Children.
			{
				BinaryNode* oldNode = t;
				itr = ++iterator(t);
				t = (NULL != t->left) ? t->left : t->right;
				if (t) t->parent = NULL;

				--theSize;
				delete oldNode;
			}

			return itr;
		}

		/** 
		 * erase
		 * p: parent node.
		 * Return the next of insert position's iterator.
		 */
		iterator erase( iterator& itr, BinaryNode* & t, BinaryNode* p )
		{
			if (NULL == t) return end();

			if (*itr < t->element)
				erase(itr, t->left, t);
			else if (*itr > t->element)
				erase(itr, t->right, t);
			else if (NULL != t->left && NULL != t->right)  // Two children
			{
				t->element = findMin(t->right)->element;
				itr = iterator(findMin(t->right));
				erase(itr, t->right, t);
			}
			else  // One children or no Children.
			{
				BinaryNode* oldNode = t;
				itr = ++iterator(t);
				t = (NULL != t->left) ? t->left : t->right;
				if (t) t->parent = NULL;

				--theSize;
				delete oldNode;
			}

			return itr;
		}

		/** 
		 * Internal method to clone subtree.
		 */
		swbSet* clone( BinaryNode* t ) const
		{
			if ( NULL == t) return NULL;
			
			return new BinaryNode(t->element, clone(t->left), clone(t->right), clone(t->parent));
		}

	private:
		BinaryNode* root;
		int theSize;
};

#endif  // SWB_SET_H