/*************************************************************************************
*�ļ����ƣ�����β�����ģ��                                                          *
*��    �ߣ�                                                                          *
*��    ����                                                                          *
*��    �ڣ�                                                                          *
*����������������Ϊ����β�����ģ�ͣ����ڼ��㵼��β���������ķ���ǿ�ȡ�              *
*��    �룺�ó���Ϊ�����룬����Ϊ�����ĸ߶ȡ�                                        *
*��    �����ó���Ϊ����������Ϊ����β�����ǿ�ȡ�                                  *
*�����б�1.getMissile_Tail_Flame_Radiation()�������ڼ��㵼��β�����ǿ�ȡ�         *
*��    ʷ��                                                                          *
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
*������getMissile_Tail_Flame_Radiation()�������ڼ��㵼��β�����ǿ�ȣ�����Ϊ�����ĸ� *
*      ��h�����Ϊ����β�����ǿ��I0��                                               *
*************************************************************************************/
double Missile_Tail_Flame_Radiation::getMissile_Tail_Flame_Radiation(double h)    //���㵼��β�����ǿ��
{
	double a = 4e-9;
	double b = 6.41e-7;
	double c = 2.434e-5;
	double d = 0.7227;
	double I0 = (a * pow(h, 3) - b * pow(h, 2) + c * h + d) * 40000;

	return I0;
}
