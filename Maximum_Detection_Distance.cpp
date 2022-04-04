/*************************************************************************************
*文件名称：卫星最大探测距离                                                          *
*作    者：                                                                          *
*版    本：                                                                          *
*日    期：                                                                          *
*功能描述：本程序为卫星最大探测距离模型，用于计算卫星的最大探测距离。                *
*输    入：该程序为多输入，输入为最小信噪比阈值和辐射源的辐射强度。                  *
*输    出：该程序为单输出，输出为卫星的最大探测距离。                                *
*函数列表：1.getMaximum_Detection_Distance()——用于计算卫星最大探测距离。           *
*历    史：                                                                          *
*                   Copyright (c) wangchong. All Rights Reserved                     *
*************************************************************************************/

#include "Maximum_Detection_Distance.h"
#include <cmath>

Maximum_Detection_Distance::Maximum_Detection_Distance()
{
}


Maximum_Detection_Distance::~Maximum_Detection_Distance()
{
}

/*************************************************************************************
*描述：getMaximum_Detection_Distance()函数用于计算卫星最大探测距离，输入为最小信噪比 *
*      阈值snr和辐射源辐射强度I0，输出为卫星的最大探测距离MDD。                      *
*************************************************************************************/
double Maximum_Detection_Distance::getMaximum_Detection_Distance(double snr, double I0)  //计算卫星最大探测距离
{
	double pi = atan(1) * 4;
	double spfactor = 2.0 / 3;
	double ta = 0.57;
	double t0 = 0.5;
	double D0 = 0.9;
	double D = 9e9;
	double Ad = 2.5e-3;
	double td = 3 * 44.6;
	double f = 3 / (4 * td);
	double a = sqrt(pi * spfactor * ta * t0 * pow(D0, 2) * D / (4 * sqrt(Ad * f)));
	double MDD = a * sqrt(I0 / snr);

	return MDD;
}
