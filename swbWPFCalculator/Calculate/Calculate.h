/** 
 * FileName: Calculate.h
 * Author: ShaoWeibin
 * Data: 2013-09-06
 * Description: Calculate Function
 * History:
 * CopyRight(C) 2013, ShaoWeibin
 */

#ifndef CALCULATE_H
#define CALCULATE_H

#define DLLEXPORT extern "C" __declspec(dllexport) 

namespace Calculate
{
	/** 
	 * return a + b
	 */
	DLLEXPORT double add(double a, double b);

	/** 
	 * return a - b
	 */
	DLLEXPORT double subtract(double a, double b);

	/** 
	 * return a * b
	 */
	DLLEXPORT double multiply(double a, double b);

	/** 
	 * return a / b
	 */
	DLLEXPORT double divide(double a, double b);
};

#endif