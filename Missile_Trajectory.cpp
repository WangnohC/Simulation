/*************************************************************************************
*文件名称：导弹弹道模型                                                              *
*作    者：                                                                          *
*版    本：                                                                          *
*日    期：                                                                          *
*功能描述：本程序为通用导弹弹道仿真计算程序，可用于计算导弹在发射坐标系（二维）中的位*
*          置。                                                                      *
*输    入：该程序为多输入，输入为椭圆轨道半长轴、椭圆轨道偏心率、卫星近地点时刻、近地*
*          点幅角、升交点赤经和椭圆轨道倾角。                                        *
*输    出：该程序为多输出，输出为卫星的位置和速度。                                  *
*函数列表：1.Interpolation()——用于对现有数据进行插值；                             *
*          2.Differential()——用于对函数进行微分；                                  *
*          3.Runge_Kutta()——用于求解微分方程；                                     *
*          4.Read_Array()——用于读取数据到数组；                                    *
*          5.Read_Data()——用于读取数据；                                           *
*          6.Ballistic_Calculation()——用于计算弹道。                               *
*历    史：                                                                          *
*                   Copyright (c) wangchong. All Rights Reserved                     *
*************************************************************************************/

#include "Missile_Trajectory.h"
#include <cmath>
#include <stdlib.h>
#include <conio.h>
#include <vector>

using namespace std;

Missile_Trajectory::Missile_Trajectory()
{
}

Missile_Trajectory::~Missile_Trajectory()
{
}

/*************************************************************************************
* 描述：Interpolation()函数用于对数据进行插值计算。                                  *
*************************************************************************************/
double Missile_Trajectory::Interpolation(double w, int n, double ax[][2])
{
	double x; 
	int i;
	if (w < ax[0][0] || w > ax[n - 1][0])
	{
		exit(-1);
	}
	for (i = 0; w > ax[i][0];)
	{
		i++;
	}
	if (i == 0)
	{
		i = 1;
	}
	if (i == n - 1)
	{
		i = n - 2;
	}
	x = ax[i - 1][1] * (w - ax[i][0]) * (w - ax[i + 1][0])
		/ ((ax[i - 1][0] - ax[i][0]) * (ax[i - 1][0] - ax[i + 1][0])) +
		ax[i][1] * (w - ax[i - 1][0]) * (w - ax[i + 1][0])
		/ ((ax[i][0] - ax[i - 1][0]) * (ax[i][0] - ax[i + 1][0])) +
		ax[i + 1][1] * (w - ax[i - 1][0]) * (w - ax[i][0])
		/ ((ax[i + 1][0] - ax[i - 1][0]) * (ax[i + 1][0] - ax[i][0]));
	
	return x;
}

/*************************************************************************************
* 描述：Differential()函数用于对函数进行微分。                                       *
*************************************************************************************/
vector <double>  Missile_Trajectory::Differential(double xy[NumbVars])
{
	double xf, yf, mach, q, rho, alpha, T, ps, sonic, dy[NumbVars];
	const double T0 = 289.05, p0 = 99991.5, R = 287.053;

	T = T0 - 0.0063 * xy[4]; 
	ps = p0 * pow(T / T0, 5.4246);
	sonic = sqrt(1.4 * R * T);
	rho = ps / (R * T);
	q = 0.5 * rho * xy[1] * xy[1];
	mach = xy[1] / sonic;
	alpha = 0.0;
	xf = q * s * Interpolation(mach, 22, acx);
	yf = q * s * alpha * Interpolation(mach, 10, acy);
	dy[0] = 1.0;
	dy[1] = (0.0 - xf - G * xy[5] * sin(xy[2])) / xy[5];
	dy[2] = yf / (xy[5] * xy[1]) - G * cos(xy[2]) / xy[1];
	dy[3] = xy[1] * cos(xy[2]);
	dy[4] = xy[1] * sin(xy[2]);
	dy[5] = 0.0;
	vector <double> DY(dy, dy + NumbVars);

	return DY;
}

/*************************************************************************************
* 描述：Runge_Kutta()函数用于求解微分方程。                                          *
*************************************************************************************/
void Missile_Trajectory::Runge_Kutta(double rk_step, double y[NumbVars])
{
	double a[4], b[NumbVars], c[NumbVars];
	int i, j;

	a[0] = rk_step / 2; 
	a[1] = rk_step / 2; 
	a[2] = rk_step; 
	a[3] = rk_step;
	vector <double> dy = Differential(y);
	for (i = 0; i < NumbVars; i++)
	{
		b[i] = y[i];
	}
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i<NumbVars; i++)
		{
			c[i] = b[i] + a[j] * dy[i];
			y[i] = y[i] + a[j + 1] * dy[i] / 3;
		}
		dy = Differential(c);
	}
	for (i = 0; i < NumbVars; i++)
	{
		y[i] = y[i] + a[0] * dy[i] / 3;
	}
}

/*************************************************************************************
* 描述：Read_Array()函数用于读取数组中的数据。                                       *
*************************************************************************************/
void Missile_Trajectory::Read_Array(double *array, int n1, int n2, FILE *fp)
{
	int i, j;
	float q;
	
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			fscanf_s(fp, "%f", &q);
			*array++ = (double)q;
		}
	}
}

/*************************************************************************************
* 描述：Read_Data()函数用于读取数据。                                                *
*************************************************************************************/
vector <double> Missile_Trajectory::Read_Data(void)
{
	float v1;
	double y00[NumbVars];
	FILE *fp;

	fopen_s(&fp, "Missile_Trajectory_Input.dat", "r");
	Read_Array((double *)acx, 22, 2, fp);
	Read_Array((double *)acy, 10, 2, fp);
	fscanf_s(fp, "%f", &v1);
	s = pow(v1, 2) * 3.1415926 / 4.;
	Read_Array(y00, 1, NumbVars, fp);
	fclose(fp);
	vector <double> Y00(y00, y00 + NumbVars);

	return Y00;
}

/*************************************************************************************
* 描述：Ballistic_Calculation()函数用于计算弹道。                                    *
*************************************************************************************/
vector <double> Missile_Trajectory::Ballistic_Calculation(double t, vector <double> y00)
{
	int i;
	double y[NumbVars];

	for (i = 0; i < NumbVars; i++)
	{
		y[i] = y00[i];
	}
	if (y[4] >= 0.)
	{
		Runge_Kutta(RUN_PACE, y);
	}
	vector <double> Coordinate(y, y + NumbVars);

	return Coordinate;
}
