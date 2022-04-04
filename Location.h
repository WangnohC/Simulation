#pragma once
class Location
{
	double getX(double r, double theta, double phi, double theta0, double phi0);
	double getY(double r, double theta, double phi, double theta0, double phi0);
	double getZ(double r, double theta, double phi, double theta0, double phi0);
public:
	Location();
	~Location();

	double getMR(double MA0, double MX, double MY);                           //���㵼����������ϵ�еľ���
	double getMEL(double Mq0, double MA0, double MX, double MY);              //���㵼����������ϵ�е�����
	double getMAZ(double Ma0, double Mq0, double MA0, double MX, double MY);  //���㵼����������ϵ�еķ�λ
	double getMx(double r, double theta, double phi, double theta0, double phi0);
	double getMy(double r, double theta, double phi, double theta0, double phi0);
};
