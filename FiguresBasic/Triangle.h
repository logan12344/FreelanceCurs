
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"

class Triangle:
public Figure
{
protected:
	int a,b,c;

public:
    Triangle(int s1=0, int s2=0, int s3=0);
	double area(void)const;
    std::string print() const;
    std::string printToFile() const;
    std::istream& read(std::istream&);
};

#endif /* TRIANGLE_H */
