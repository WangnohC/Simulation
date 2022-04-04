/*************************************************************************************
*文件名称：卫星轨道模型                                                              *
*作    者：                                                                          *
*版    本：                                                                          *
*日    期：                                                                          *
*功能描述：本程序为卫星六轨道根参数模型，用于描绘卫星的轨道以及计算卫星的位置。      *
*输    入：该程序为多输入，输入为椭圆轨道半长轴、椭圆轨道偏心率、卫星近地点时刻、近地*
*          点幅角、升交点赤经和椭圆轨道倾角。                                        *
*输    出：该程序为多输出，输出为卫星的位置和速度。                                  *
*函数列表：1.getE()——用于计算偏近地角；                                            *
*          2.getX()——用于计算卫星在空间直角坐标系中的x坐标；                       *
*          3.getY()——用于计算卫星在空间直角坐标系中的y坐标；                       *
*          4.getZ()——用于计算卫星在空间直角坐标系中的z坐标；                       *
*          5.getVX()——用于计算卫星在空间直角坐标系中x轴方向的速度vx；              *
*          6.getVY()——用于计算卫星在空间直角坐标系中y轴方向的速度vy；              *
*          7.getVZ()——用于计算卫星在空间直角坐标系中z轴方向的速度vz。              *
*历    史：                                                                          *
*                   Copyright (c) wangchong. All Rights Reserved                     *
*************************************************************************************/

#include "Track.h"
#include <cmath>

Track::Track()
{
}


Track::~Track()
{
}

/**************************************************************************************
*描述：getE()函数用于计算偏近地角E，采用Newton迭代法求解开普勒方程，输入为椭圆轨道半  *
*      长轴a、椭圆轨道偏心率e、近地点时刻tp和时间t，输出为任意时刻t所对应的偏近地角E。*
**************************************************************************************/
double Track::getE(double a, double e, double tp, double t)                          //计算偏近地角（弧度）
{
	double u = 3.986005e14;
	double n = sqrt(u / pow(a, 3));
	double M = n * (t - tp);
	double E0 = 0;
	while (1)
	{
		double E = E0 - (E0 - e * sin(E0) - M) / (1 - e * cos(E0));
		double Er = abs(E - E0);
		if (Er < 1e-5)
		{
			return E;
		}
		else
		{
			E0 = E;
		}
	}
}

/*************************************************************************************
*描述：getX()函数用于计算卫星在空间直角坐标系中的x坐标，输入为椭圆轨道半长轴a、椭圆轨*
*      道偏心率e、偏近地点角E、近地点幅角w、升交点赤经o和椭圆轨道倾角i，输出为卫星在 *
*      空间直角坐标 系中的x坐标。                                                    *
*************************************************************************************/
double Track::getX(double a, double e, double E, double w, double o, double i)      //计算卫星在空间直角坐标系中的x坐标
{
	double x = a * (cos(E) - e) * (cos(w) * cos(o) - sin(w) * sin(o) * cos(i)) + a * sqrt(1 - pow(e, 2)) * sin(E) * (-sin(w) * cos(o) - cos(w) * sin(o) * cos(i));
	
	return x;
}

/*************************************************************************************
*描述：getY()函数用于计算卫星在空间直角坐标系中的y坐标，输入为椭圆轨道半长轴a、椭圆轨*
*      道偏心率e、偏近地点角E、近地点幅角w、升交点赤经o和椭圆轨道倾角i，输出为卫星在 *
*      空间直角坐标系中的y坐标。                                                     *
*************************************************************************************/
double Track::getY(double a, double e, double E, double w, double o, double i)       //计算卫星在空间直角坐标系中的y坐标
{
	double y = a * (cos(E) - e) * (cos(w) * sin(o) - sin(w) * cos(o) * cos(i)) + a * sqrt(1 - pow(e, 2)) * sin(E) * (-sin(w) * sin(o) - cos(w) * cos(o) * cos(i));
	
	return y;
}

/*************************************************************************************
*描述：getZ()函数用于计算卫星在空间直角坐标系中的z坐标，输入为椭圆轨道半长轴a、椭圆轨*
*      道偏心率e、偏近地点角E、近地点幅角w和椭圆轨道倾角i，输出为卫星在空间直角坐标系*
*      中的z坐标。                                                                   *
*************************************************************************************/
double Track::getZ(double a, double e, double E, double w, double i)                //计算卫星在空间直角坐标系中的z坐标
{
	double z = a * (cos(E) - e) * sin(w) * sin(i) + a * sqrt(1 - pow(e, 2)) * sin(E) * cos(w) * sin(i);
	
	return z;
}

/*************************************************************************************
*描述：getVX()函数用于计算卫星在空间直角坐标系中x轴方向的速度vx，输入为椭圆轨道半长轴*
*      a、椭 圆轨道偏心率e、偏近地点角E、近地点幅角w、升交点赤经o和椭圆轨道倾角i，输 *
*      出为卫星在空 间直角坐标系中x轴方向的速度vx。                                  *
*************************************************************************************/
double Track::getVX(double a, double e, double E, double w, double o, double i)     //计算卫星在空间直角坐标系中的x轴方向的速度
{
	double u = 3.986005e14;
	double x = getX(a, e, E, w, o, i);
	double y = getY(a, e,E, w, o, i);
	double z = getZ(a, e, E, w, i);
	double r = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	double vx = sqrt(u * a) * (-sin(E)) * (cos(w) * cos(o) - sin(w) * sin(o) * cos(i)) / r + sqrt(1 - pow(e, 2)) * cos(E) * (-sin(w) * cos(o) - cos(w) * sin(o) * cos(i));
	
	return vx;
}

/*************************************************************************************
*描述：getVY()函数用于计算卫星在空间直角坐标系中y轴方向的速度vy，输入为椭圆轨道半长轴*
*      a、椭圆轨道偏心率e、偏近地点角E、近地点幅角w、升交点赤经o和椭圆轨道倾角i，输出*
*      为卫星在空间直角坐标系中y轴方向的速度vy。                                     *
*************************************************************************************/
double Track::getVY(double a, double e, double E, double w, double o, double i)     //计算卫星在空间直角坐标系中的y轴方向的速度
{
	double u = 3.986005e14;
	double x = getX(a, e, E, w, o, i);
	double y = getY(a, e, E, w, o, i);
	double z = getZ(a, e, E, w, i);
	double r = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	double vy = sqrt(u * a) * (-sin(E)) * (cos(w) * sin(o) + sin(w) * cos(o) * cos(i)) / r + sqrt(1 - pow(e, 2)) * cos(E) * (-sin(w) * sin(o) + cos(w) * cos(o) * cos(i));
	
	return vy;
}

/*************************************************************************************
*描述：getVZ()函数用于计算卫星在空间直角坐标系中z轴方向的速度vz，输入为椭圆轨道半长轴*
*      a、椭 圆轨道偏心率e、偏近地点角E、近地点幅角w、升交点赤经o和椭圆轨道倾角i，输 *
*      出为卫星在空间直角坐标系中z轴方向的速度vz。                                   *
*************************************************************************************/
double Track::getVZ(double a, double e, double E, double w, double o, double i)     //计算卫星在空间直角坐标系中的z轴方向的速度
{
	double u = 3.986005e14;
	double x = getX(a, e, E, w, o, i);
	double y = getY(a, e, E, w, o, i);
	double z = getZ(a, e, E, w, i);
	double r = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	double vz = sqrt(u * a) * (-sin(E)) * sin(w) * sin(i) / r + sqrt(1 - pow(e, 2)) * cos(E) * cos(w) * sin(i);
	
	return vz;
}
