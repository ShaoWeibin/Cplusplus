/** 
 * FileName:swb_stack.h 
 * Author: ShaoWeibin
 * Data: 2013-10-17
 * Description: stack
 * History:
 * CopyRight(C) 2013, ShaoWeibin
 */

#ifndef SWB_STACK_H
#define SWB_STACK_H

#ifndef DLL_EXP
#define DLL_EXP _declspec(dllexport)
#endif

template <typename Object>
class DLL_EXP swb_stack
{
private:
	struct Node
	{ 
		Object data;   // the data of current Node
		Node* next;    // the pointer of next Node

		Node( const Object& d = Object(), Node* n = NULL )
			: data(d), next(n) { }
	};

public:
	swb_stack( ) : topNode ( new Node() ), theSize(0) { }

	swb_stack( const swb_stack& rhs )
		: topNode ( new Node() ), theSize(0)
	{ *this = rhs; }

	~swb_stack( )
	{
		clear();
	}

	const swb_stack& operator= ( const swb_stack& rhs )
	{
		if ( *this == rhs )
			return *this;

		clear();

		theSize = rhs.size(); 
		topNode = rhs.topNode;
	}

	bool operator== ( const swb_stack& rhs ) const
	{ return theSize == rhs.size() && topNode == rhs.topNode }

	bool operator!= ( const swb_stack& rhs ) const
	{ return theSize != rhs.size() || topNode != rhs.topNode }

	/* 
	 * push an Object
	 */
	void push(const Object & x)
	{
		Node* p = new Node(x, topNode);
		p->next = topNode;
		topNode = p;

		++theSize;
	}

	/* 
	 * delete top item
	 */
	void pop()
	{
		Node* old = topNode;
		topNode = topNode->next;

		delete old;
		--theSize;
	}

	/* 
	 * return top Object
	 */
	Object& top( )
	{	return topNode->data;	}

	const Object& top( ) const
	{	return topNode->data;	}

	/* 
	 * top and pop
	 */
	Object& topAndPop()
	{
		Object topItem = top();
		pop();
		return topItem;
	}

	/* 
	 * return stack size
	 */
	int size( ) const
	{ return theSize; };

	/* 
	 * if theSize == 0, return true; else return false
	 */
	bool empty( ) const
	{ return size() == 0; }

	/* 
	 * clear stack
	 */
	void clear( )
	{ 
		while ( !empty() )
			pop();
	}


private:
	int theSize;        // the size of stack
	Node* topNode;      // the top Node of stack
};

#endif