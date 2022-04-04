#pragma once
#include <stdio.h>
#include <vector>
#define G 9.80665
#define RUN_PACE 0.1
#define NumbVars 10

using namespace std;

class Missile_Trajectory
{
	double acx[22][2];
	double acy[10][2];
	double s;

	double Interpolation(double w, int n, double ax[][2]);                    //插值函数
	vector<double> Differential(double xy[NumbVars]);                         //对函数微分
	void Runge_Kutta(double rk_step, double y[NumbVars]);                     //四阶龙格库塔法求解常微分方程
	void Read_Array(double *array, int n1, int n2, FILE *fp);                 //读取数组
public:
	Missile_Trajectory();
	~Missile_Trajectory();

	vector <double> Read_Data(void);                                          //读取数据
	vector <double> Ballistic_Calculation(double t, vector <double> y00);     //计算弹道
};

