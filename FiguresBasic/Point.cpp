#include "Point.h"

double Point::dist(Point other) {
    double xd = xval - other.xval;
    double yd = yval - other.yval;
    return sqrt(xd*xd + yd * yd);
}

void Point::move(double a, double b)
{
    xval += a;
    yval += b;
}

Point Point::add(Point b)
{
    return Point(xval + b.xval, yval + b.yval);
}

Point Point::sub(Point b)
{
    return Point(xval - b.xval, yval - b.yval);
}

void Point::print(ostream &strm)
{
    strm << "(" << xval << "," << yval << ")";
}

std::istream& operator>>(std::istream& in, Point &p)
{
    std::cout << "Input x: ";
    in >> p.xval;
    std::cout << "Input y: ";
    in >> p.yval;
    return in;
}