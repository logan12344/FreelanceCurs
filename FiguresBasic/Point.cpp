#include "Point.h"
#include <iomanip>

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
	strm << "\n___________________";
	strm << "\n|   X    |    Y   |";
	strm << "\n|________|________|";
	strm << "\n|" << setw(8) << xval << "|" << setw(8) << yval << "|";
	strm << "\n|________|________|";
}

std::istream& operator>>(std::istream& in, Point &p)
{
    std::cout << "Input x: ";
    in >> p.xval;
    std::cout << "Input y: ";
    in >> p.yval;
    return in;
}