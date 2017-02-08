/** 
 * FileName:swb_queue.h 
 * Author: ShaoWeibin
 * Data: 2013-10-21
 * Description: queue
 * History:
 * CopyRight(C) 2013, ShaoWeibin
 */

#ifndef SWB_QUEUE_H
#define SWB_QUEUE_H

#ifndef DLL_EXP
#define DLL_EXP _declspec(dllexport)
#endif

template <typename Object>
class DLL_EXP swb_queue
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
	swb_queue( ) : theSize(0), front( new Node() ), back( new Node() ) { }

	swb_queue( const swb_queue& rhs )
		: theSize(0), front( new Node() ), back( new Node() )
	{ *this = rhs; }

	~swb_queue( ) { clear(); }

	const swb_queue& operator= ( const swb_queue& rhs )
	{
		if (*this == rhs)
			return *this;

		clear();

		theSize = rhs.size();
		front = rhs.front;
		back = rhs.back;
	}

	bool operator== ( const swb_queue& rhs ) const
	{ return theSize == rhs.size() && front == rhs.front && back == rhs.back }

	bool operator!= ( const swb_queue& rhs ) const
	{ return theSize != rhs.size() || front != rhs.front || back != rhs.back }

	/* 
	 * enqueue an Object
	 */
	void enqueue( const Object & x )
	{
		if ( size() == 0 )
		{
			Node* p = new Node( x, NULL );
			front = back = p;
		}
		else
		{
			Node* p = new Node( x, NULL );
			back->next = p;
			back = p;
		}

		++theSize;
	}

	/* 
	 * dequeue an Object
	 */
	Object& dequeue( )
	{
		Node* old = front;
		Object obj = old->data;

		front = front->next;

		delete old;
		--theSize;

		return obj;
	}

	/* 
	 * return queue size
	 */
	int size( ) const
	{ return theSize; };

	/* 
	 * if theSize == 0, return true; else return false
	 */
	bool empty( ) const
	{ return size() == 0; }

	/* 
	 * clear queue
	 */
	void clear( )
	{ 
		while ( !empty() )
			dequeue();
	}

private:
	Node* front;    // the front Node of queue
	Node* back;     // the back Node of queue
	int theSize;    // the size of stack
};

#endif