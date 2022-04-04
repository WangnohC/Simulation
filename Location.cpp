/*************************************************************************************
* 文件名称：导弹位置模型                                                             *
* 作    者：                                                                         *
* 版    本：                                                                         *
* 日    期：                                                                         *
* 功能描述：本程序为导弹位置模型，用于计算导弹在球坐标系中的坐标。                   *
* 输    入：该程序为多输入，输入为导弹在发射坐标系中水平方向的位移和竖直方向的位移。 *
* 输    出：该程序输出为多输出，输出为导弹在球坐标系中的坐标。                       *
* 函数列表：1.getMR()——用于计算导弹在球坐标系中的距离；                            *
*           2.getMEL()——用于计算导弹在球坐标系中的仰角；                           *
*           3.getMAZ()——用于计算导弹在球坐标系中的方位角；                         *
*           4.getY()——用于计算导弹在以发射点为原点所建立的直角坐标系中的y坐标；    *
*           5.getZ()——用于计算导弹在以发射点为原点所建立的直角坐标系中的z坐标；    *
*           6.getX()——用于计算导弹在以发射点为原点所建立的直角坐标系中的x坐标；    *
*           7.getMx()——用于计算导弹在发射坐标系中沿水平方向的位移；                *
*           8.getMy()——用于计算导弹在发射坐标系中沿竖直方向的位移。                *
* 历    史：                                                                         *
*                   Copyright (c) wangchong. All Rights Reserved                     *
*************************************************************************************/

#include "Location.h"
#include <cmath>

Location::Location()
{
}


Location::~Location()
{
}

/*************************************************************************************
* 描述：getMR()函数用于计算导弹在球坐标系中的距离参数r，输入为导弹发射的方位角MA0、导*
*       弹水平方向的位移MX和导弹竖直方向的位移MY，输出为导弹在球坐标系中的距离参数r。*
*************************************************************************************/
double Location::getMR(double MA0, double MX, double MY)                           //计算导弹在球坐标系中的距离（参考建模的原理文档）
{
	double RE = 6371000;
	double x = MX * cos(MA0);
	double y = MX * sin(MA0);
	double z = MY;
	double s = sqrt(pow(x, 2) + pow(z, 2));
	double B = atan(x / z);
	double l = sqrt(pow(RE, 2) + pow(s, 2) + 2 * RE * s * cos(B));
	double r = sqrt(pow(l, 2) + pow(y, 2));

	return r;
}

/*************************************************************************************
* 描述：getMEL()函数用于计算导弹在球坐标系中的仰角MEL，输入为导弹在球坐标系中的初始仰*
*       角Mq0、导弹发射的方位角MA0、导弹水平方向的位移MX和导弹竖直方向的位移MY，输出 *
*       为导弹在球坐标系中的仰角MEL。                                                *
*************************************************************************************/
double Location::getMEL(double Mq0, double MA0, double MX, double MY)              //计算导弹在球坐标系中的仰角（参考建模的原理文档）
{
	double RE = 6371000;
	double x = MX * cos(MA0);
	double y = MX * sin(MA0);
	double z = MY;
	double s = sqrt(pow(x, 2) + pow(z, 2));
	double B = atan(x / z);
	double l = sqrt(pow(RE, 2) + pow(s, 2) + 2 * RE * s * cos(B));
	double r = sqrt(pow(l, 2) + pow(y, 2));
	double m = acos((pow(RE, 2) + pow(l, 2) - pow(s, 2)) / (2 * RE * l));
	double MEL = acos((l / r * cos(Mq0 + m)));

	return MEL;
}

/*************************************************************************************
* 描述：getMAZ()函数用于计算导弹在球坐标系中的方位角MAZ，输入为导弹在球坐标系中的初始*
*       方位角Ma0、初始仰角Mq0、导弹发射的方位角MA0、导弹水平方向的位移MX和导弹竖直方*
*       向的位移MY，输出为导弹在球坐标系中的方位角MAZ。                              *
*************************************************************************************/
double Location::getMAZ(double Ma0, double Mq0, double MA0, double MX, double MY)  //计算导弹在球坐标系中的方位角（参考建模的原理文档）
{
	double RE = 6371000;
	double x = pow(MX, 2) + pow(MY, 2);
	double y = getMR(MA0, MX, MY); 
	double z = getMEL(Mq0, MA0, MX, MY);
	double l = y * cos(z) - RE * cos(Mq0);
	double d = x - pow(l, 2);
	double B = RE * sin(Mq0);
	double C = y * sin(z);
	double D = acos((pow(C, 2) + pow(B, 2) - d) / (2 * B * C));
	double MAZ = Ma0 + D;

	return MAZ;
}

