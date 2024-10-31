#include <iostream>
#include <fstream>
#include <vector>
#include "header.h"
using namespace std;

void findShape(vector<lineType>& lines) {

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

    while (inputFile >> a >> b >> c) {
        // Read the 4 lines and then call findShape function for each set of 4
        lineType line(a, b, c);
        lines.push_back(line); 
        lineCounter++;

        
        if (lineCounter == 4) {
            findShape(lines);
            lines.clear();
            lineCounter = 0;
        }
    }

    inputFile.close();
    return 0;
}
