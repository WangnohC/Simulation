/*************************************************************************************
* 文件名称：卫星导弹位置间参数模型                                                   *
* 作    者：                                                                         *
* 版    本：                                                                         *
* 日    期：                                                                         *
* 功能描述：本程序为卫星导弹位置间参数模型，用于计算卫星与导弹间的相对距离。         *
* 输    入：该程序为多输入，输入为卫星的空间直角坐标和导弹的空间直角坐标。           *
* 输    出：该程序为单输出，输出为卫星与导弹间的相对距离。                           *
* 函数列表：1.getRelative_Distance()——用于计算卫星与导弹间的相对距离。             *
* 历    史：                                                                         *
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
* 描述：getRelative_Distance()函数用于计算卫星与导弹间的相对距离，输入为卫星的空间直 *
*       角坐标（xs,ys,zs)和导弹的空间直角坐标（xm,ym,zm)，输出为二者的相对距离RD。   *
*************************************************************************************/
double Distance::getRelative_Distance(double xs, double ys, double zs, double xm, double ym, double zm)   //计算卫星与导弹之间的相对距离
{
	double Rx = abs(xs - xm);
	double Ry = abs(ys - ym);
	double Rz = abs(zs - zm);
	double RD = sqrt(pow(Rx, 2) + pow(Ry, 2) + pow(Rz, 2));
	
	return RD;
}
