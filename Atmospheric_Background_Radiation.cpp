/*************************************************************************************
*�ļ����ƣ�������������ģ��                                                          *
*��    �ߣ�                                                                          *
*��    ����                                                                          *
*��    �ڣ�                                                                          *
*����������������Ϊ������������ģ�ͣ����ڼ�������������������������                *
*��    �룺�ó���Ϊ�����룬����Ϊ��Ծ��롣                                          *
*��    �����ó���Ϊ����������Ϊ������������������                                  *
*�����б�1.getAtmospheric_Background_Radiation()�������ڼ��������������������     *
*��    ʷ��                                                                          *
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
*������getAtmospheric_Background_Radiation()�������ڼ������������������������������ *
*      ��Ϊ����Դ��̽����֮�����Ծ���RD�����Ϊ̽���������յ�������AN��            *
*************************************************************************************/
double Atmospheric_Background_Radiation::getAtmospheric_Background_Radiation(double h, double RD)       //���������������������������
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
