
#include <iostream>
#include <conio.h>
#include <fstream>
#include "Figure.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Ellipse.h"

using namespace std;

enum EFiguresTypes {
    eFTCircle = 0,
    eFTTriangle,
    eFTRectangle,
    eFTEllipse,
    eFTLast
};

template <class T>
T getArithmeticMean(T *areaValues, int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += areaValues[i];
    }

    return sum / count;
}

Figure *createFigure(EFiguresTypes type, vector<string> params=vector<string>()) {
    Figure *f = nullptr;
    switch (type)
    {
    case eFTCircle:
        f = new Circle();
        break;
    case eFTTriangle:
        f = new Triangle();
        break;
    case eFTRectangle:
        f = new Rectangle();
        break;
    case eFTEllipse:
        f = new Ellipse();
        break;
    }

    if (params.size() > 0)
        return f;

    if (f)
    {
        std::cin >> *f;
        return f;
    }
    throw std::logic_error("Incorrect figure type");
}

const char textDataFile[] = { "textDataFile.txt" };
const char binaryDataFile[] = { "binaryDataFile.txt" };

bool is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

int main()
{
    int count=0;
    int openFormat = 0;
    double *areaValues = nullptr;
    Figure** figures = nullptr;

    std::cout << "Load data from previous session (1 - yes, 2 - no):";
    //std::cout << "Load data from previous session? \n (type: 0 - to load data in text format, \n 1 - to load data in binary format, \n 2 - don't load previous data):" << std::endl;
    std::cin >> openFormat;
    
    if (openFormat <= 1)
    {        
        if (is_file_exist(textDataFile))
        {
            std::ifstream infile(textDataFile);
            string str;
            vector<Figure*> figrs;
            vector<string> params;
            
            while (infile >> str)//(!str.empty())
            {
                if (str == "Circle") {
                    figrs.push_back(createFigure(eFTCircle, params));
                    params.clear(); str.clear();
                }
                else if (str == "Triangle") {
                    figrs.push_back(createFigure(eFTTriangle, params));
                    params.clear(); str.clear();
                }
                else if (str == "Rectangle") {
                    figrs.push_back(createFigure(eFTRectangle, params));
                    params.clear(); str.clear();
                }
                else if (str == "Ellipse") {
                    figrs.push_back(createFigure(eFTEllipse, params));
                    params.clear(); str.clear();
                }
                else {
                    params.push_back(str);
                }
                //infile >> str;
            }

            infile.close();

            int cnt = figrs.size();
            count = cnt;
            if (cnt > 0)
            {
                areaValues = new double[cnt];
                figures = new Figure*[cnt];

                for (int i = 0; i < cnt; i++)
                {
                    figures[i] = figrs[i];
                }
            }
        }
    }
    else
    {
        std::cout << "Input figures count :  ";
        std::cin >> count;
        std::cout << "################################" << std::endl;

        areaValues = new double[count];
        figures = new Figure*[count];

        try {
            for (int i = 0; i < count; i++)
            {
                int fType = 0;
                std::cout << "Choose figure type (0 - Circle, 1 - Triangle, 2 - Rectangle, 3 - Ellipse): ";
                std::cin >> fType;

                //EFiguresTypes t = EFiguresTypes(i % (int)eFTLast);
                figures[i] = createFigure((EFiguresTypes)fType);
                std::cout << "================================" << std::endl;
            }
        }
        catch (std::exception e)
        {
            std::cout << e.what() << endl;
        }
    }


    std::cout << std::endl;
    std::cout << "Print all figures" << std::endl;
    std::cout << "################################" << std::endl;

    double sumX = 0;
    double sumY = 0;

    for (int i = 0; i < count; i++)
    {
        areaValues[i] = figures[i]->area();
        sumX += figures[i]->getCenter().x();
        sumY += figures[i]->getCenter().y();

        cout << *figures[i] << endl;
        cout << "Area :  " << areaValues[i] << endl;
        std::cout << "================================" << std::endl;
    }

    std::cout << "################################" << std::endl;
    std::cout << "All figures mean area = " << getArithmeticMean<double>(areaValues, count) << std::endl;
    std::cout << "################################" << std::endl;
    std::cout << "All figures center mean (x, y) = (" << sumX / count << ", " << sumY / count << ")" << std::endl;
    std::cout << "################################" << std::endl;
    std::cout << std::endl;

    int dataFormat = 0;
    std::cout << "Save data to file..." << std::endl;
    //std::cout << "Save data to file, choose format (0 - text format, 1 - binary format, 2 - don't save data to file):" << std::endl;
    //std::cin >> dataFormat;

    if (dataFormat <= 1)
    {
        ios_base::openmode mode = (dataFormat==0 ? ios_base::out : ios_base::binary);
        std::ofstream outfile(dataFormat == 0 ? textDataFile : binaryDataFile, mode);
        //outfile << "Count: " << count << "\n";
        for (int i = 0; i < count; i++)
        {
            //const string &str = figures[i]->print();
            //outfile.write(str.c_str(), str.size());
            outfile << figures[i]->printToFile() << "\n";
        }
        outfile.close();
        std::cout << "Data saved" << std::endl;
    }
    else
        std::cout << "Data not Saved" << std::endl;

    std::cout << "################################" << std::endl;
    std::cout << "################################" << std::endl;

    delete[] areaValues;
    delete [] figures;
    _getch();
}

