#pragma once
class Track
{
public:
	Track();
	~Track();

	double getE(double a, double e, double tp, double t);                     //����ƫ�����E
	double getX(double a, double e, double E, double w, double o, double i);  //���������ڿռ�ֱ������ϵ�е�X����
	double getY(double a, double e, double E, double w, double o, double i);  //���������ڿռ�ֱ������ϵ�е�Y����
	double getZ(double a, double e, double E, double w, double i);            //���������ڿռ�ֱ������ϵ�е�Z����
	double getVX(double a, double e, double E, double w, double o, double i); //���������ڿռ�ֱ������ϵX�᷽����ٶ�VX
	double getVY(double a, double e, double E, double w, double o, double i); //���������ڿռ�ֱ������ϵY�᷽����ٶ�VY
	double getVZ(double a, double e, double E, double w, double o, double i); //���������ڿռ�ֱ������ϵZ�᷽����ٶ�VZ
};
