/* 
** FileName:swb_sort.h 
** Author: ShaoWeibin
** Data: 2014-04-01
** Description: sort
** History:
** CopyRight(C) 2014, ShaoWeibin
*/

#include "swb_sort.h"
using namespace std;

void swb_sort::radix_sort_asc(int data[], int n)
{
	int max = max_bit(data, n);  // ��ȡ���λ��
	int * count = new int[10];  // ������
	int * tmp = new int[n];

	int radix = 1;

	for(int i = 0; i < max; ++i)  // ����d������
	{
		//ÿ�η���ǰ��ռ�����
		for(int j = 0; j < 10; ++j)
			count[j] = 0; 

		// ͳ��ÿ��Ͱ�еļ�¼��
		for(int j = 0; j < n; ++j)
		{
			int k = (data[j] / radix) % 10;  
			++count[k];
		}

		//��tmp�е�λ�����η����ÿ��Ͱ
		for(int j = 1; j < 10; ++j)
			count[j] = count[j-1] + count[j]; 

		//������Ͱ�м�¼�����ռ���tmp��
		for(int j = n-1; j >= 0; --j) 
		{
			int k = (data[j] / radix) % 10;
			tmp[count[k]-1] = data[j];
			--count[k];
		}

		//����ʱ��������ݸ��Ƶ�data��
		for(int j = 0; j < n; ++j) 
			data[j] = tmp[j];

		radix = radix*10;
	}

	delete [] tmp;
	delete [] count;
}

void swb_sort::radix_sort_desc(int data[], int n)
{
	int max = max_bit(data, n);  // ��ȡ���λ��
	int * count = new int[10];  // ������
	int * tmp = new int[n];

	int radix = 1;

	for(int i = 0; i < max; ++i)  // ����d������
	{
		//ÿ�η���ǰ��ռ�����
		for(int j = 0; j < 10; ++j)
			count[j] = 0; 

		// ͳ��ÿ��Ͱ�еļ�¼��
		for(int j = 0; j < n; ++j)
		{
			int k = (data[j] / radix) % 10;  
			++count[k];
		}

		//��tmp�е�λ�����η����ÿ��Ͱ
		for(int j = 8; j >= 0; --j)
			count[j] = count[j+1] + count[j]; 

		//������Ͱ�м�¼�����ռ���tmp��
		for(int j = n-1; j >= 0; --j) 
		{
			int k = (data[j] / radix) % 10;
			tmp[count[k]-1] = data[j];
			--count[k];
		}

		//����ʱ��������ݸ��Ƶ�data��
		for(int j = 0; j < n; ++j) 
			data[j] = tmp[j];

		radix = radix*10;
	}

	delete [] tmp;
	delete [] count;
}

int swb_sort::max_bit(const int data[], int n)
{
	int max = 1;  //����λ��
	int p = 10;
	for(int i = 0;i < n; ++i)
	{
		while(data[i] >= p)
		{
			p *= 10;
			++max;
		}
	}

	return max;
}

void swb_sort::bubble_sort_asc(int data[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = n - 1; j > i; --j)
		{
			if(data[j] < data[j - 1] )
			{
				int temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;
			}
		}
	}
}

void swb_sort::bubble_sort_desc(int data[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = n - 1; j > i; --j)
		{
			if(data[j] > data[j - 1] )
			{
				int temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;
			}
		}
	}
}

void swb_sort::quick_sort_asc(int data[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = data[l];
		while (i < j)
		{

			// ���������ҵ�һ��С��x����  
			while (i < j && data[j] >= x) --j;

			if (i < j) data[i++] = data[j];

			// ���������ҵ�һ������x����  
			while (i < j && data[i] <= x) ++i;

			if (i < j) data[j--] = data[i];
		}

		data[i] = x;  

		quick_sort_asc(data, l, i - 1);  // �ݹ����   
		quick_sort_asc(data, i + 1, r);  // �ݹ����    
	}
}

void swb_sort::quick_sort_desc(int data[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = data[l];
		while (i < j)
		{

			// ���������ҵ�һ������x����  
			while (i < j && data[j] <= x) --j;

			if (i < j) data[i++] = data[j];

			// ���������ҵ�һ��С��x����  
			while (i < j && data[i] >= x) ++i;

			if (i < j) data[j--] = data[i];
		}

		data[i] = x;  

		quick_sort_desc(data, l, i - 1);  // �ݹ����   
		quick_sort_desc(data, i + 1, r);  // �ݹ����    
	}
}

void swb_sort::heap_sort_asc(int data[], int n)
{
	for(int i = n - 1; i >= 0; --i)
		max_heapify(data, n, i);

	while(n > 0)  // �����
	{
		swap(data[--n], data[0]);  // �����������������ĩ����
		max_heapify(data, n, 0);  //������
	}

	return;
}

void swb_sort::heap_sort_desc(int data[], int n)
{
	for(int i = n - 1; i >= 0; --i)
		min_heapify(data, n, i);

	while(n > 0)  // �����
	{
		swap(data[--n], data[0]);  // ��������С����������ĩ����
		min_heapify(data, n, 0);  //������
	}

	return;
}

