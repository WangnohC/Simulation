#pragma once
class Atmospheric_Background_Radiation
{
public:
	Atmospheric_Background_Radiation();
	~Atmospheric_Background_Radiation();

	double getAtmospheric_Background_Radiation(double h, double RD);     //计算探测器所接受到的噪声
};

