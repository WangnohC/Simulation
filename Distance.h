#pragma once
class Distance
{
public:
	Distance();
	~Distance();

	double getRelative_Distance(double xs, double ys, double zs, double xm, double ym, double zm);   //计算卫星与导弹之间的相对距离
};

