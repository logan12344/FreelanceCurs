
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"

class Triangle:
public Figure
{
    double a,b,c;

public:
    Triangle(double s1=0,double s2=0,double s3=0);
    Triangle(vector<string> pars);
    double area(void)const;
    std::string print() const;
    std::string printToFile() const;
    std::istream& read(std::istream&);
};

#endif /* TRIANGLE_H */
