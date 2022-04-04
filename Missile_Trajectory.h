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

	double Interpolation(double w, int n, double ax[][2]);                    //��ֵ����
	vector<double> Differential(double xy[NumbVars]);                         //�Ժ���΢��
	void Runge_Kutta(double rk_step, double y[NumbVars]);                     //�Ľ������������ⳣ΢�ַ���
	void Read_Array(double *array, int n1, int n2, FILE *fp);                 //��ȡ����
public:
	Missile_Trajectory();
	~Missile_Trajectory();

	vector <double> Read_Data(void);                                          //��ȡ����
	vector <double> Ballistic_Calculation(double t, vector <double> y00);     //���㵯��
};

