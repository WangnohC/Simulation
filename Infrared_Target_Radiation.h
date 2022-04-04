#pragma once
class Infrared_Target_Radiation
{
public:
	Infrared_Target_Radiation();
	~Infrared_Target_Radiation();

	double getInfrared_Target_Radiation(double I0, double RD);      //计算探测器所接收到的辐射强度
};

