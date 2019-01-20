
#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>
#include <vector>
#include "Point.h"

class Figure
{
protected:
    Point center;

public:
    Point getCenter() const { return center; }
   // Figure(void);
    virtual double area(void) const = 0;
    virtual std::string print() const = 0;
    virtual std::string printToFile() const = 0;
    virtual std::istream& read(std::istream&) = 0;
    friend std::ostream& operator<<(std::ostream&, Figure&);
    friend std::istream& operator>>(std::istream&, Figure&);
};

 #endif /* FIGURE_H */
