/** 
 * FileName:swb_vector.h 
 * Author: ShaoWeibin
 * Data: 2013-10-15
 * Description: vector
 * History:
 * CopyRight(C) 2013, ShaoWeibin
 */

#ifndef SWB_VECTOR_H
#define SWB_VECTOR_H

#ifndef DLL_EXP
#define DLL_EXP _declspec(dllexport)
#endif

template<typename Object>
class DLL_EXP swb_vector
{
public:
	typedef Object* iterator;
	typedef const Object* const_iterator;

public:
	explicit swb_vector(int initSize = 0)
		: theSize(initSize)
		, theCapacity(initSize + SPACE_CAPACITY)
	{
		objects = new Object[theCapacity];
	}

	explicit swb_vector(int initSize, const Object x)
		: theSize(initSize)
		, theCapacity(initSize + SPACE_CAPACITY)
	{
		objects = new Object[theCapacity];

		for (int i = 0; i < initSize; ++i)
			objects[i] = x;
	}

	swb_vector(const swb_vector& rhs)
		: objects(NULL)
	{
		operator= (rhs);
	}

	~swb_vector()
	{
		delete[] objects;
	}

public:
	/* 
	 * operator=
	 */
	const swb_vector& operator= (const swb_vector& rhs)
	{
		if (this != rhs)
		{
			delete[] objects;
			theSize = rhs.size();
			theCapacity = rhs.capacity();

			objects = new Object[capacity()];
			for (int i = 0; i < size(); ++i)
			{
				objects[i] = rhs.objects[i];
			}
		}

		return *this;
	}

	/* 
	 * change vector size
	 */
	void resize(int newSize)
	{
		if (newSize > theCapacity)
			reserve(2 * newSize + 1);

		theSize = newSize;
	}

	/* 
	 * change vector capacity
	 */
	void reserve(int newCapacity)
	{
		if (newCapacity < theSize) return;

		Object* oldObjects = objects;

		objects = new Object[newCapacity];
		for (int i = 0; i < theSize; ++i)
			objects[i] = oldObjects[i];

		theCapacity = newCapacity;

		delete[] oldObjects;
	}
	
	/* 
	 * subscript operator
	 */
	Object& operator[] (int index)
	{
		if (index >= 0 && index < size())
			return objects[index];
		else
			// cout<<"index out of bounds"<<endl;
			return objects[0];
	}
	const Object& operator[] (int index) const
	{
		if (index >= 0 && index < size())
			return objects[index];
		else
			// cout<<"index out of bounds"<<endl;
			return objects[0];
	}

	/* 
	 * return index element
	 */
	Object& at(int index)
	{
		return objects[index];
	}
	const Object& at(int index) const
	{
		return objects[index];
	}

	/* 
	 * clear vector
	 */
	void clear()
	{
		theSize = 0;
	}

	/* 
	 * if theSize == 0, return true; else return false
	 */
	bool empty() const
	{
		return size() == 0;
	}
	
	/* 
	 * return vector size
	 */
	int size() const
	{
		return theSize;
	}

	/* 
	 * return vector capacity
	 */
	int capacity() const
	{
		return theCapacity;
	}

	/* 
	 * push an Object at the end of vector
	 */
	void push_back(const Object& x)
	{
		if (theSize == theCapacity)
			reserve(2* theCapacity + 1);

		objects[theSize++] = x;
	}

	/* 
	 * push an Object at the begin of vector
	 */
	void push_front(const Object& x)
	{
		if (theSize == theCapacity)
			reserve(2* theCapacity + 1);

		int num = size();

		Object* oldObjects = objects;
		objects = new Object[capacity()];

		objects[0] = x;

		for (int i = 0; i < num; ++i)
		{
			objects[i + 1] = oldObjects[i];
		}

		delete[] oldObjects;
	}

	/* 
	 * delete the Object of first
	 */
	void pop_back()
	{
		--theSize;
	}

	/* 
	 * delete the Object of first
	 */
	void pop_front()
	{
		Object* oldObjects = objects;
		objects = new Object[capacity()];

		for (int i = 0; i < theSize - 1; ++i)
		{
			objects[i] = oldObjects[i + 1];
		}

		--theSize;

		delete[] oldObjects;
	}

	/* 
	 * return last element
	 */
	const Object& back() const
	{
		return objects[theSize - 1];
	}

	/* 
	 * return first element
	 */
	const Object& front() const
	{
		return objects[0];
	}

	/* 
	 * insert element
	 */
	iterator insert(iterator pos, const Object& x)
	{
		iterator itr = &objects[0];
		Object* oldObjs = objects;
		++theSize;
		
		int i = 0;

		if (theCapacity < theSize)
			theCapacity = 2 * theSize + 1;

		objects = new Object[theSize];

		while (pos != itr)
		{
			objects[i] = oldObjs[i];
			itr += sizeof(Object);
			pos += sizeof(Object);
			++i;
		}

		objects[i] = x;

		for (int j = i + 1; j < theSize; ++j)
			objects[j] = oldObjs[j - 1];

		delete[] oldObjs;

		return &objects[i];
	}

	/* 
	 * return first iterator
	 */
	iterator begin()
	{
		return &objects[0];
	}
	const_iterator begin() const
	{
		return &objects[0];
	}

	/* 
	 * return last iterator
	 */
	iterator end()
	{
		return &objects[size()];
	}
	const_iterator end() const
	{
		return &objects[size()];
	}

	/* 
	 * erase item at itr
	 */
	iterator erase(iterator pos)
	{
		if (pos == end())
			return end();

		int index = 0;

		iterator it = begin();
		for (int i = 0; it != end(); ++i, ++it)
		{
			if (pos == it)
			{
				index = i;
				break;
			}
		}

		for (int i = index; i < theSize - 1; ++i)
		{
			objects[i] = objects[i + 1];
		}

		--theSize;

		return pos;
	}

	/* 
	 * operator++
	 */
	/*iterator operator++( )
	{

	}*/
	
	enum{ SPACE_CAPACITY = 16 };

private:
	int theSize;       // the size of vector
	int theCapacity;   // the capacity of vector
	Object* objects;   // Object pointer
};

#endif