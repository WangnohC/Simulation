/*************************************************************************************
*�ļ����ƣ��������̽�����                                                          *
*��    �ߣ�                                                                          *
*��    ����                                                                          *
*��    �ڣ�                                                                          *
*����������������Ϊ�������̽�����ģ�ͣ����ڼ������ǵ����̽����롣                *
*��    �룺�ó���Ϊ�����룬����Ϊ��С�������ֵ�ͷ���Դ�ķ���ǿ�ȡ�                  *
*��    �����ó���Ϊ����������Ϊ���ǵ����̽����롣                                *
*�����б�1.getMaximum_Detection_Distance()�������ڼ����������̽����롣           *
*��    ʷ��                                                                          *
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
*������getMaximum_Detection_Distance()�������ڼ����������̽����룬����Ϊ��С����� *
*      ��ֵsnr�ͷ���Դ����ǿ��I0�����Ϊ���ǵ����̽�����MDD��                      *
*************************************************************************************/
double Maximum_Detection_Distance::getMaximum_Detection_Distance(double snr, double I0)  //�����������̽�����
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
