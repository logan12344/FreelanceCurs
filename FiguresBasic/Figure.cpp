#include "Figure.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, Figure& f)
{    
    out << f.print() << " with center: ";
    f.center.print(out);
    return out;
}

std::istream& operator>>(std::istream& in, Figure& f)
{    
    f.read(in);
    std::cout << "Input center of "<<f.print() << std::endl;
    in >> f.center;
    return in;
}