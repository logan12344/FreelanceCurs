#pragma once

#include <iostream>
#include <math.h>

using namespace std;

class Point {
private:
    double xval, yval;
public:
    // Constructor uses default arguments to allow calling with zero, one,
    // or two values.
    Point(double x = 0.0, double y = 0.0) {
        xval = x;
        yval = y;
    }

    // Extractors.
    double x() { return xval; }
    double y() { return yval; }

    // Distance to another point.  Pythagorean thm.
    double dist(Point other);

    // Add or subtract two points.
    Point add(Point b);
    Point sub(Point b);

    // Move the existing point.
    void move(double a, double b);

    // Print the point on the stream.  The class ostream is a base class
    // for output streams of various types.
    void print(ostream &strm);

    friend std::istream& operator>>(std::istream& in, Point &p);
};