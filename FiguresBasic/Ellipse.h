#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <iostream>
#include "Figure.h"

class Ellipse :
    public Figure
{
    double r, R;
    
public:
    Ellipse(double _r=0, double _R=0);
    Ellipse(vector<string> pars);

    double area(void)const;
    std::string print() const;
    std::string printToFile() const;
    std::istream& read(std::istream&);
};

#endif /* ELLIPSE_H */