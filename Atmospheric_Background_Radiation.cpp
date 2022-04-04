/*************************************************************************************
*文件名称：大气背景辐射模型                                                          *
*作    者：                                                                          *
*版    本：                                                                          *
*日    期：                                                                          *
*功能描述：本程序为大气背景辐射模型，用于计算大气背景辐射产生的噪声。                *
*输    入：该程序为单输入，输入为相对距离。                                          *
*输    出：该程序为单输出，输出为大气背景辐射噪声。                                  *
*函数列表：1.getAtmospheric_Background_Radiation()——用于计算大气背景辐射噪声。     *
*历    史：                                                                          *
*                   Copyright (c) wangchong. All Rights Reserved                     *
*************************************************************************************/

#include "Atmospheric_Background_Radiation.h"
#include <cmath>

Atmospheric_Background_Radiation::Atmospheric_Background_Radiation()
{
}


Atmospheric_Background_Radiation::~Atmospheric_Background_Radiation()
{
}

/*************************************************************************************
*描述：getAtmospheric_Background_Radiation()函数用于计算大气背景辐射所产生的噪声，输 *
*      入为辐射源与探测器之间的相对距离RD，输出为探测器所接收到的噪声AN。            *
*************************************************************************************/
double Atmospheric_Background_Radiation::getAtmospheric_Background_Radiation(double h, double RD)       //计算大气背景辐射所产生的噪声
{
	double c1 = 3.7418e-16;
	double c2 = 1.4388e-2;
	double pi = atan(1) * 4;
	double wavelength = 2.7e-6;
	double T = 20 - 0.6 * h / 100;
	double K = T + 273.15;
	double M = c1 * pow(wavelength, -5) * pow((exp(c2 / wavelength / K) - 1), -1);
	double F = M / pi;
	double a = 3.0543e-8;
	double ts = 0.6;
	double ABR = ts * F * exp(- a * RD);
	
	return ABR;
}
