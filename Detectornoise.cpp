/*************************************************************************************
*文件名称：探测器噪声模型                                                            *
*作    者：                                                                          *
*版    本：                                                                          *
*日    期：                                                                          *
*功能描述：本程序为探测器噪声模型，用于计算探测器所产生的噪声。                      *
*输    入：该程序为单输入，输入为相对距离。                                          *
*输    出：该程序为单输出，输出为探测器噪声。                                        *
*函数列表：1.getAirnoise()——用于计算探测器所产生的噪声。                           *
*历    史：                                                                          *
*                   Copyright (c) wangchong. All Rights Reserved                     *
*************************************************************************************/

#include "Detectornoise.h"
#include <cmath>

Detectornoise::Detectornoise()
{
}


Detectornoise::~Detectornoise()
{
}

/*************************************************************************************
*描述：getDetectornoise()函数用于计算探测器所产生的噪声，输入为辐射源与探测器之间的相*
*      对距离RD，输出为探测器所接收到的噪声DN。                                      *
*************************************************************************************/
double Detectornoise::getDetectornoise(double RD)      //计算探测器所产生的噪声
{
	double pi = atan(1) * 4;
	double Sd = 2.5e-3;
	double td = 3 * 44.6;
	double f = 3 / (4 * td);
	double t0 = 0.5;
	double D = 9e9;
	double D0 = 0.9;
	double St = pi * pow(D0, 2) / 4;
	double a = sqrt(Sd * f) / (t0 * St * D);
	double b = a * pow(RD, 2);
	double DN = b / pow(RD, 2);
	
	return DN;
}
