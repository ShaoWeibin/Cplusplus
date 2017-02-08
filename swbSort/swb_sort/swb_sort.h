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
	** 基数排序(桶子法)(升序)
	** data[]: 需排序数组
	** n: 数组元素总数
	** int
	*/
	static void radix_sort_asc(int data[], int n);

	/*
	** 基数排序(桶子法)(降序)
	** data[]: 需排序数组
	** n: 数组元素总数
	** int
	*/
	static void radix_sort_desc(int data[], int n);

	/*
	** 冒泡排序(升序)
	** data[]: 需排序数组
	** n: 数组元素总数
	** int
	*/
	static void bubble_sort_asc(int data[], int n);

	/*
	** 冒泡排序(降序)
	** data[]: 需排序数组
	** n: 数组元素总数
	** int
	*/
	static void bubble_sort_desc(int data[], int n);
	
	/*
	** 快速排序(升序)
	** data[]: 需排序数组
	** l: 数组第一个元素位置
	** r: 数组最后一个元素位置
	** int
	*/
	static void quick_sort_asc(int data[], int l, int r);

	/*
	** 快速排序(降序)
	** data[]: 需排序数组
	** l: 数组第一个元素位置
	** r: 数组最后一个元素位置
	** int
	*/
	static void quick_sort_desc(int data[], int l, int r);

	/*
	** 堆排序(升序)
	** data[]: 需排序数组
	** n: 数组元素总数
	** int
	*/
	static void heap_sort_asc(int data[], int n);

	/*
	** 堆排序(降序)
	** data[]: 需排序数组
	** n: 数组元素总数
	** int
	*/
	static void heap_sort_desc(int data[], int n);

	/*
	** 归并排序(升序)
	** data[]: 需排序的数组
	** data_[]: 临时数组
	** f: 数组第一个元素位置
	** l: 数组最后一个元素位置
	** int
	*/
	static void merge_sort_asc(int data[], int data_[], int f, int l);

	/*
	** 归并排序(降序)
	** data[]: 需排序的数组
	** data_[]: 临时数组
	** f: 数组第一个元素位置
	** l: 数组最后一个元素位置
	** int
	*/
	static void merge_sort_desc(int data[], int data_[], int f, int l);

	/*
	** 直接插入排序(升序)
	** data[]: 需排序数组
	** n: 数组元素总数
	** int
	*/
	static void insert_sort_asc(int data[], int n);

	/*
	** 直接插入排序(降序)
	** data[]: 需排序数组
	** n: 数组元素总数
	** int
	*/
	static void insert_sort_desc(int data[], int n);

	/*
	** 希尔排序(缩小增量排序)(升序)
	** data[]: 需排序数组
	** n: 数组元素总数
	** int
	*/
	static void shell_sort_asc(int data[], int n);

	/*
	** 希尔排序(缩小增量排序)(降序)
	** data[]: 需排序数组
	** n: 数组元素总数
	** int
	*/
	static void shell_sort_desc(int data[], int n);

	/*
	** 选择排序(升序)
	** data[]: 需排序数组
	** n: 数组元素总数
	** int
	*/
	static void selection_sort_asc(int data[], int n);

	/*
	** 选择排序(降序)
	** data[]: 需排序数组
	** n: 数组元素总数
	** int
	*/
	static void selection_sort_desc(int data[], int n);

private:
	/*
	** 获取整数的最大位数
	** data[]: 数组
	** n: 数组元素总数
	*/
	static int max_bit(const int data[], int n);

	/*
	** 构造大顶堆
	** data[]: 需构造堆的数组
	** n: 数组元素总数
	** i: 元素在数组中的索引号
	*/
	static void max_heapify(int data[], int n, int i);

	/*
	** 构造小顶堆
	** data[]: 需构造堆的数组
	** n: 数组元素总数
	** i: 元素在数组中的索引号
	*/
	static void min_heapify(int data[], int n, int i);

	/*
	** 合并俩数组(升序)
	** data[]: 需合并的数组
	** data_[]: 临时数组
	** f: 数组第一个元素位置
	** m: 数组中间的元素位置
	** l: 数组最后一个元素位置
	*/
	static void merge_asc(int data[], int data_[], int f, int m, int l);

	/*
	** 合并俩数组(降序)
	** data[]: 需合并的数组
	** data_[]: 临时数组
	** f: 数组第一个元素位置
	** m: 数组中间的元素位置
	** l: 数组最后一个元素位置
	*/
	static void merge_desc(int data[], int data_[], int f, int m, int l);
};

#endif  // SWB_SORT_H

