#pragma once
class Track
{
public:
	Track();
	~Track();

	double getE(double a, double e, double tp, double t);                     //计算偏近点角E
	double getX(double a, double e, double E, double w, double o, double i);  //计算卫星在空间直角坐标系中的X坐标
	double getY(double a, double e, double E, double w, double o, double i);  //计算卫星在空间直角坐标系中的Y坐标
	double getZ(double a, double e, double E, double w, double i);            //计算卫星在空间直角坐标系中的Z坐标
	double getVX(double a, double e, double E, double w, double o, double i); //计算卫星在空间直角坐标系X轴方向的速度VX
	double getVY(double a, double e, double E, double w, double o, double i); //计算卫星在空间直角坐标系Y轴方向的速度VY
	double getVZ(double a, double e, double E, double w, double o, double i); //计算卫星在空间直角坐标系Z轴方向的速度VZ
};
