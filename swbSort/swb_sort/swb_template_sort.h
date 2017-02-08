/* 
** FileName:swb_template_sort.h 
** Author: ShaoWeibin
** Data: 2015-04-10
** Description: template sort
** History:
** CopyRight(C) 2015, ShaoWeibin
*/

#ifndef SWB_TEMPLATE_SORT_H
#define SWB_TEMPLATE_SORT_H

#include <string>
#include <vector>
using namespace std;

#ifndef DLL_EXP
#define DLL_EXP _declspec(dllexport)
#endif

class DLL_EXP swb_template_sort
{
public:
	/*
	** Simple insertion sort.
	** Ascending order.
	*/
	template<typename Comparable>
	static void insertionSortAsc( vector<Comparable> & a )
	{
		int j;
		for ( int p = 1; p < a.size(); ++p )
		{
			Comparable tmp = a[p];
			for ( j = p; j > 0 && tmp < a[j - 1]; --j )
				a[j] = a[j - 1];
			a[j] = tmp;
		}
	}

	/*
	** Simple insertion sort.
	** Descending order.
	*/
	template<typename Comparable>
	static void insertionSortDesc( vector<Comparable> & a )
	{
		int j;
		for ( int p = 1; p < a.size(); ++p )
		{
			Comparable tmp = a[p];
			for ( j = p; j > 0 && tmp > a[j - 1]; --j )
				a[j] = a[j - 1];
			a[j] = tmp;
		}
	}

	/*
	** Shellsort, using Shell's (poor) increments.
	** Ascending order.
	*/
	template<typename Comparable>
	static void shellsortAsc( vector<Comparable> & a )
	{
		for ( int gap = a.size() / 2; gap > 0; gap /= 2 )
		{
			for ( int i = gap; i < a.size(); ++i )
			{
				Comparable tmp = a[i];
				int j = i;

				for ( ; j >= gap && tmp < a[j - gap]; j -= gap )
					a[j] = a[j - gap];
				a[j] = tmp;
			}
		}
	}

	/*
	** Shellsort, using Shell's (poor) increments.
	** Descending order.
	*/
	template<typename Comparable>
	static void shellsortDesc( vector<Comparable> & a )
	{
		for ( int gap = a.size() / 2; gap > 0; gap /= 2 )
		{
			for ( int i = gap; i < a.size(); ++i )
			{
				Comparable tmp = a[i];
				int j = i;

				for ( ; j >= gap && tmp > a[j - gap]; j -= gap )
					a[j] = a[j - gap];
				a[j] = tmp;
			}
		}
	}

	/*
	** Standard heapsort.
	** Ascending order.
	*/
	template<typename Comparable>
	static void heapsortAsc( vector<Comparable> & a )
	{
		for ( int i = a.size() / 2; i >= 0; --i )  // buildHeap
			percDownMax( a, i, a.size() ); 
		for ( int j = a.size() - 1; j > 0; --j )
		{
			swap( a[0], a[j] );  // deleteMax
			percDownMax(a, 0, j);
		}
	}

	/*
	** Standard heapsort.
	** Descending order.
	*/
	template<typename Comparable>
	static void heapsortDesc( vector<Comparable> & a )
	{
		for ( int i = a.size() / 2; i >= 0; --i )  // buildHeap
			percDownMin( a, i, a.size() ); 
		for ( int j = a.size() - 1; j > 0; --j )
		{
			swap( a[0], a[j] );  // deleteMin
			percDownMin(a, 0, j);
		}
	}

	private:
	/*
	** Internal method for heapsort.
	** i is the index of an item in the heap.
	** Return the index of the left child.
	*/
	inline static int leftChild( int i )
	{
		return 2 * i + 1;
	}

	/*
	** Internal method for heapsort that is used in deleteMax and buildHeap.
	** i is the position from which to percolate down.
	** n is the logical size of the binary heap.
	*/
	template<typename Comparable>
	static void percDownMax ( vector<Comparable> & a, int i, int n )
	{
		int child;
		Comparable tmp;

		for ( tmp = a[i]; leftChild( i ) < n; i = child )
		{
			child = leftChild( i );
			if ( child != n - 1 && a[child] < a[child + 1] )
				++child;
			if ( tmp < a[child] )
				a[i] = a[child];
			else
				break;
		}

		a[i] = tmp;
	}

