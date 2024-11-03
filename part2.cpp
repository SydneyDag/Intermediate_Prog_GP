#include <iostream>
#include <fstream>
#include <vector>
#include "implementation.cpp"
using namespace std;

// Helper function to find distance between two points
// Distance formula is sqrt((x2 - x1)^2 + (y2 - y1)^2)
// We represent x2, y2 ... in code with p2.first, p2.second respectively
double distance(const pair<double, double> &p1, const pair<double, double> &p2)
{
    return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
}

void findShape(vector<lineType> &lines)
{
    // Base case
    if (lines.size() != 4)
    {
        cout << "There aren't 4 lines to determine the quadrilateral type." << endl;
        return;
    }

    // According to the rules for quadrilateral classification we want to determine a few properties for the lines.
    // Resource: https://www.varsitytutors.com/hotmath/hotmath_help/topics/quadrilaterals

    // First we want to see if opposite sides are parallel so we compare the first and second and the second and last lines respectively.
    bool isParallel1 = lines.at(0).parallelLines(lines.at(0), lines.at(1));
    bool isParallel2 = lines.at(2).parallelLines(lines.at(2), lines.at(3));

    // Next we want to determine if adjacent sides are perpendicular to determine if there is a right angle at that intersecting side.
    bool isPerpendicular1 = lines.at(0).perpendicularLines(lines.at(0), lines.at(3));
    bool isPerpendicular2 = lines.at(3).perpendicularLines(lines.at(3), lines.at(1));
    bool isPerpendicular3 = lines.at(1).perpendicularLines(lines.at(1), lines.at(2));
    bool isPerpendicular4 = lines.at(2).perpendicularLines(lines.at(2), lines.at(0));

    // Since we are given infinitely recurring lines we want to determine where the lines intersect
    pair<double, double> p1 = lines.at(0).intersectionPoint(lines.at(0), lines.at(3));
    pair<double, double> p2 = lines.at(3).intersectionPoint(lines.at(3), lines.at(1));
    pair<double, double> p3 = lines.at(1).intersectionPoint(lines.at(1), lines.at(2));
    pair<double, double> p4 = lines.at(2).intersectionPoint(lines.at(2), lines.at(0));

    // Calculating distance between the points to determine side lengths of the side for congruency tests.
    double d1 = distance(p1, p2);
    double d2 = distance(p2, p3);
    double d3 = distance(p3, p4);
    double d4 = distance(p4, p1);

    // Now we have all the information to determine the given shape.
    if (isParallel1 && isParallel2)
    {
        if (isPerpendicular1 && isPerpendicular2 && isPerpendicular3 && isPerpendicular4)
        {
            // Square if all sides are equal, with 2 parallel sides and 4 perpendicular angles; rectangle if not.
            if (abs(d1 - d2) < 1e-9 && abs(d2 - d3) < 1e-9 && abs(d3 - d4) < 1e-9)
            {
                cout << "The shape is a square." << endl;
            }
            else
            {
                cout << "The shape is a rectangle." << endl;
            }
        }
        else if (abs(d1 - d2) < 1e-9 && abs(d2 - d3) < 1e-9 && abs(d3 - d4) < 1e-9)
        {
            // Rhombus (all sides equal but not perpendicular)
            cout << "The shape is a rhombus." << endl;
        }
        else
        {
            // Parallelogram (opposite sides equal and parallel, but not all sides equal or perpendicular)
            cout << "The shape is a parallelogram." << endl;
        }
    }
    else if (isParallel1 || isParallel2)
    {
        // Trapezoid (only one pair of parallel sides)
        cout << "The shape is a trapezoid." << endl;
    }
    else
    {
        cout << "The shape is an irregular quadrilateral." << endl;
    }
}

int main()
{
    string filename = "data.txt";

    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    double a, b, c;
    vector<lineType> lines;
    int lineCounter = 0;

    while (inputFile >> a >> b >> c)
    {
        // Read the 4 lines and then call findShape function for each set of 4
        lineType line(a, b, c);
        lines.push_back(line);
        lineCounter++;

        // Process each set of 4 lines as a quadrilateral
        if (lineCounter == 4)
        {
            findShape(lines);
            lines.clear();
            lineCounter = 0;
        }
    }

    inputFile.close();
    return 0;
}