#pragma once
#include "Figure.h"

class ArrayFigure : public Figure
{
public:
	Figure *arr[5];
	
	void showArr() {
		string print();
	}
};