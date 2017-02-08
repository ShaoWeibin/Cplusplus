/** 
 * FileName: swbSeparateChainingHashTable.h
 * Author: ShaoWeibin
 * Data: 2015-04-07
 * Description: Separate Chaining Hash Table(分离链接散列表)
 * History:
 * CopyRight(C) 2015, ShaoWeibin
 */

#ifndef SWB_SEPARATE_CHAINING_HASH_TABLE
#define SWB_SEPARATE_CHAINING_HASH_TABLE

#include<vector> 
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;  

template <typename HashedObj>
class swbSeparateChainingHashTable
{
public:
	explicit swbSeparateChainingHashTable( int size = 101 ) : currentSize(0) { theLists.resize(size); }
	~swbSeparateChainingHashTable( ) { }

	void print( );

	int size ( ) const { return theLists.size(); }
	const list<HashedObj> & get( int i ) const { return theLists[i]; }

	bool contains( const HashedObj & x ) const
	{ 
		const list<HashedObj> & whichList = theLists[ myhash( x ) ];
		return find ( whichList.begin(), whichList.end(), x ) != whichList.end();
	}

	void makeEmpty( )
	{
		for ( int i = 0; i < theLists.size(); ++i )
			theLists[i].clear( );
	}

	bool insert( const HashedObj & x )
	{
		list<HashedObj> & whichList = theLists[ myhash( x ) ];
		if ( find( whichList.begin(), whichList.end(), x ) != whichList.end() )
			return false;
		whichList.push_back(x);

		// Rehash
		if ( ++currentSize > theLists.size() )
			rehash();

		return true;
	}

	bool remove( const HashedObj & x )
	{
		list<HashedObj> & whichList = theLists[ myhash( x ) ];
		list<HashedObj>::iterator itr = find( whichList.begin(), whichList.end(), x );

		if ( itr == whichList.end() )
			return false;

		whichList.erase(itr);
		--currentSize;
		return true;
	}

private:
	vector<list<HashedObj> > theLists;  // the array of Lists
	int currentSize;

	/*
	** 分离链接散列表再散列
	** Rehashing for separate chaining hash table.
	*/
	void rehash( )
	{
		vector<list<HashedObj> > oldLists = theLists;

		// Create new double-sized, empty table
		theLists.resize( nextPrime( 2 * theLists.size() ) );
		for ( int i = 0; i < theLists.size(); ++i )
			theLists[i].clear();

		// Copy table over
		currentSize = 0; 
		for ( int i = 0; i < oldLists.size(); ++i )
		{
			list<HashedObj>::iterator itr = oldLists[i].begin();
			while ( itr != oldLists[i].end() )
				insert( *itr++ );
		}
	}

	int myhash( const HashedObj & x ) const
	{
		int hasVal = hash( x );
		hasVal %= theLists.size();
		if ( hasVal < 0 )
			hasVal += theLists.size();

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
int swbSeparateChainingHashTable<string>::hash( const string & key ) const
{
	int hashVal = 0;

	for ( int i = 0; i < key.length(); ++i )
		hashVal = 37 * hashVal + key[i];

	hashVal %= theLists.size();
	if ( hashVal < 0 ) hashVal += theLists.size();

	return hashVal;
}

template<>
int swbSeparateChainingHashTable<int>::hash( int key ) const
{ return key % theLists.size(); }

#endif  // SWB_SEPARATE_CHAINING_HASH_TABLE