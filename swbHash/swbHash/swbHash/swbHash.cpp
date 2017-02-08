// swbHash.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "swbProbingHashTable.h"
#include "swbSeparateChainingHashTable.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	swbProbingHashTable<int> intTable;  
	intTable.insert(10);  
	intTable.insert(20);  
	intTable.insert(30);  
	intTable.insert(40);  
	intTable.insert(50);  
	intTable.remove(30);  

	for (int i = 0; i < intTable.size(); ++i)
		cout<<i<<":"<<intTable.get(i)<<endl;

	intTable.makeEmpty();  

	for (int i = 0; i < 10000000; ++i)
		intTable.insert(i);  

	bool contain = intTable.contains(5999999);

	swbSeparateChainingHashTable<int> intTable_;  
	intTable_.insert(10);  
	intTable_.insert(20);  
	intTable_.insert(30);  
	intTable_.insert(40);  
	intTable_.insert(50);  
	intTable_.remove(30);  

	for (int i = 0; i < intTable_.size(); ++i)
	{
		if (intTable_.get(i).size())
			cout<<i<<":"<<intTable_.get(i).front()<<endl;
	}

	intTable_.makeEmpty();  

	/*swbProbingHashTable<string> strTable;  
	strTable.insert(string("10"));  
	strTable.insert(string("20"));  
	strTable.insert(string("30"));  
	strTable.insert(string("40")); */
 
	system("pause");
	return 0;
}