	/*
	** Internal method for heapsort that is used in deleteMin and buildHeap.
	** i is the position from which to percolate down.
	** n is the logical size of the binary heap.
	*/
	template<typename Comparable>
	static void percDownMin ( vector<Comparable> & a, int i, int n )
	{
		int child;
		Comparable tmp;

		for ( tmp = a[i]; leftChild( i ) < n; i = child )
		{
			child = leftChild( i );
			if ( child != n - 1 && a[child] > a[child + 1] )
				++child;
			if ( tmp > a[child] )
				a[i] = a[child];
			else
				break;
		}

		a[i] = tmp;
	}

public:
	/*
	** Mergesort algorithm (dirver).
	** Ascending order.
	*/
	template<typename Comparable>
	static void mergeSortAsc( vector<Comparable> & a )
	{
		vector<Comparable> tmpArray( a.size() );

		mergeSortAsc( a, tmpArray, 0, a.size() - 1 );
	}

	/*
	** Mergesort algorithm (dirver).
	** Descending order.
	*/
	template<typename Comparable>
	static void mergeSortDesc( vector<Comparable> & a )
	{
		vector<Comparable> tmpArray( a.size() );

		mergeSortDesc(a, tmpArray, 0, a.size() - 1);
	}

private:
	/*
	** Internal method that makes recursive calls.
	** a is an array of Comparable items.
	** tmpArray is an array to place the merged result.
	** left is the left-mosst index of the subarray.
	** right is the right-most index of the subarray.
	** Ascending order.
	*/
	template<typename Comparable>
	static void mergeSortAsc(vector<Comparable> & a, vector<Comparable> & tmpArray, int left, int right)
	{
		if (left < right)
		{
			int center = (left + right) / 2;
			mergeSortAsc(a, tmpArray, left, center);
			mergeSortAsc(a, tmpArray, center + 1, right);
			mergeAsc(a, tmpArray, left, center + 1, right);
		}
	}

	/*
	** Internal method that makes recursive calls.
	** a is an array of Comparable items.
	** tmpArray is an array to place the merged result.
	** left is the left-most index of the subarray.
	** right is the right-most index of the subarray.
	** Descending order.
	*/
	template<typename Comparable>
	static void mergeSortDesc(vector<Comparable> & a, vector<Comparable> & tmpArray, int left, int right)
	{
		if (left < right)
		{
			int center = (left + right) / 2;
			mergeSortDesc(a, tmpArray, left, center);
			mergeSortDesc(a, tmpArray, center + 1, right);
			mergeDesc(a, tmpArray, left, center + 1, right);
		}
	}

	/*
	** Internal method that merges two sorted halves of a subarray.
	** a is an array of Comparable items.
	** tmpArray is an array to place the merged result.
	** leftPos is the left-most index of the subarray.
	** rightPos is the index of the start of the second half.
	** rightEnd is the right-most index of the subarray.
	** Ascending order.
	*/
	template<typename Comparable>
	static void mergeAsc(vector<Comparable> & a, vector<Comparable> & tmpArray, int leftPos, int rightPos, int rightEnd)
	{
		int leftEnd = rightPos - 1;
		int tmpPos = leftPos;
		int numElements = rightEnd - leftPos + 1;

		// Main loop
		while (leftPos <= leftEnd && rightPos <= rightEnd)
		{
			if (a[leftPos] <= a[rightPos])
				tmpArray[tmpPos++] = a[leftPos++];
			else
				tmpArray[tmpPos++] = a[rightPos++];
		}
		
		while (leftPos <= leftEnd)  // Copy rest of first half
			tmpArray[tmpPos++] = a[leftPos++];

		while (rightPos <= rightEnd)  // Copy rest of right half
			tmpArray[tmpPos++] = a[rightPos++];

		// Copy tmpArray back
		for (int i = 0; i < numElements; ++i, --rightEnd)
			a[rightEnd] = tmpArray[rightEnd];
	}

