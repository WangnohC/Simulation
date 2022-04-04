#pragma once
class Location
{
	double getX(double r, double theta, double phi, double theta0, double phi0);
	double getY(double r, double theta, double phi, double theta0, double phi0);
	double getZ(double r, double theta, double phi, double theta0, double phi0);
public:
	Location();
	~Location();

	double getMR(double MA0, double MX, double MY);                           //计算导弹在球坐标系中的距离
	double getMEL(double Mq0, double MA0, double MX, double MY);              //计算导弹在球坐标系中的仰角
	double getMAZ(double Ma0, double Mq0, double MA0, double MX, double MY);  //计算导弹在球坐标系中的方位
	double getMx(double r, double theta, double phi, double theta0, double phi0);
	double getMy(double r, double theta, double phi, double theta0, double phi0);
};
