#include "Ellipse.h"
#define _USE_MATH_DEFINES
#include <math.h>

Ellipse::Ellipse(double _r, double _R) 
    : r(_r)
    , R(_R)
{
    if (r < 0 || R < 0)
    {
        r = 1;
        R = 1;
        throw std::invalid_argument("Exception: r or R negative");
    }
}

double Ellipse::area(void) const
{
    return M_PI*r*R;
}

std::string Ellipse::print() const
{
    string s = "Ellipse (r: "+ std::to_string(r) +", R:" + std::to_string(R) + ")";
    return s;
}

std::string Ellipse::printToFile() const
{
    string s = std::to_string(r) + " " + std::to_string(R) + " Ellipse ";
    return s;
}

std::istream& Ellipse::read(std::istream& in)
{
    std::cout << "Input ellipse radius 1: ";
    in >> this->r;
    std::cout << "Input ellipse radius 2: ";
    in >> this->R;
    return in;
}
