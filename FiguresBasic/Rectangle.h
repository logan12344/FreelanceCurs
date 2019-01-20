
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

class Rectangle:
public Figure
{
	int a,b;

public:
    Rectangle(int s1=0, int s2=0);
    virtual double area(void)const;
    virtual std::string print() const;
    virtual std::string printToFile() const;
    virtual std::istream& read(std::istream&);
};

#endif /* RECTANGLE_H */
