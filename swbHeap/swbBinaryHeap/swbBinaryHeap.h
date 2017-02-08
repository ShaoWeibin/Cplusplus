/* 
** FileName: swbBinaryHeap.h
** Author: ShaoWeibin
** Data: 2014-06-06
** Description: Binary Heap
** History:
** CopyRight(C) 2014, ShaoWeibin
*/

#include <vector>
using namespace std;

template<typename Comparable>
class swbBinaryHeap
{
public:
	explicit swbBinaryHeap( int capacity = 100 ) : currentSize(0) { array.resize(capacity); }
	explicit swbBinaryHeap( const vector<Comparable>& items ) 
		: array(items.size() + 10),	currentSize(items.size())
	{ 
		for (int i = 0; i < items.size(); ++i)
			array[i + 1] = items[i];

		buildHeap();
	}

	bool isEmpty( ) const { return array.size() == 0; }
	const Comparable& findMin( ) const { if (array.size()) return array[1]; }
	
	/*
	** Insert item x, allowing duplicates.
	*/
	void insert( const Comparable& x )
	{
		if (currentSize == array.size() - 1)
			array.resize(array.size() * 2);

		// Percolate up
		int hole = ++currentSize;
		for (; hole > 1 && x < array[hole / 2]; hole /= 2)
			array[hole] = array[hole / 2];

		array[hole] = x;
	}

	/*
	** Remove the minimum item.
	** Throws UnderflowException if empty.
	*/
	void deleteMin( )
	{
		if (isEmpty()) ;
			//throw UnderflowException();

		array[1] == array[currentSize--];
		percolateDown(1);
	}

	/*
	** Remove the minimum item and place it in minItem.
	** Throws UnderflowException if empty.
	*/
	void deleteMin( const Comparable& minItem )
	{
		if (isEmpty()) ;
			//throw UnderflowException();

		minItem = array[1];
		array[1] == array[currentSize--];
		percolateDown(1);
	}

	void makeEmpty( ) { array.clear(); currentSize = 0; }

private:
	/*
	** Establish heap order property from an arbitrary 
	** arrangement of items. Runs in linear time.
	*/
	void buildHeap( )
	{
		for (int i = currentSize / 2; i > 0; --i)
			percolateDown(i);
	}

	/*
	** Internal method to percolate down in the heap.
	** hole is the index at which the percolate begins.
	*/
	void percolateDown( int hole )
	{
		int child;
		Comparable tmp = array[hole];

		for (; hole * 2 <= currentSize; hole = child)
		{
			child = hole * 2;

			if (child != currentSize && array[child + 1] < array[child])
				++child;

			if (array[child] < tmp)
				array[hole] = array[child];
			else
				break;
		}

		array[hole] = tmp;
	}

private:
	int currentSize;           // Number of elements in heap
	vector<Comparable> array;  // the heap array

};