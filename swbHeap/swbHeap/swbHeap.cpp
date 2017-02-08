// swbHeap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "swbBinaryHeap.h"

int _tmain(int argc, _TCHAR* argv[])
{

	int a[3][4] = { {2,5,6,8}, {22,55,66,88}, {1,2,3,5} };
	int b[4]={5,8,9,4};
	int c[3]={23,12,443};
	int *p[4],(*q)[4];
	q = a;
	*p = b;
	*(p + 1) = c;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
			cout<<*(*(q + i) +j)<<" ";

		cout<<endl;
	}

	cout<<*p[0]<<" "<<*(p[0] + 1)<<endl;
	/*swbBinaryHeap<int> heap;
	heap.insert(3);
	heap.insert(2);
	heap.insert(1);*/

	system("pause");
	return 0;
}