	/*
	** Internal method that merges two sorted halves of a subarray.
	** a is an array of Comparable items.
	** tmpArray is an array to place the merged result.
	** leftPos is the left-most index of the subarray.
	** rightPos is the index of the start of the second half.
	** rightEnd is the right-most index of the subarray.
	** Descending order.
	*/
	template<typename Comparable>
	static void mergeDesc(vector<Comparable> & a, vector<Comparable> & tmpArray, int leftPos, int rightPos, int rightEnd)
	{
		int leftEnd = rightPos - 1;
		int tmpPos = leftPos;
		int numElements = rightEnd - leftPos + 1;

		// Main loop
		while (leftPos <= leftEnd && rightPos <= rightEnd)
		{
			if (a[leftPos] >= a[rightPos])
				tmpArray[tmpPos++] = a[leftPos++];
			else
				tmpArray[tmpPos++] = a[rightPos++];
		}

		while (leftPos <= leftEnd)  // Copy rest of first half
			tmpArray[tmpPos++] = a[leftPos++];

		while (rightPos <= rightEnd)  // Copy rest of right half
			tmpArray[tmpPos++] = a[rightPos++];

		// Copy tmpArray back
		for (int i = 0; i < numElements; ++i, --rightEnd)
			a[rightEnd] = tmpArray[rightEnd];
	}

public:
	/*
	** Quicksort algorithm (dirver).
	** Ascending order.
	*/
	template<typename Comparable>
	static void quicksortAsc(vector<Comparable> & a)
	{
		quicksortAsc(a, 0, a.size() - 1);
	}

	/*
	** Quicksort algorithm (dirver).
	** Descending order.
	*/
	template<typename Comparable>
	static void quicksortDesc(vector<Comparable> & a)
	{
		quicksortDesc(a, 0, a.size() - 1);
	}

private:
	/*
	** Internal quicksort method that makes recursive calls.
	** Uses median-of-three partitioning and a cutoff of 10.
	** a is an array of Comparable items.
	** left is the left-most index of the subarray.
	** right is the right-most index of the subarray.
	** Ascending order.
	*/
	template<typename Comparable>
	static void quicksortAsc(vector<Comparable> & a, int left, int right)
	{
		if (left + 10 < right)
		{
			Comparable pivot = median3(a, left , right);

			// Begin partitioning
			int i = left, j = right - 1;
			for ( ; ; )
			{
				while (a[++i] < pivot) { }
				while (pivot < a[--j]) { }
				if (i < j)
					swap(a[i], a[j]);
				else
					break;
			}

			swap(a[i], a[right - 1]);  // Restore	pivot

			quicksortAsc(a, left, i - 1);     // Sort small elements
			quicksortAsc(a, i + 1, right);    // Sort large elements
		}
		else  // Do an insertion sort on the subarray
			insertionSortAsc(a, left, right); 
	}

	/*
	** Internal quicksort method that makes recursive calls.
	** Uses median-of-three partitioning and a cutoff of 10.
	** a is an array of Comparable items.
	** left is the left-most index of the subarray.
	** right is the right-most index of the subarray.
	** Descending order.
	*/
	template<typename Comparable>
	static void quicksortDesc(vector<Comparable> & a, int left, int right)
	{
		if (left + 10 < right)
		{
			Comparable pivot = median3(a, left , right);

			// Begin partitioning
			int i = left, j = right - 1;
			for ( ; ; )
			{
				while (a[++i] > pivot) { }
				while (pivot > a[--j]) { }
				if (i < j)
					swap(a[i], a[j]);
				else
					break;
			}

			swap(a[i], a[right - 1]);  // Restore	pivot

			quicksortDesc(a, left, i - 1);     // Sort small elements
			quicksortDesc(a, i + 1, right);    // Sort large elements
		}
		else  // Do an insertion sort on the subarray
			insertionSortDesc(a, left, right); 
	}

	/*
	** Simple insertion sort.
	** Ascending order.
	*/
	template<typename Comparable>
	static void insertionSortAsc( vector<Comparable> & a , int left, int right )
	{
		int j;
		for ( int p = left + 1; p <= right; ++p )
		{
			Comparable tmp = a[p];
			for ( j = p; j > 0 && tmp < a[j - 1]; --j )
				a[j] = a[j - 1];
			a[j] = tmp;
		}
	}

	/*
	** Simple insertion sort.
	** Descending order.
	*/
	template<typename Comparable>
	static void insertionSortDesc( vector<Comparable> & a , int left, int right )
	{
		int j;
		for ( int p = left + 1; p <= right; ++p )
		{
			Comparable tmp = a[p];
			for ( j = p; j > 0 && tmp > a[j - 1]; --j )
				a[j] = a[j - 1];
			a[j] = tmp;
		}
	}
	
	/*
	** Return median of left, center, and right.
	** Order these and hide the pivot.
	*/
	template<typename Comparable>
	static const Comparable & median3(vector<Comparable> & a, int left, int right)
	{
		int center = (left + right) / 2;
		if (a[center] < a[left])
			swap(a[left], a[center]);
		if (a[right] < a[left])
			swap(a[left], a[right]);
		if (a[right] < a[center])
			swap(a[center], a[right]);

		// Place pivot at position right - 1
		swap(a[center], a[right - 1]);
		return a[right - 1];
	}

