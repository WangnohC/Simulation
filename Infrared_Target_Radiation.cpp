/*************************************************************************************
*文件名称：红外目标辐射模型                                                          *
*作    者：                                                                          *
*版    本：                                                                          *
*日    期：                                                                          *
*功能描述：本程序为红外目标辐射模型，用于计算红外目标在空间中的辐射强度。            *
*输    入：该程序为单输入，输入为相对距离。                                          *
*输    出：该程序为单输出，输出为探测器所接收到的红外辐射强度。                      *
*函数列表：1.getInfrared_Target_Radiation()——用于计算探测器所接收到的红外辐射强度。*
*历    史：                                                                          *
*                   Copyright (c) wangchong. All Rights Reserved                     *
*************************************************************************************/

#include "Infrared_Target_Radiation.h"
#include <cmath>

Infrared_Target_Radiation::Infrared_Target_Radiation()
{
}


Infrared_Target_Radiation::~Infrared_Target_Radiation()
{
}

/*************************************************************************************
*描述：getInfrared_Target_Radiation()函数用于计算红外目标辐射强度随传输距离的变化关  *
*      系，输入为辐射源与探测器之间的相对距离RD，输出为探测器所接收到的辐射强度Is。  *
*************************************************************************************/
double Infrared_Target_Radiation::getInfrared_Target_Radiation(double I0, double RD)   //计算探测器所接收到的辐射强度
{
	double a = 3.0543e-8;                           //衰减系数
	double ts = 0.6;                                //相机红外辐射透射率
	double Is = ts * I0 * exp(- a * RD);             //导弹尾焰红外辐射入射到相机入瞳处的辐射强度
	
	return Is;
}
