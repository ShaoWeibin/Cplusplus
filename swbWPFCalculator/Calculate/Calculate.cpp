/** 
 * FileName: Calculate.cpp
 * Author: ShaoWeibin
 * Data: 2013-09-06
 * Description: Calculate Function
 * History:
 * CopyRight(C) 2013, ShaoWeibin
 */

// Calculate.cpp : 定义 DLL 应用程序的导出函数。

#include "stdafx.h"
#include "Calculate.h"

double Calculate::add(double a, double b)
{
	return a + b;
}

double Calculate::subtract(double a, double b)
{
	return a - b;
}

double Calculate::multiply(double a, double b)
{
	return a * b;
}

double Calculate::divide(double a, double b)
{
	if (b == 0)
	{
		return 0;
	}

	return a / b;
}
