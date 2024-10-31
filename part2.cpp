#include <iostream>
#include <fstream>
#include <vector>
#include "header.h"
using namespace std;

void classifyQuadrilateral(vector<lineType>& lines) {
    // Assuming lines vector has exactly 4 lines as per the problem description
    bool isParallel1 = lines[0].parallelLines(lines[0], lines[1]);
    bool isParallel2 = lines[2].parallelLines(lines[2], lines[3]);
    bool isOppositeParallel = (isParallel1 && isParallel2);

    bool isTrapezoid = (isParallel1 || isParallel2) && !(isParallel1 && isParallel2);
    bool isRectangle = isOppositeParallel && lines[0].perpendicularLines(lines[0], lines[2]) && lines[1].perpendicularLines(lines[1], lines[3]);

    bool isSquare = 
    
    // Additional checks for rhombus and square would require distance calculation, 
    // assuming lines are written to satisfy the criteria mentioned.

    if (isRectangle) {
        cout << "Rectangle" << endl;
    } else if (isOppositeParallel) {
        cout << "Parallelogram" << endl;
    } else if (isTrapezoid) {
        cout << "Trapezoid" << endl;
    } else {
        cout << "Square" << endl;
    }
}

int main() {
    ifstream inputFile("datafile.txt");
    if (!inputFile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    double a, b, c;
    vector<lineType> lines;
    int lineCounter = 0;

    // Reading file and storing each set of lines in a vector
    while (inputFile >> a >> b >> c) {
        lineType line(a, b, c);
        lines.push_back(line); 
        lineCounter++;

        // Once we have a set of 4 lines, classify the quadrilateral
        if (lineCounter == 4) {
            classifyQuadrilateral(lines);
            lines.clear();
            lineCounter = 0;
        }
    }

    inputFile.close();
    return 0;
}