/*************************************************************************************
* 描述：getY()函数用于计算导弹在以发射点为原点的直角坐标系中的y坐标，输入为导弹在球坐*
*       标系中的坐标r，theta，phi以及导弹发射点的仰角theta0和方位角phi0，输出为导弹在*
*       以发射点为原点的直角坐标系中的y坐标。                                        *
*************************************************************************************/
double Location::getY(double r, double theta, double phi, double theta0, double phi0)//计算导弹在以发射点为原点的直角坐标系中的y坐标
{
	double phi_ = phi - phi0;
	double RE = 6371000;
	double A = RE * sin(theta0);
	double B = r * sin(theta);
	double C = pow(A, 2) + pow(B, 2) - 2 * A * B * cos(phi_);
	double D = r * cos(theta) - RE * cos(theta0);
	double E = C + pow(D, 2);
	double F = (pow(RE, 2) + pow(r, 2) - E) / (2 * RE);
	double G = F * cos(theta0) - r * cos(theta);
	double H = F * sin(theta0);
	double I = G / H;
	double gamma = atan(I);
	double r_ = r * cos(theta) / cos(theta0 + gamma);
	double y = sqrt(pow(r, 2) - pow(r_, 2));

	return y;
}

/*************************************************************************************
* 描述：getZ()函数用于计算导弹在以发射点为原点的直角坐标系中的z坐标，输入为导弹在球坐*
*       标系中的坐标r，theta，phi以及导弹发射点的仰角theta0和方位角phi0，输出为导弹在*
*       以发射点为原点的直角坐标系中的z坐标。                                        *                                                                             *
*************************************************************************************/
double Location::getZ(double r, double theta, double phi, double theta0, double phi0)//计算导弹在以发射点为原点的直角坐标系中的z坐标
{
	double y = getY(r, theta, phi, theta0, phi0);
	double phi_ = phi - phi0;
	double RE = 6371000;
	double A = RE * sin(theta0);
	double B = r * sin(theta);
	double C = pow(A, 2) + pow(B, 2) - 2 * A * B * cos(phi_);
	double D = r * cos(theta) - RE * cos(theta0);
	double E = C + pow(D, 2);
	double F = (pow(RE, 2) + E - pow(r, 2)) / (2 * RE);
	double G = E - pow(y, 2);
	double H = G / pow(F, 2) - 1;
	double z = sqrt(G / (H + 1));

	return z;
}

/*************************************************************************************
* 描述：getX()函数用于计算导弹在以发射点为原点的直角坐标系中的x坐标，输入为导弹在球坐*
*       标系中的坐标r，theta，phi以及导弹发射点的仰角theta0和方位角phi0，输出为导弹在*
*       以发射点为原点的直角坐标系中的x坐标。                                        *                                                                             *
*************************************************************************************/
double Location::getX(double r, double theta, double phi, double theta0, double phi0)//计算导弹在以发射点为原点的直角坐标系中的x坐标
{
	double y = getY(r, theta, phi, theta0, phi0);
	double phi_ = phi - phi0;
	double RE = 6371000;
	double A = RE * sin(theta0);
	double B = r * sin(theta);
	double C = pow(A, 2) + pow(B, 2) - 2 * A * B * cos(phi_);
	double D = r * cos(theta) - RE * cos(theta0);
	double E = C + pow(D, 2);
	double F = (pow(RE, 2) + E - pow(r, 2)) / (2 * RE);
	double G = E - pow(y, 2);
	double H = G / pow(F, 2) - 1;
	double x = sqrt(G * H / (H + 1));

	return x;
}

/*************************************************************************************
* 描述：getMx()函数用于计算导弹在发射坐标系中水平方向的位移Mx，输入为导弹在球坐标系中*
*       的坐标r，theta，phi以及导弹发射点的仰角theta0和方位角phi0，输出为导弹在发射坐*
*       标系中沿水平方向的位移Mx。                                                   *                                                                             *
*************************************************************************************/
double Location::getMx(double r, double theta, double phi, double theta0, double phi0)//计算导弹在发射坐标系中水平方向的位移
{
	double x = getX(r, theta, phi, theta0, phi0);
	double y = getY(r, theta, phi, theta0, phi0);
	double Mx = sqrt(pow(x, 2) + pow(y, 2));

	return Mx;
}

/*************************************************************************************
* 描述：getMy()函数用于计算导弹在发射坐标系中竖直方向的位移My，输入为导弹在球坐标系中*
*       的坐标r，theta，phi以及导弹发射点的仰角theta0和方位角phi0，输出为导弹在发射坐*
*       标系中沿竖直方向的位移My。                                                   *                                                                             *
*************************************************************************************/
double Location::getMy(double r, double theta, double phi, double theta0, double phi0)//计算导弹在发射坐标系中竖直方向的位移
{
	double z = getZ(r, theta, phi, theta0, phi0);
	double My = z;

	return My;
}
