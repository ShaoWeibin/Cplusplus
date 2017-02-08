/** 
 * FileName:swb_list.h 
 * Author: ShaoWeibin
 * Data: 2013-10-16
 * Description: list
 * History:
 * CopyRight(C) 2013, ShaoWeibin
 */

#ifndef SWB_LIST_H
#define SWB_LIST_H

#ifndef DLL_EXP
#define DLL_EXP _declspec(dllexport)
#endif

template<typename Object>
class DLL_EXP swb_list
{
private:
	/* 
	 * Node struct
	 */
	struct Node
	{
		Object data;   // the data of current Node
		Node* prev;    // the pointer of previous Node 
		Node* next;    // the pointer of next Node 

		Node( const Object& d = Object(), Node* p = NULL, Node* n = NULL )
			: data(d), prev(p), next(n) { }
	};

public:
	/* 
	 * const_iterator class
	 */
	class const_iterator
	{
	public:
		const_iterator( ) : current(NULL) { }

		const Object* operator* ( ) const 
		{ return retrieve(); }

		const_iterator& operator++ ( )
		{
			current = current->next;
			return *this;
		}

		const_iterator operator++ ( int )
		{
			const_iterator old = *this;
			++( *this );
			return old;
		}

		const_iterator& operator-- ( )
		{
			current = current->prev;
			return *this;
		}

		const_iterator operator-- ( int )
		{
			const_iterator old = *this;
			--( *this );
			return old;
		}

		bool operator== ( const const_iterator& rhs ) const
		{ return current == rhs.current; }

		bool operator!= ( const const_iterator& rhs ) const
		{ return !( *this == rhs ); }

	protected:
		/* 
		 * retrieve current data
		 */
		Object& retrieve( ) const
		{ return current->data; }

		const_iterator ( Node* p ) : current(p) { }

	protected:
		Node* current;  // current Node

		friend class swb_list<Object>;
	};
	
	/* 
	 * iterator class
	 */
	class iterator : public const_iterator
	{
	public:
		iterator ( ) { }

		Object& operator* ( ) 
		{ return retrieve(); }

		const Object& operator* ( ) const
		{ return const_iterator::operator*(); }

		iterator& operator++ ( )
		{
			current = current->next;
			return *this;
		}

		iterator operator++ ( int )
		{
			iterator old = *this;
			++( *this );
			return old;
		}

		iterator& operator-- ( )
		{
			current = current->prev;
			return *this;
		}

		iterator operator-- ( int )
		{
			iterator old = *this;
			--( *this );
			return old;
		}

	protected:
		iterator ( Node* p ) : const_iterator(p) { }
		
		friend class swb_list<Object>;
	};

public:
	swb_list( ) { init(); }

	swb_list( const swb_list& rhs )
	{
		init();
		*this = rhs;
	}

	~swb_list( )
	{
		clear();
		delete head;
		delete tail;
	}

	const swb_list& operator= ( const swb_list& rhs )
	{
		if ( *this == rhs )
			return *this;

		clear();

		for ( const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr )
		{	push_back( *itr ); }

		return *this;
	}

	/* 
	 * begin
	 */
	iterator begin( )
	{ return iterator( head->next ); }

	const_iterator begin( ) const
	{ return const_iterator( head->next ); }

	/* 
	 * end
	 */
	iterator end( )
	{ return iterator( tail ); }

	const_iterator end( ) const
	{ return const_iterator( tail ); }

	/* 
	 * return the size of list
	 */
	int size( ) const
	{ return theSize; }

	/* 
	 * if theSize == 0, return true; else return false 
	 */
	bool empty( ) const 
	{ return size() == 0; }

	/* 
	 * clear the list
	 */
	void clear( )
	{
		while ( !empty() )
			pop_front();
	}

	/* 
	 * return front Object
	 */
	Object& front( )
	{ return *begin(); }

	const Object& front ( ) const
	{ return *begin(); }

	/* 
	 * return back Object
	 */
	Object& back( )
	{ return *( --end() ); }

	const Object& back ( ) const
	{ return *( --end() ); }

	/* 
	 * push an Object at the begin of list
	 */
	void push_front( const Object& x )
	{ insert( begin(), x ); }

	/* 
	 * push an Object at the end of list
	 */
	void push_back( const Object& x )
	{ insert( end(), x ); }

	/* 
	 * delete an Object at the begin of list
	 */
	void pop_front( )
	{ erase( begin() ); }

	/* 
	 * delete an Object at the end of list
	 */
	void pop_back( )
	{ erase( --end(); ); }

	/* 
	 * swap two item
	 */
	void swap( Node* p, Node* q )
	{ 
		p->prev->next = q;  // 让p的前一个节点指向q
		q->prev->next = q;  // 让q的前一个节点指向p

		// 交换next指针
		Node* temp = p->next;
		p->next = q->next;
		q->next = temp;

		// 交换prev指针
		temp = p->prev;
		p->prev = q->prev;
		q->prev = temp;
	}

	/* 
	 * insert x before itr
	 */
	iterator insert( iterator itr, const Object& x )
	{
		Node* p = itr.current;
		++theSize;
		return iterator( p->prev = p->prev->next = new Node( x, p->prev, p ) );
	}

	/* 
	 * erase item at itr
	 */
	iterator erase( iterator itr )
	{
		Node* p = itr.current;
		iterator retVal(p->next);
		p->prev->next = p->next;
		p->next->prev = p->prev;

		delete p;
		--theSize;

		return retVal;
	}

	iterator erase( iterator start, iterator end )
	{
		for ( iterator itr = start; itr != end; )
		{ itr = erase(itr);	}

		return itr;
	}

private:
	void init( )
	{
		theSize = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}

private:
	int theSize;    // the size of list
	Node* head;     // the head of list
	Node* tail;     // the tail of list
};

#endif