/*************************************************************************************
*�ļ����ƣ���������ģ��                                                              *
*��    �ߣ�                                                                          *
*��    ����                                                                          *
*��    �ڣ�                                                                          *
*����������������Ϊͨ�õ����������������򣬿����ڼ��㵼���ڷ�������ϵ����ά���е�λ*
*          �á�                                                                      *
*��    �룺�ó���Ϊ�����룬����Ϊ��Բ����볤�ᡢ��Բ���ƫ���ʡ����ǽ��ص�ʱ�̡�����*
*          ����ǡ�������ྭ����Բ�����ǡ�                                        *
*��    �����ó���Ϊ����������Ϊ���ǵ�λ�ú��ٶȡ�                                  *
*�����б�1.Interpolation()�������ڶ��������ݽ��в�ֵ��                             *
*          2.Differential()�������ڶԺ�������΢�֣�                                  *
*          3.Runge_Kutta()�����������΢�ַ��̣�                                     *
*          4.Read_Array()�������ڶ�ȡ���ݵ����飻                                    *
*          5.Read_Data()�������ڶ�ȡ���ݣ�                                           *
*          6.Ballistic_Calculation()�������ڼ��㵯����                               *
*��    ʷ��                                                                          *
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
* ������Interpolation()�������ڶ����ݽ��в�ֵ���㡣                                  *
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
* ������Differential()�������ڶԺ�������΢�֡�                                       *
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
* ������Runge_Kutta()�����������΢�ַ��̡�                                          *
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
* ������Read_Array()�������ڶ�ȡ�����е����ݡ�                                       *
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
* ������Read_Data()�������ڶ�ȡ���ݡ�                                                *
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
* ������Ballistic_Calculation()�������ڼ��㵯����                                    *
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