	/*
	** Internal selection method that makes recursive calls.
	** Uses median-of-three partitioning and a cutoff of 10.
	** Places the kth smallest item in a[k-1].
	** a is an array of Comparable items.
	** left is the left-most index of the subarray.
	** right is the right-most index of the subarray.
	** k is the desired rank (1 is mininum) in the entire array.
	*/
	template<typename Comparable>
	void quickSelect(vector<Comparable> & a, int left, int right, int k)
	{
		if (left + 10 <= right)
		{
			Comparable pivot = median3(a, left, right);

			// Begin partitioning
			int i = left, j = right - 1;
			for (;;)
			{
				while (a[++i] < pivot) {}
				while (a[--j] > pivot) {}

				if (i < j)
					swap(a[i], a[j]);
				else
					break;
			}

			swap(a[i], a[right - 1])£»  // Restore pivot

				// Recurse; only this part changes
			if (k <= i)
				quickSelect(a, left, i - 1, k);
			else
				quickSelect(a, i + 1, right, k);
		}
		else  // Do an insertion sort on the subarray
			insertionSortAsc(a, left, right);
	}

public:
	template<typename Comparable>
	class Pointer
	{
	public:
		Pointer(Comparable* rhs = NULL) : pointee(rhs) { }
		
		bool operator < (const Comparable & rhs) const
		{
			std::cout<<"hello"<<endl;
			return *pointee < *rhs.pointee; 
		}

		operator Comparable * () const { return pointee; }

	private:
		Comparable* pointee;
	};

	/*
	** Large object sort.
	** Ascending order.
	*/
	template<typename Comparable>
	static void largeObjectSortAsc(vector<Comparable> & a)
	{
		vector<Pointer<Comparable> > p(a.size());
		int i, j, nextj;

		for (i = 0; i < a.size(); ++i)
			p[i] = &a[i];
		
		quicksort(p);

		p[0] = &a[0];
		p[1] = &a[7];
		p[2] = &a[9];
		p[3] = &a[2];
		p[4] = &a[6];
		p[5] = &a[1];
		p[6] = &a[8];
		p[7] = &a[4];
		p[8] = &a[5];
		p[9] = &a[3];

		// Shuffle items in place
		for (i = 0; i < a.size(); ++i)
		{
			if (p[i] != &a[i])
			{
				Comparable tmp = a[i];
				for (j = i; p[j] != &a[i]; j = nextj)
				{
					nextj = p[j] - &a[0];
					a[j] = *p[j];
					p[j] = &a[j];
				}
				a[j] = tmp;
				p[j] = &a[j];
			}
		}
	}

private:
	/*
	** Quicksort algorithm (dirver).
	** Ascending order.
	*/
	template<typename Comparable>
	static void quicksort(vector<Pointer<Comparable> > & a)
	{
		quicksort(a, 0, a.size() - 1);
	}

	/*
	** Internal quicksort method that makes recursive calls.
	** Uses median-of-three partitioning and a cutoff of 10.
	** a is an array of Comparable items.
	** left is the left-most index of the subarray.
	** right is the right-most index of the subarray.
	** Ascending order.
	*/
	template<typename Comparable>
	static void quicksort(vector<Pointer<Comparable> > & a, int left, int right)
	{
		if (left + 10 <= right)
		{
			Pointer<Comparable> pivot = median3(a, left , right);

			// Begin partitioning
			int i = left, j = right - 1;
			for ( ; ; )
			{
				while (a[++i] < pivot) { }
				while (pivot < a[--j]) { }
				if (i < j)
					swap(a[i], a[j]);
				else
					break;
			}

			swap(a[i], a[right - 1]);  // Restore	pivot

			quicksort(a, left, i - 1);     // Sort small elements
			quicksort(a, i + 1, right);    // Sort large elements
		}
		else  // Do an insertion sort on the subarray
			insertionSort(a, left, right);
	}

	/*
	** Simple insertion sort.
	** Ascending order.
	*/
	template<typename Comparable>
	static void insertionSort( vector<Pointer<Comparable> > & a , int left, int right )
	{
		int j;
		for ( int p = left + 1; p <= right; ++p )
		{
			Pointer<Comparable> tmp = a[p];
			for ( j = p; j > 0 && tmp < a[j - 1]; --j )
				a[j] = a[j - 1];
			a[j] = tmp;
		}
	}
};

#endif  // SWB_TEMPLATE_SORT_H