void swb_sort::max_heapify(int data[], int n, int i)
{ 
	int l = i * 2 + 1;  // ������
	int r = l + 1;  // ������

	while(r < n)  // �������ڷ�Χ��
	{
		// ������������������������
		if(data[i] >= data[l] && data[i] >= data[r])
			return;
	
		if(data[l] < data[r])  // ��������С
		{
			swap(data[i], data[r]);  // ��������ᵽ����
			i = r;  // ѭ��ʱ��������
		}
		else  // ����������С
		{
			swap(data[i], data[l]);
			i = l;
		}

		l = i * 2 + 1;  // ������
		r = l + 1;    // ������
	}

	// ֻ�������������������Լ�
	if(l < n && data[l] > data[i])
	{
		swap(data[l], data[i]);
	}

	return;
}

void swb_sort::min_heapify(int data[], int n, int i)
{ 
	int l = i * 2 + 1;  // ������
	int r = l + 1;  // ������

	while(r < n)  // �������ڷ�Χ��
	{
		// ���������������С���������
		if(data[i] <= data[l] && data[i] <= data[r])
			return;
	
		if(data[l] < data[r])  // ��������С
		{
			swap(data[i], data[l]);  // ��������ᵽ����
			i = l;  // ѭ��ʱ��������
		}
		else  // ����������С
		{
			swap(data[i], data[r]);
			i = r;
		}

		l = i * 2 + 1;  // ������
		r = l + 1;    // ������
	}

	// ֻ��������������С���Լ�
	if(l < n && data[l] < data[i])
	{
		swap(data[l], data[i]);
	}

	return;
}

void swb_sort::merge_sort_asc(int data[], int data_[], int f, int l)
{
	if(f == l) return;
	else
	{
		int m = (f + l) / 2;
		merge_sort_asc(data, data_, f, m);       // �������
		merge_sort_asc(data, data_ , m + 1, l);  // �ұ�����
		merge_asc(data, data_, f, m, l);         // �ϲ�������������
	}
}

void swb_sort::merge_sort_desc(int data[], int data_[], int f, int l)
{
	if(f == l) return;
	else
	{
		int m = (f + l) / 2;
		merge_sort_desc(data, data_, f, m);       // �������
		merge_sort_desc(data, data_ , m + 1, l);  // �ұ�����
		merge_desc(data, data_, f, m, l);         // �ϲ�������������
	}
}

void swb_sort::merge_asc(int data[], int data_[], int f, int m, int l)
{
	int i = f;
	int j= m + 1;
	int k = f;

	while(i <= m && j <= l)
	{
		if(data[i] <= data[j])
			data_[k++] = data[i++];
		else
			data_[k++] = data[j++];
	}

	while(i <= m)
	 data_[k++] = data[i++];

	while(j <= l)
		data_[k++]=data[j++];
	
	for(int i = f; i < k; ++i)
		data[i]=data_[i];
}

void swb_sort::merge_desc(int data[], int data_[], int f, int m, int l)
{
	int i = f;
	int j= m + 1;
	int k = f;

	while(i <= m && j <= l)
	{
		if(data[i] >= data[j])
			data_[k++] = data[i++];
		else
			data_[k++] = data[j++];
	}

	while(i <= m)
		data_[k++] = data[i++];

	while(j <= l)
		data_[k++]=data[j++];

	for(int i = f; i < k; ++i)
		data[i]=data_[i];
}

void swb_sort::insert_sort_asc(int data[], int n)
{
	int i, j, temp;

	for (i = 1; i < n; ++i)
	{
		if (data[i] < data[i - 1])
		{
			temp = data[i];

			for (j = i - 1; j >= 0 && data[j] > temp; --j)
				data[j + 1] = data[j];

			data[j + 1] = temp;
		}
	}

	// �����࣬Ч�ʽϵ�
	/*for (int i = 1; i < n; ++i)
	for (int j = i - 1; j >= 0 && data[j] > data[j + 1]; --j)
	swap(data[j], data[j + 1]);*/
}

void swb_sort::insert_sort_desc(int data[], int n)
{
	int i, j, temp;

	for (i = 1; i < n; ++i)
	{
		if (data[i] > data[i - 1])
		{
			temp = data[i];

			for (j = i - 1; j >= 0 && data[j] < temp; --j)
				data[j + 1] = data[j];

			data[j + 1] = temp;
		}
	}

	// �����࣬Ч�ʽϵ�
	/*for (int i = 1; i < n; ++i)
	for (int j = i - 1; j >= 0 && data[j] < data[j + 1]; --j)
	swap(data[j], data[j + 1]);*/
}

void swb_sort::shell_sort_asc(int data[], int n)
{
	int d, i, j, temp;

	for(d = n / 2; d >= 1; d = d/2)
	{
		for(i = d; i < n; ++i)
		{
			temp = data[i];
			for(j = i; (j >= d) && (temp < data[j - d]); j -= d)
				data[j] = data[j - d];

			data[j] = temp;
		}
	}
}

void swb_sort::shell_sort_desc(int data[], int n)
{
	int d, i, j, temp;

	for(d = n / 2; d >= 1; d = d/2)
	{
		for(i = d; i < n; ++i)
		{
			temp = data[i];
			for(j = i; (j >= d) && (temp > data[j - d]); j -= d)
				data[j] = data[j - d];

			data[j] = temp;
		}
	}
}

void swb_sort::selection_sort_asc(int data[], int n)
{
	int index;

	for (int i = 0; i < n - 1; ++i)
	{
		index = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (data[j] < data[i])
				index = j;
		}

		if (index != i)
			swap(data[i], data[index]);
	}
}

void swb_sort::selection_sort_desc(int data[], int n)
{
	int index;

	for (int i = 0; i < n - 1; ++i)
	{
		index = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (data[j] > data[i])
				index = j;
		}

		if (index != i)
			swap(data[i], data[index]);
	}
}