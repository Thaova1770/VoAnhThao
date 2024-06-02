#pragma once
#include <vector>
#include <string>
using namespace std;
class Point
{
private:
	double x, y;

public:
	vector<Point> pointList;
	bool operator<(Point& other);
	double getX()const;
	double getY()const;
	void addPoint(double x, double y);
	void saveToFile(const string& filename);
	void Docfile(const string& filename);
	Point(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}
};

