/** 
 * FileName: swbProbingHashTable.h
 * Author: ShaoWeibin
 * Data: 2015-04-07
 * Description: Probing Hash Table(探测散列表)
 * History:
 * CopyRight(C) 2015, ShaoWeibin
 */

#ifndef SWB_PROBING_HASH_TABLE
#define SWB_PROBING_HASH_TABLE

#include<vector> 
#include <iostream>
using namespace std;  

template <typename HashedObj>
class swbProbingHashTable
{
public:
	explicit swbProbingHashTable( int size = 101 ) : array( nextPrime( size ) ) { makeEmpty(); }
	~swbProbingHashTable( ) { }

	void print( );

	int size ( ) const { return array.size(); }
	const HashedObj & get( int i ) const { return array[i].element; }

	bool contains( const HashedObj & x ) const
	{ return isActive( findPos( x ) ); }

	void makeEmpty( )
	{
		currentSize = 0;
		for ( int i = 0; i < array.size(); ++i )
			array[i].info = EMPTY;
	}

	bool insert( const HashedObj & x )
	{
		// insert x as active
		int currentPos = findPos( x );
		if ( isActive( currentPos ) )
			return false;

		array[currentPos] = HashEntry( x, ACTIVE );

		// Rehash
		if ( ++currentSize > array.size() / 2 )
			rehash();

		return true;
	}

	bool remove( const HashedObj & x )
	{
		int currentPos = findPos( x );

		if ( !isActive( currentPos ) )
			return false;

		array[currentPos].info = DELETED;
		return true;
	}

	enum EntryType { ACTIVE, EMPTY, DELETED };

private:
	struct HashEntry
	{
		HashedObj element;
		EntryType info;

		HashEntry( const HashedObj & e = HashedObj( ), EntryType i = EMPTY )
			: element( e ), info ( i ) { }
	};

	vector<HashEntry> array;
	int currentSize;

	bool isActive( int currentPos ) const
	{ return array[currentPos].info == ACTIVE; }

	int findPos( const HashedObj & x ) const
	{
		int offSet = 1;
		int currentPos = myhash( x );
		
		while ( array[currentPos].info != EMPTY && array[currentPos].element != x )
		{
			currentPos += offSet;  // Compute ith probe
			offSet += 2;
			if ( currentPos >= array.size() )
				currentPos -= array.size();
		}

		return currentPos;
	}

	/*
	** 平方探测
	** Rehashing for quadratic probing hash table.
	*/
	void rehash( )
	{
		vector<HashEntry> oldArray = array;

		// Create new double-sized, empty table
		array.resize( nextPrime( 2 * oldArray.size() ) );
		for ( int i = 0; i < array.size(); ++i )
			array[i].info = EMPTY;

		// Copy table over
		currentSize = 0; 
		for ( int i = 0; i < oldArray.size(); ++i )
			if ( oldArray[i].info == ACTIVE )
				insert( oldArray[i].element );
	}

	int myhash( const HashedObj & x ) const
	{
		int hasVal = hash( x );
		hasVal %= array.size();
		if ( hasVal < 0 )
			hasVal += array.size();

		return hasVal;
	}

	int hash( const string & key ) const;

	int hash( int key ) const;

	/*
  ** Helper function
  ** check prime
  */
  bool isPrime( size_t x)
  {
    for( std::size_t i = 3; true; i += 2 )
    {
      std::size_t q = x / i;
      if( q < i )
        return true;

      if( x == q * i )
        return false;
    }
    return true;
  }


  /*
  ** Find next prime for given x
  */
  size_t	nextPrime( size_t x )
  {
    if( x <= 2 )
      return 2;

    if(!(x & 1))
      ++x;

    for(; !isPrime(x); x += 2 );

    return x;
  }
};

template<>
int swbProbingHashTable<string>::hash( const string & key ) const
{
	int hashVal = 0;

	for ( int i = 0; i < key.length(); ++i )
		hashVal = 37 * hashVal + key[i];

	hashVal %= array.size();
	if ( hashVal < 0 ) hashVal += array.size();

	return hashVal;
}

template<>
int swbProbingHashTable<int>::hash( int key ) const
{ return key % array.size(); }

#endif  // SWB_PROBING_HASH_TABLE