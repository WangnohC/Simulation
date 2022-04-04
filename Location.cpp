/*************************************************************************************
* �ļ����ƣ�����λ��ģ��                                                             *
* ��    �ߣ�                                                                         *
* ��    ����                                                                         *
* ��    �ڣ�                                                                         *
* ����������������Ϊ����λ��ģ�ͣ����ڼ��㵼����������ϵ�е����ꡣ                   *
* ��    �룺�ó���Ϊ�����룬����Ϊ�����ڷ�������ϵ��ˮƽ�����λ�ƺ���ֱ�����λ�ơ� *
* ��    �����ó������Ϊ����������Ϊ������������ϵ�е����ꡣ                       *
* �����б�1.getMR()�������ڼ��㵼����������ϵ�еľ��룻                            *
*           2.getMEL()�������ڼ��㵼����������ϵ�е����ǣ�                           *
*           3.getMAZ()�������ڼ��㵼����������ϵ�еķ�λ�ǣ�                         *
*           4.getY()�������ڼ��㵼�����Է����Ϊԭ����������ֱ������ϵ�е�y���ꣻ    *
*           5.getZ()�������ڼ��㵼�����Է����Ϊԭ����������ֱ������ϵ�е�z���ꣻ    *
*           6.getX()�������ڼ��㵼�����Է����Ϊԭ����������ֱ������ϵ�е�x���ꣻ    *
*           7.getMx()�������ڼ��㵼���ڷ�������ϵ����ˮƽ�����λ�ƣ�                *
*           8.getMy()�������ڼ��㵼���ڷ�������ϵ������ֱ�����λ�ơ�                *
* ��    ʷ��                                                                         *
*                   Copyright (c) wangchong. All Rights Reserved                     *
*************************************************************************************/

#include "Location.h"
#include <cmath>

Location::Location()
{
}


Location::~Location()
{
}

/*************************************************************************************
* ������getMR()�������ڼ��㵼����������ϵ�еľ������r������Ϊ��������ķ�λ��MA0����*
*       ��ˮƽ�����λ��MX�͵�����ֱ�����λ��MY�����Ϊ������������ϵ�еľ������r��*
*************************************************************************************/
double Location::getMR(double MA0, double MX, double MY)                           //���㵼����������ϵ�еľ��루�ο���ģ��ԭ���ĵ���
{
	double RE = 6371000;
	double x = MX * cos(MA0);
	double y = MX * sin(MA0);
	double z = MY;
	double s = sqrt(pow(x, 2) + pow(z, 2));
	double B = atan(x / z);
	double l = sqrt(pow(RE, 2) + pow(s, 2) + 2 * RE * s * cos(B));
	double r = sqrt(pow(l, 2) + pow(y, 2));

	return r;
}

/*************************************************************************************
* ������getMEL()�������ڼ��㵼����������ϵ�е�����MEL������Ϊ������������ϵ�еĳ�ʼ��*
*       ��Mq0����������ķ�λ��MA0������ˮƽ�����λ��MX�͵�����ֱ�����λ��MY����� *
*       Ϊ������������ϵ�е�����MEL��                                                *
*************************************************************************************/
double Location::getMEL(double Mq0, double MA0, double MX, double MY)              //���㵼����������ϵ�е����ǣ��ο���ģ��ԭ���ĵ���
{
	double RE = 6371000;
	double x = MX * cos(MA0);
	double y = MX * sin(MA0);
	double z = MY;
	double s = sqrt(pow(x, 2) + pow(z, 2));
	double B = atan(x / z);
	double l = sqrt(pow(RE, 2) + pow(s, 2) + 2 * RE * s * cos(B));
	double r = sqrt(pow(l, 2) + pow(y, 2));
	double m = acos((pow(RE, 2) + pow(l, 2) - pow(s, 2)) / (2 * RE * l));
	double MEL = acos((l / r * cos(Mq0 + m)));

	return MEL;
}

/*************************************************************************************
* ������getMAZ()�������ڼ��㵼����������ϵ�еķ�λ��MAZ������Ϊ������������ϵ�еĳ�ʼ*
*       ��λ��Ma0����ʼ����Mq0����������ķ�λ��MA0������ˮƽ�����λ��MX�͵�����ֱ��*
*       ���λ��MY�����Ϊ������������ϵ�еķ�λ��MAZ��                              *
*************************************************************************************/
double Location::getMAZ(double Ma0, double Mq0, double MA0, double MX, double MY)  //���㵼����������ϵ�еķ�λ�ǣ��ο���ģ��ԭ���ĵ���
{
	double RE = 6371000;
	double x = pow(MX, 2) + pow(MY, 2);
	double y = getMR(MA0, MX, MY); 
	double z = getMEL(Mq0, MA0, MX, MY);
	double l = y * cos(z) - RE * cos(Mq0);
	double d = x - pow(l, 2);
	double B = RE * sin(Mq0);
	double C = y * sin(z);
	double D = acos((pow(C, 2) + pow(B, 2) - d) / (2 * B * C));
	double MAZ = Ma0 + D;

	return MAZ;
}

