/*************************************************************************************
*文件名称：协同探测模型                                                              *
*作    者：                                                                          *
*版    本：                                                                          *
*日    期：                                                                          *
*功能描述：本程序为协同探测模型，用于多颗卫星对目标进行定位和探测。                  *
*输    入：该程序为多输入，输入为三颗卫星的空间直角坐标以及目标分别与三颗卫星的距离。*
*输    出：该程序为多输出，输出为目标的空间直角坐标。                                *
*函数列表：1.getZ()——用于计算目标在空间直角坐标系中的z坐标；                       *
*          2.getY()——用于计算目标在空间直角坐标系中的y坐标；                       *
*          3.getX()——用于计算目标在空间直角坐标系中的x坐标。                       *
*历    史：                                                                          *
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
*描述：getZ()函数用于计算目标在空间之间坐标系中的z坐标，输入为三颗卫星的空间直角坐标 *
*      (x1,y1,z1)、(x2,y2,z2)、(x3,y3,z3)以及目标分别与三颗卫星的距离L1、L2、L3，输出*
*      为目标的空间直角坐标系中的z坐标。                                             *
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
*描述：getY()函数用于计算目标在空间之间坐标系中的z坐标，输入为三颗卫星的空间直角坐标 *
*      (x1,y1,z1)、(x2,y2,z2)、(x3,y3,z3)以及目标分别与三颗卫星的距离L1、L2、L3，输出*
*      为目标的空间直角坐标系中的y坐标。                                             *
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
*描述：getX()函数用于计算目标在空间之间坐标系中的z坐标，输入为三颗卫星的空间直角坐标 *
*      (x1,y1,z1)、(x2,y2,z2)、(x3,y3,z3)以及目标分别与三颗卫星的距离L1、L2、L3，输出*
*      为目标的空间直角坐标系中的x坐标。                                             *
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
