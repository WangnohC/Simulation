#pragma once
class Transformation
{
public:
	Transformation();
	~Transformation();

	double getAzimuth(double Lng);                             //计算方位角
	double getElevation(double Lat);                           //计算仰角
	double getLng(double AZ);                                  //计算经度
	double getLat(double EL);                                  //计算纬度
	double getX(double R, double EL, double AZ);               //计算空间直角坐标系中的x坐标
	double getY(double R, double EL, double AZ);               //计算空间直角坐标系中的y坐标
	double getZ(double R, double EL);                          //计算空间直角坐标系中的z坐标
	double getR(double x, double y, double z);                 //计算球坐标系中的距离
	double getEL(double x, double y, double z);                //计算球坐标系中的仰角
	double getAZ(double x, double y);                          //计算球坐标系中的方位角
	double getDeg(double Rad);                                 //计算角度
	double getRad(double Deg);                                 //计算弧度
};

