
#include "Rectangle.h"

Rectangle::Rectangle(double inX, double inY ):a(inX),b(inY)
{
    if(a<0)
    {
        a = 1;
        throw std::invalid_argument("Exception: a is negative");        
    }

    if(b<0)
    {
        b = 1;
        throw std::invalid_argument("Exception: b is negative");        
    }
}

Rectangle::Rectangle(vector<string> pars) :
    Rectangle(pars.size() == 2 ? std::stod(pars[0]) : 0, pars.size() == 2 ? std::stod(pars[1]) : 0)
{
}

double Rectangle::area(void) const
{
    return a*b;
}

std::string Rectangle::print() const
{
    string s = "Rectangle (a: " + std::to_string(a) + ", b:" + std::to_string(b) + ")";
    return s;
}

std::string Rectangle::printToFile() const
{
    string s = std::to_string(a) + " " + std::to_string(b) + " Rectangle ";
    return s;
}

std::istream& Rectangle::read(std::istream& in)
{
    std::cout << "Input rectangle side 'a': ";
    in >> this->a;
    std::cout << "Input rectangle side 'b': ";
    in >> this->b;

    return in;
}