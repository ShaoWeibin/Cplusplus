// SwbSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "swb_sort.h"
#include "swb_sort.cpp"
#include "swb_template_sort.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {10,66,44,52323,343,454,55,22,75,43};

	vector<int> v;
	/*for (int i = 20; i >= 0; --i)
		v.push_back(i);*/
	for (int i = 0; i < 10; ++i)
		v.push_back(a[i]);

	swb_template_sort::largeObjectSortAsc(v);
	swb_template_sort::quicksortAsc(v);
	swb_template_sort::quicksortDesc(v);
	swb_template_sort::mergeSortAsc(v);
	swb_template_sort::heapsortAsc(v);

	vector<int> v_;
	for (int i = 0; i <= 20; ++i)
		v_.push_back(i);

	swb_template_sort::mergeSortDesc(v_);
	swb_template_sort::heapsortDesc(v_);

	/*swb_sort::insert_sort_asc(a, 10);
	for (int i = 0; i < 10; ++i)
		cout<<a[i]<<" ";*/

	int* m = new int[100000];
	for (int i = 0; i < 100000; ++i)
	{
		m[i] = 100000 - i;
	}

	int* n = new int[100000];
	for (int i = 0; i < 100000; ++i)
	{
		n[i] = i + 1;
	}

	int c[] = {2,343,343,1,123,43,43,433,687,654,3};
	int *temp = new int[10000000];
	swb_sort::selection_sort_asc(m, 100000);
	//swb_sort::heap_sort_asc(m, 10000000);
	//swb_sort::radix_sort_desc(n, 1000000);
	//swb_sort::bubble_sort_asc(m, 100000);
	//swb_sort::quick_sort_asc(c, 0, 10);
	for (int i = 0; i < 1000; ++i)
		cout<<m[i]<<" ";

	cout<<endl;

	swb_sort::selection_sort_desc(n, 100000);
	for (int i = 0; i < 1000; ++i)
		cout<<n[i]<<" ";


	/*swb_sort::bubble_sort_desc(n, 100000);
	for (int i = 0; i < 100; ++i)
		cout<<n[i]<<" ";*/
	

	system("pause");
	return 0;
}

