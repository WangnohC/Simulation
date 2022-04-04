/*************************************************************************************
*文件名称：导弹尾焰辐射模型                                                          *
*作    者：                                                                          *
*版    本：                                                                          *
*日    期：                                                                          *
*功能描述：本程序为导弹尾焰辐射模型，用于计算导弹尾焰所产生的辐射强度。              *
*输    入：该程序为单输入，输入为导弹的高度。                                        *
*输    出：该程序为单输出，输出为导弹尾焰辐射强度。                                  *
*函数列表：1.getMissile_Tail_Flame_Radiation()——用于计算导弹尾焰辐射强度。         *
*历    史：                                                                          *
*                   Copyright (c) wangchong. All Rights Reserved                     *
*************************************************************************************/

#include "Missile_Tail_Flame_Radiation.h"
#include <cmath>

Missile_Tail_Flame_Radiation::Missile_Tail_Flame_Radiation()
{
}


Missile_Tail_Flame_Radiation::~Missile_Tail_Flame_Radiation()
{
}

/*************************************************************************************
*描述：getMissile_Tail_Flame_Radiation()函数用于计算导弹尾焰辐射强度，输入为导弹的高 *
*      度h，输出为导弹尾焰辐射强度I0。                                               *
*************************************************************************************/
double Missile_Tail_Flame_Radiation::getMissile_Tail_Flame_Radiation(double h)    //计算导弹尾焰辐射强度
{
	double a = 4e-9;
	double b = 6.41e-7;
	double c = 2.434e-5;
	double d = 0.7227;
	double I0 = (a * pow(h, 3) - b * pow(h, 2) + c * h + d) * 40000;

	return I0;
}
