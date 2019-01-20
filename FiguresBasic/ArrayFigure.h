#pragma once
#include "Figure.h"

class ArrayFigure : public Figure
{
public:
	int *numbers;
	Figure *arr;
	
	void showArr() {
		string print();
	}

	int &operator[](int j)
	{
		return numbers[j];
	}
};