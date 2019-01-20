
#include "Circle.h"
#define _USE_MATH_DEFINES
#include <math.h>

Circle::Circle(int in) :r(in)
{
    if (r < 0)
    {
        r = 1;
        throw std::invalid_argument("Exception: r is negative");        
    }
}

Circle::Circle(vector<string> pars) :
    Circle(pars.size()==1 ? std::stod(pars[0]) : 0)
{
//    if (pars.size() != 1)
//        throw std::logic_error("Exception: error in reading file textDataFile.txt - try to delete this file and restart");    
}

double Circle::area(void) const
{
    return M_PI * r*r;
}

std::string Circle::print() const
{
    string s = "Circle (r: " + std::to_string(r) + ")";
    return s;
}

std::string Circle::printToFile() const
{
    string s = std::to_string(r) + " Circle ";
    return s;
}

std::istream& Circle::read(std::istream& in)
{
    std::cout << "Input circle radius: ";
    in >> this->r;
    return in;
}
