
#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Figure.h"

class Circle:
public Figure
{
protected:
    double r;

public:
    Circle(int r=0);
    
    double area(void)const;
    std::string print() const;
    std::string printToFile() const;
    std::istream& read(std::istream&);
};

#endif /* CIRCLE_H */
