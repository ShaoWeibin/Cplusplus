/* 
** FileName:swb_sort.h 
** Author: ShaoWeibin
** Data: 2014-04-01
** Description: sort
** History:
** CopyRight(C) 2014, ShaoWeibin
*/

#ifndef SWB_SORT_H
#define SWB_SORT_H
#include <string>

#ifndef DLL_EXP
#define DLL_EXP _declspec(dllexport)
#endif

class DLL_EXP swb_sort
{
public:
	/*
	** ��������(Ͱ�ӷ�)(����)
	** data[]: ����������
	** n: ����Ԫ������
	** int
	*/
	static void radix_sort_asc(int data[], int n);

	/*
	** ��������(Ͱ�ӷ�)(����)
	** data[]: ����������
	** n: ����Ԫ������
	** int
	*/
	static void radix_sort_desc(int data[], int n);

	/*
	** ð������(����)
	** data[]: ����������
	** n: ����Ԫ������
	** int
	*/
	static void bubble_sort_asc(int data[], int n);

	/*
	** ð������(����)
	** data[]: ����������
	** n: ����Ԫ������
	** int
	*/
	static void bubble_sort_desc(int data[], int n);
	
	/*
	** ��������(����)
	** data[]: ����������
	** l: �����һ��Ԫ��λ��
	** r: �������һ��Ԫ��λ��
	** int
	*/
	static void quick_sort_asc(int data[], int l, int r);

	/*
	** ��������(����)
	** data[]: ����������
	** l: �����һ��Ԫ��λ��
	** r: �������һ��Ԫ��λ��
	** int
	*/
	static void quick_sort_desc(int data[], int l, int r);

	/*
	** ������(����)
	** data[]: ����������
	** n: ����Ԫ������
	** int
	*/
	static void heap_sort_asc(int data[], int n);

	/*
	** ������(����)
	** data[]: ����������
	** n: ����Ԫ������
	** int
	*/
	static void heap_sort_desc(int data[], int n);

	/*
	** �鲢����(����)
	** data[]: �����������
	** data_[]: ��ʱ����
	** f: �����һ��Ԫ��λ��
	** l: �������һ��Ԫ��λ��
	** int
	*/
	static void merge_sort_asc(int data[], int data_[], int f, int l);

	/*
	** �鲢����(����)
	** data[]: �����������
	** data_[]: ��ʱ����
	** f: �����һ��Ԫ��λ��
	** l: �������һ��Ԫ��λ��
	** int
	*/
	static void merge_sort_desc(int data[], int data_[], int f, int l);

	/*
	** ֱ�Ӳ�������(����)
	** data[]: ����������
	** n: ����Ԫ������
	** int
	*/
	static void insert_sort_asc(int data[], int n);

	/*
	** ֱ�Ӳ�������(����)
	** data[]: ����������
	** n: ����Ԫ������
	** int
	*/
	static void insert_sort_desc(int data[], int n);

	/*
	** ϣ������(��С��������)(����)
	** data[]: ����������
	** n: ����Ԫ������
	** int
	*/
	static void shell_sort_asc(int data[], int n);

	/*
	** ϣ������(��С��������)(����)
	** data[]: ����������
	** n: ����Ԫ������
	** int
	*/
	static void shell_sort_desc(int data[], int n);

	/*
	** ѡ������(����)
	** data[]: ����������
	** n: ����Ԫ������
	** int
	*/
	static void selection_sort_asc(int data[], int n);

	/*
	** ѡ������(����)
	** data[]: ����������
	** n: ����Ԫ������
	** int
	*/
	static void selection_sort_desc(int data[], int n);

private:
	/*
	** ��ȡ���������λ��
	** data[]: ����
	** n: ����Ԫ������
	*/
	static int max_bit(const int data[], int n);

	/*
	** ����󶥶�
	** data[]: �蹹��ѵ�����
	** n: ����Ԫ������
	** i: Ԫ���������е�������
	*/
	static void max_heapify(int data[], int n, int i);

	/*
	** ����С����
	** data[]: �蹹��ѵ�����
	** n: ����Ԫ������
	** i: Ԫ���������е�������
	*/
	static void min_heapify(int data[], int n, int i);

	/*
	** �ϲ�������(����)
	** data[]: ��ϲ�������
	** data_[]: ��ʱ����
	** f: �����һ��Ԫ��λ��
	** m: �����м��Ԫ��λ��
	** l: �������һ��Ԫ��λ��
	*/
	static void merge_asc(int data[], int data_[], int f, int m, int l);

	/*
	** �ϲ�������(����)
	** data[]: ��ϲ�������
	** data_[]: ��ʱ����
	** f: �����һ��Ԫ��λ��
	** m: �����м��Ԫ��λ��
	** l: �������һ��Ԫ��λ��
	*/
	static void merge_desc(int data[], int data_[], int f, int m, int l);
};

#endif  // SWB_SORT_H

