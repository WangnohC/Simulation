#pragma once
class Transformation
{
public:
	Transformation();
	~Transformation();

	double getAzimuth(double Lng);                             //���㷽λ��
	double getElevation(double Lat);                           //��������
	double getLng(double AZ);                                  //���㾭��
	double getLat(double EL);                                  //����γ��
	double getX(double R, double EL, double AZ);               //����ռ�ֱ������ϵ�е�x����
	double getY(double R, double EL, double AZ);               //����ռ�ֱ������ϵ�е�y����
	double getZ(double R, double EL);                          //����ռ�ֱ������ϵ�е�z����
	double getR(double x, double y, double z);                 //����������ϵ�еľ���
	double getEL(double x, double y, double z);                //����������ϵ�е�����
	double getAZ(double x, double y);                          //����������ϵ�еķ�λ��
	double getDeg(double Rad);                                 //����Ƕ�
	double getRad(double Deg);                                 //���㻡��
};

