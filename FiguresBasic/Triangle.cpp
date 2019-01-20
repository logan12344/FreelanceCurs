
#include "Triangle.h"
#include <iostream>
#include <math.h>

Triangle::Triangle(int inX, int inY, int inZ) :a(inX), b(inY), c(inZ)
{
    if (a < 0)
    {        
        a = 1;
        throw std::invalid_argument("Exception: a is negative");
    }
    if (b < 0)
    {
        b = 1;
        throw std::invalid_argument("Exception: b is negative!");
    }
    if (c < 0)
    {
        c = 1;
        throw std::invalid_argument("Exception: c is negative!");
    }    
}

double Triangle::area() const
{
	double p = 0.5*(a + b + c);
    return sqrt(p*(p - a)*(p - b)*(p - c));
}

std::string Triangle::print() const
{
    string s = "Triangle (a: " + std::to_string(a) + ", b:" + std::to_string(b) + ", c:" + std::to_string(c) + ")";
    return s;
}

std::string Triangle::printToFile() const
{
    string s = std::to_string(a) + " " + std::to_string(b) + " " + std::to_string(c) + " Triangle ";
    return s;
}

std::istream& Triangle::read(std::istream& in)
{
    std::cout << "Input triangle side 'a': ";
    in >> this->a;
    std::cout << "Input triangle side 'b': ";
    in >> this->b;
    std::cout << "Input triangle side 'c': ";
    in >> this->c;

    if (a + b <= c || a + c <= b || b + c <= a)
    {
        a = 1;
        b = 1;
        c = 1;
        throw std::invalid_argument("Exception: a+b<=c || a+c<=b || b+c<=a");
    }

    return in;
}