/*************************************************************************************
* ������getY()�������ڼ��㵼�����Է����Ϊԭ���ֱ������ϵ�е�y���꣬����Ϊ����������*
*       ��ϵ�е�����r��theta��phi�Լ���������������theta0�ͷ�λ��phi0�����Ϊ������*
*       �Է����Ϊԭ���ֱ������ϵ�е�y���ꡣ                                        *
*************************************************************************************/
double Location::getY(double r, double theta, double phi, double theta0, double phi0)//���㵼�����Է����Ϊԭ���ֱ������ϵ�е�y����
{
	double phi_ = phi - phi0;
	double RE = 6371000;
	double A = RE * sin(theta0);
	double B = r * sin(theta);
	double C = pow(A, 2) + pow(B, 2) - 2 * A * B * cos(phi_);
	double D = r * cos(theta) - RE * cos(theta0);
	double E = C + pow(D, 2);
	double F = (pow(RE, 2) + pow(r, 2) - E) / (2 * RE);
	double G = F * cos(theta0) - r * cos(theta);
	double H = F * sin(theta0);
	double I = G / H;
	double gamma = atan(I);
	double r_ = r * cos(theta) / cos(theta0 + gamma);
	double y = sqrt(pow(r, 2) - pow(r_, 2));

	return y;
}

/*************************************************************************************
* ������getZ()�������ڼ��㵼�����Է����Ϊԭ���ֱ������ϵ�е�z���꣬����Ϊ����������*
*       ��ϵ�е�����r��theta��phi�Լ���������������theta0�ͷ�λ��phi0�����Ϊ������*
*       �Է����Ϊԭ���ֱ������ϵ�е�z���ꡣ                                        *                                                                             *
*************************************************************************************/
double Location::getZ(double r, double theta, double phi, double theta0, double phi0)//���㵼�����Է����Ϊԭ���ֱ������ϵ�е�z����
{
	double y = getY(r, theta, phi, theta0, phi0);
	double phi_ = phi - phi0;
	double RE = 6371000;
	double A = RE * sin(theta0);
	double B = r * sin(theta);
	double C = pow(A, 2) + pow(B, 2) - 2 * A * B * cos(phi_);
	double D = r * cos(theta) - RE * cos(theta0);
	double E = C + pow(D, 2);
	double F = (pow(RE, 2) + E - pow(r, 2)) / (2 * RE);
	double G = E - pow(y, 2);
	double H = G / pow(F, 2) - 1;
	double z = sqrt(G / (H + 1));

	return z;
}

/*************************************************************************************
* ������getX()�������ڼ��㵼�����Է����Ϊԭ���ֱ������ϵ�е�x���꣬����Ϊ����������*
*       ��ϵ�е�����r��theta��phi�Լ���������������theta0�ͷ�λ��phi0�����Ϊ������*
*       �Է����Ϊԭ���ֱ������ϵ�е�x���ꡣ                                        *                                                                             *
*************************************************************************************/
double Location::getX(double r, double theta, double phi, double theta0, double phi0)//���㵼�����Է����Ϊԭ���ֱ������ϵ�е�x����
{
	double y = getY(r, theta, phi, theta0, phi0);
	double phi_ = phi - phi0;
	double RE = 6371000;
	double A = RE * sin(theta0);
	double B = r * sin(theta);
	double C = pow(A, 2) + pow(B, 2) - 2 * A * B * cos(phi_);
	double D = r * cos(theta) - RE * cos(theta0);
	double E = C + pow(D, 2);
	double F = (pow(RE, 2) + E - pow(r, 2)) / (2 * RE);
	double G = E - pow(y, 2);
	double H = G / pow(F, 2) - 1;
	double x = sqrt(G * H / (H + 1));

	return x;
}

/*************************************************************************************
* ������getMx()�������ڼ��㵼���ڷ�������ϵ��ˮƽ�����λ��Mx������Ϊ������������ϵ��*
*       ������r��theta��phi�Լ���������������theta0�ͷ�λ��phi0�����Ϊ�����ڷ�����*
*       ��ϵ����ˮƽ�����λ��Mx��                                                   *                                                                             *
*************************************************************************************/
double Location::getMx(double r, double theta, double phi, double theta0, double phi0)//���㵼���ڷ�������ϵ��ˮƽ�����λ��
{
	double x = getX(r, theta, phi, theta0, phi0);
	double y = getY(r, theta, phi, theta0, phi0);
	double Mx = sqrt(pow(x, 2) + pow(y, 2));

	return Mx;
}

/*************************************************************************************
* ������getMy()�������ڼ��㵼���ڷ�������ϵ����ֱ�����λ��My������Ϊ������������ϵ��*
*       ������r��theta��phi�Լ���������������theta0�ͷ�λ��phi0�����Ϊ�����ڷ�����*
*       ��ϵ������ֱ�����λ��My��                                                   *                                                                             *
*************************************************************************************/
double Location::getMy(double r, double theta, double phi, double theta0, double phi0)//���㵼���ڷ�������ϵ����ֱ�����λ��
{
	double z = getZ(r, theta, phi, theta0, phi0);
	double My = z;

	return My;
}
