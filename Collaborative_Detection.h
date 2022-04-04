#pragma once
#include <vector>

using namespace std;

class Collaborative_Detection
{
public:
	Collaborative_Detection();
	~Collaborative_Detection();

	double getZ(double x1, double y1, double z1, double L1, double x2, double y2, double z2, double L2, double x3, double y3, double z3, double L3);
	double getY(double x1, double y1, double z1, double L1, double x2, double y2, double z2, double L2, double x3, double y3, double z3, double L3);
	double getX(double x1, double y1, double z1, double L1, double x2, double y2, double z2, double L2, double x3, double y3, double z3, double L3);
};

