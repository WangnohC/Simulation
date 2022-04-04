/*************************************************************************************
* �ļ����ƣ����ǵ���λ�ü����ģ��                                                   *
* ��    �ߣ�                                                                         *
* ��    ����                                                                         *
* ��    �ڣ�                                                                         *
* ����������������Ϊ���ǵ���λ�ü����ģ�ͣ����ڼ��������뵼�������Ծ��롣         *
* ��    �룺�ó���Ϊ�����룬����Ϊ���ǵĿռ�ֱ������͵����Ŀռ�ֱ�����ꡣ           *
* ��    �����ó���Ϊ����������Ϊ�����뵼�������Ծ��롣                           *
* �����б���1.getRelative_Distance()�������ڼ��������뵼�������Ծ��롣             *
* ��    ʷ��                                                                         *
*                   Copyright (c) wangchong. All Rights Reserved                     *
*************************************************************************************/

#include "Distance.h"
#include <cmath>

Distance::Distance()
{
}


Distance::~Distance()
{
}

/*************************************************************************************
* ������getRelative_Distance()�������ڼ��������뵼�������Ծ��룬����Ϊ���ǵĿռ�ֱ *
*       �����꣨xs,ys,zs)�͵����Ŀռ�ֱ�����꣨xm,ym,zm)�����Ϊ���ߵ���Ծ���RD��   *
*************************************************************************************/
double Distance::getRelative_Distance(double xs, double ys, double zs, double xm, double ym, double zm)   //���������뵼��֮�����Ծ���
{
	double Rx = abs(xs - xm);
	double Ry = abs(ys - ym);
	double Rz = abs(zs - zm);
	double RD = sqrt(pow(Rx, 2) + pow(Ry, 2) + pow(Rz, 2));
	
	return RD;
}