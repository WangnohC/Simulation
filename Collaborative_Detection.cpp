/*************************************************************************************
*�ļ����ƣ�Эͬ̽��ģ��                                                              *
*��    �ߣ�                                                                          *
*��    ����                                                                          *
*��    �ڣ�                                                                          *
*����������������ΪЭͬ̽��ģ�ͣ����ڶ�����Ƕ�Ŀ����ж�λ��̽�⡣                  *
*��    �룺�ó���Ϊ�����룬����Ϊ�������ǵĿռ�ֱ�������Լ�Ŀ��ֱ����������ǵľ��롣*
*��    �����ó���Ϊ����������ΪĿ��Ŀռ�ֱ�����ꡣ                                *
*�����б�1.getZ()�������ڼ���Ŀ���ڿռ�ֱ������ϵ�е�z���ꣻ                       *
*          2.getY()�������ڼ���Ŀ���ڿռ�ֱ������ϵ�е�y���ꣻ                       *
*          3.getX()�������ڼ���Ŀ���ڿռ�ֱ������ϵ�е�x���ꡣ                       *
*��    ʷ��                                                                          *
*                   Copyright (c) wangchong. All Rights Reserved                     *
*************************************************************************************/

#include "Collaborative_Detection.h"
#include <cmath>


Collaborative_Detection::Collaborative_Detection()
{
}


Collaborative_Detection::~Collaborative_Detection()
{
}

/*************************************************************************************
*������getZ()�������ڼ���Ŀ���ڿռ�֮������ϵ�е�z���꣬����Ϊ�������ǵĿռ�ֱ������ *
*      (x1,y1,z1)��(x2,y2,z2)��(x3,y3,z3)�Լ�Ŀ��ֱ����������ǵľ���L1��L2��L3�����*
*      ΪĿ��Ŀռ�ֱ������ϵ�е�z���ꡣ                                             *
*************************************************************************************/
double Collaborative_Detection::getZ(double x1, double y1, double z1, double L1, double x2, double y2, double z2, double L2, double x3, double y3, double z3, double L3)
{
	double C1 = pow(L2, 2) - pow(L1, 2) + pow(x1, 2) - pow(x2, 2) + pow(y1, 2) - pow(y2, 2) + pow(z1, 2) - pow(z2, 2);
	double C2 = pow(L3, 2) - pow(L1, 2) + pow(x1, 2) - pow(x3, 2) + pow(y1, 2) - pow(y3, 2) + pow(z1, 2) - pow(z3, 2);
	double C = (x1 - x2) * (y1 - y3) - (x1 - x3) * (y1 - y2);
	double C3 = (C1 * (y1 - y3) - C2 * (y1 - y2)) / 2 / C;
	double C4 = ((z1 - z3) * (y1 - y2) - (z1 - z2) * (y1 - y3)) / C;
	double C5 = (C2 * (x1 - x2) - C1 * (x1 - x3)) / 2 / C;
	double C6 = ((z1 - z2) * (x1 - x3) - (z1 - z3) * (x1 - x2)) / C;
	double C7 = C3 - x1;
	double C8 = C5 - y1;
	double a = pow(C4, 2) + pow(C6, 2) + 1;
	double b = 2 * C4 * C7 + 2 * C6 * C8 - 2 * z1;
	double c = pow(C7, 2) + pow(C8, 2) + pow(z1, 2) - pow(L1, 2);
	double d = pow(b, 2) - 4 * a * c;
	if (d >= 0)
	{
		double z = (sqrt(d) - b) / 2 / a;
		//vector <double> z(Z, Z + 2);
		
		return z;
	}
}

/*************************************************************************************
*������getY()�������ڼ���Ŀ���ڿռ�֮������ϵ�е�z���꣬����Ϊ�������ǵĿռ�ֱ������ *
*      (x1,y1,z1)��(x2,y2,z2)��(x3,y3,z3)�Լ�Ŀ��ֱ����������ǵľ���L1��L2��L3�����*
*      ΪĿ��Ŀռ�ֱ������ϵ�е�y���ꡣ                                             *
*************************************************************************************/
double Collaborative_Detection::getY(double x1, double y1, double z1, double L1, double x2, double y2, double z2, double L2, double x3, double y3, double z3, double L3)
{
	double z = getZ(x1, y1, z1, L1, x2, y2, z2, L2, x3, y3, z3, L3);
	double C1 = pow(L2, 2) - pow(L1, 2) + pow(x1, 2) - pow(x2, 2) + pow(y1, 2) - pow(y2, 2) + pow(z1, 2) - pow(z2, 2);
	double C2 = pow(L3, 2) - pow(L1, 2) + pow(x1, 2) - pow(x3, 2) + pow(y1, 2) - pow(y3, 2) + pow(z1, 2) - pow(z3, 2);
	double C = (x1 - x2) * (y1 - y3) - (x1 - x3) * (y1 - y2);
	double C5 = (C2 * (x1 - x2) - C1 * (x1 - x3)) / 2 / C;
	double C6 = ((z1 - z2) * (x1 - x3) - (z1 - z3) * (x1 - x2)) / C;
	double y = C5 + C6 * z;
	
	return y;
}

/*************************************************************************************
*������getX()�������ڼ���Ŀ���ڿռ�֮������ϵ�е�z���꣬����Ϊ�������ǵĿռ�ֱ������ *
*      (x1,y1,z1)��(x2,y2,z2)��(x3,y3,z3)�Լ�Ŀ��ֱ����������ǵľ���L1��L2��L3�����*
*      ΪĿ��Ŀռ�ֱ������ϵ�е�x���ꡣ                                             *
*************************************************************************************/
double Collaborative_Detection::getX(double x1, double y1, double z1, double L1, double x2, double y2, double z2, double L2, double x3, double y3, double z3, double L3)
{
	double z = getZ(x1, y1, z1, L1, x2, y2, z2, L2, x3, y3, z3, L3);
	double C1 = pow(L2, 2) - pow(L1, 2) + pow(x1, 2) - pow(x2, 2) + pow(y1, 2) - pow(y2, 2) + pow(z1, 2) - pow(z2, 2);
	double C2 = pow(L3, 2) - pow(L1, 2) + pow(x1, 2) - pow(x3, 2) + pow(y1, 2) - pow(y3, 2) + pow(z1, 2) - pow(z3, 2);
	double C = (x1 - x2) * (y1 - y3) - (x1 - x3) * (y1 - y2);
	double C3 = (C1 * (y1 - y3) - C2 * (y1 - y2)) / 2 / C;
	double C4 = ((z1 - z3) * (y1 - y2) - (z1 - z2) * (y1 - y3)) / C;
	double x = C3 + C4 * z;
	
	return x;
}
