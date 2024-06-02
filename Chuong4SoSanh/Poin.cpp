#include "Poin.h"
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

bool Point::operator<(Point& other)
{
    return sqrt(x * x + y * y) < sqrt(other.x * other.x + other.y * other.y);
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

void Point::addPoint(double x, double y)
{
    pointList.emplace_back(Point(x, y));
}
void Point::saveToFile(const string& filename) {
    ofstream outfile(filename);
    if (!outfile) {
        cerr << "Khong the mo file!" << std::endl;
        return;
    }

    outfile << pointList.size() << endl;
    for (const Point& p : pointList) {
        outfile << p.x << " " << p.y << endl;
    }
    outfile.close();
}

void Point::Docfile(const string& filename)
{
    ifstream infile(filename);
    if (!infile) {
        cerr << "Khong the mo file!" << endl;
        return;
    }

    int numPoints;
    infile >> numPoints;
    for (int i = 0; i < numPoints; ++i) {
        double x, y;
        infile >> x >> y;
        addPoint(x, y);
    }
    infile.close();
}