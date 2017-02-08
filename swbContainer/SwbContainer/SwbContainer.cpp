// SwbContainer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include <sys/timeb.h>
#include "swb_vector.h"
#include "swb_list.h"
#include "swb_stack.h"
#include "swb_queue.h"
#include <list>
#include <vector>
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	/************************************************************************/
	/*                           swb_vector                                 */
	/*swb_vector<int> vec(10, 0);
	swb_vector<int>::iterator it = vec.begin();
	it = vec.insert(it, 10);
	cout<<*it<<endl;
	vec.push_back(10);*/
	//cout<<vec.back()<<endl;
	//cout<<vec.size()<<endl;
	//cout<<vec.size()<<endl;
	//cout<<vec.capacity()<<endl;

	//cout<<vec.at(10)<<endl;
	//vec.push_front(10);
	//cout<<"push_front:"<<vec.at(0)<<endl;
	//vec.pop_front();
	//swb_vector<int>::iterator it;
	//for (it = vec.begin(); it != vec.end(); ++it)
	//{
	//	cout<<*it<<endl;
	//}

	//it = vec.begin();
	//while(it != vec.end())
	//{
	//	if (vec.erase(it) != vec.end()) 
	//		++it;
	//}

	//cout<<"after erase:"<<endl;

	//for (it = vec.begin(); it != vec.end(); ++it)
	//{
	//	cout<<*it<<endl;
	//}

	//timeb begtime, endtime;
	//ftime(&begtime);

	//swb_vector<int> test;
	//for (int i = 0; i < 40000; ++i)
	//{
	//	test.push_back(i);
	//}

	//ftime(&endtime);
	//int sec = endtime.time * 1000 + endtime.millitm 
	//	- begtime.time * 1000 - begtime.millitm;
	//cout<<"vector(40000)初始化时间："<<sec<<endl;

	//ftime(&begtime);

	//it = test.begin();
	///*while(it != test.end())
	//{
	//	if (test.erase(it) != test.end()) 
	//		++it;
	//}*/

	//ftime(&endtime);
	//sec = endtime.time * 1000 + endtime.millitm 
	//	- begtime.time * 1000 - begtime.millitm;
	//cout<<"vector(40000)删除时间："<<sec<<endl;
	/************************************************************************/

	/************************************************************************/
	/*                             swb_list                                 */
	//swb_list<int> lst;
	//lst.push_back(10);
	//cout<<lst.back()<<endl;
	//cout<<lst.size()<<endl;

	//lst.push_front(9);
	//cout<<"front:"<<lst.front()<<endl;
	//cout<<"back:"<<lst.back()<<endl;
	//
	//lst.pop_front();
	//lst.clear();

	//swb_list<int>::iterator itr;
	//for (itr = lst.begin(); itr != lst.end(); ++itr)
	//{
	//	cout<<*itr<<endl;
	//}

	//ftime(&begtime);

	//vector<int> stdVec;
	//for (int i = 0; i < 40000000; ++i)
	//{
	//	stdVec.push_back(i);
	//}

	///*list<int> stdList;
	//for (int i = 0; i < 20000000; ++i)
	//{
	//	stdList.push_back(i);
	//}*/

	//for (int i = 0; i < 20000000; ++i)
	//{
	//	lst.push_back(0);
	//}

	//ftime(&endtime);
	//sec = endtime.time * 1000 + endtime.millitm 
	//	- begtime.time * 1000 - begtime.millitm;
	//cout<<"list(40000)初始化时间："<<sec<<endl;

	//ftime(&begtime);

	//itr = lst.begin();
	//while(itr != lst.end())
	//{
	//	itr = lst.erase(itr);
	//	if (itr != lst.end()) 
	//		++itr;
	//}

	//ftime(&endtime);
	//sec = endtime.time * 1000 + endtime.millitm 
	//	- begtime.time * 1000 - begtime.millitm;
	//cout<<"lst(40000)删除时间："<<sec<<endl;

	//lst.clear();

	//cout<<"after erase:"<<endl;

	//for (itr = lst.begin(); itr != lst.end(); ++itr)
	//{
	//	cout<<*itr<<endl;
	//}
	/************************************************************************/

	/************************************************************************/
	/*                             swb_stack                                */
	/*swb_stack<int> stk;
	stk.push(10);
	cout<<stk.top()<<endl;
	cout<<stk.size()<<endl;

	stk.pop();
	cout<<"front:"<<stk.top()<<endl;
	cout<<"size:"<<stk.size()<<endl;
	
	timeb begtime, endtime;
	ftime(&begtime);

	for (int i = 0; i < 400000; ++i)
	{
		stk.push(i);
	}

	ftime(&endtime);
	int sec = endtime.time * 1000 + endtime.millitm 
		- begtime.time * 1000 - begtime.millitm;
	cout<<"stack(40000)初始化时间："<<sec<<endl;

	ftime(&begtime);
	
	stk.clear();
	
	ftime(&endtime);
	sec = endtime.time * 1000 + endtime.millitm 
		- begtime.time * 1000 - begtime.millitm;
	cout<<"stack(40000)删除时间："<<sec<<endl;


	cout<<"after erase:"<<endl;

	while (stk.size() != 0)
	{
		cout<<stk.top()<<endl;
		stk.pop();
	}*/

	/************************************************************************/

	/************************************************************************/
	/*                             swb_queue                                */
	swb_queue<int> que;
	que.enqueue(10);
	cout<<que.dequeue()<<endl;
	cout<<que.size()<<endl;

	timeb begtime, endtime;
	ftime(&begtime);

	for (int i = 0; i < 400000; ++i)
	{
		que.enqueue(i);
	}

	ftime(&endtime);
	int sec = endtime.time * 1000 + endtime.millitm 
		- begtime.time * 1000 - begtime.millitm;
	cout<<"queue(40000)初始化时间："<<sec<<endl;

	ftime(&begtime);

	/*while (que.size() != 0)
		cout<<que.dequeue()<<" | ";*/

	que.clear();

	ftime(&endtime);
	sec = endtime.time * 1000 + endtime.millitm 
		- begtime.time * 1000 - begtime.millitm;
	cout<<"queue(40000)删除时间："<<sec<<endl;


	cout<<"after erase:"<<endl;

	while (que.size() != 0)
	{
		cout<<que.dequeue()<<endl;
	}

	/************************************************************************/

	system("pause");
	return 0;
}

