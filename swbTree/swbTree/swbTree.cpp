// swbTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "swbBinarySearchTree.h"
#include "swbAvlTree.h"
#include "swbSet.h"
#include "swbSplayTree.h"
#include "iostream"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	swbSplayTree<int> tree;
	for (int i = 0; i < 10000000; ++i)
		tree.insert(i);
	
	/*cout<<tree.findMin()<<endl;
	cout<<tree.findMax()<<endl;*/
	tree.remove(50);
	tree.makeEmpty();

	//swbSet<int> mySet;
	//mySet.insert(1);
	//mySet.insert(2);
	//mySet.insert(3);

	//swbSet<int>::iterator itr;
	//itr = mySet.begin();
	//++itr;
	//itr = mySet.end();

	//int sum = 0;
	//for (itr = mySet.begin(); itr != mySet.end(); ++itr)
	//{
	//	cout<<*itr<<endl;
	//	itr = mySet.erase(itr);
	//	++sum;
	//}

	//mySet.clear();

	//for (int i = 0; i < 10000; ++i)
	//{
	//	try 
	//	{
	//		mySet.insert(i);
	//	}
	//	catch (...)
	//	{
	//		int err = i;
	//	}
	//	
	//}
	//
	//itr = mySet.begin();
	//while (itr != mySet.end())
	//{
	//	itr = mySet.erase(++itr);
	//}

	//itr = mySet.begin();
	//while (itr != mySet.end())
	//{
	//	cout<<*itr<<" ";
	//	++itr;
	//}

	//cout<<*mySet.erase(1)<<endl;
	//cout<<*mySet.erase(2)<<endl;


	//swbAvlTree<int> tree;
	//// swbBinarySearchTree<int> tree;
	//tree.insert(1);
	//tree.insert(2);
	//tree.insert(3);
	//tree.insert(4);
	//tree.insert(5);
	//tree.insert(6);
	//tree.insert(7);

	//tree.remove(2);
	//tree.remove(3);
	//tree.remove(1);
	//tree.remove(5);
	//tree.remove(6);
	//tree.remove(4);
	//tree.remove(7);


	///*cout<<tree.findMin()<<endl;
	//cout<<tree.findMax()<<endl;*/

	//tree.prefixPrint();
	//cout<<endl;
	//tree.infixPrint();
	//cout<<endl;
	//tree.postfixPrint();
	//cout<<endl;

	//tree.makeEmpty();
	//
	//for (int i = 0; i < 400; ++i)
	//{
	//	tree.insert(i);
	//}

	//for (int i = 300; i < 400; ++i)
	//{
	//	tree.remove(i);
	//}

	//cout<<"MIN: "<<tree.findMin()<<endl;
	//cout<<"MAX: "<<tree.findMax()<<endl;
	//cout<<"HEIGTH: "<<tree.height()<<endl;

	//tree.prefixPrint();
	//cout<<endl;
	//tree.infixPrint();
	//cout<<endl;
	//tree.postfixPrint();

	system("pause");
	return 0;
}

