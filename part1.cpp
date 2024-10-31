#include "implementation.cpp"
#include <iostream>
#include <utility>
using namespace std;

int main() {
    lineType line1(2.0, 3.0, 6.0); 
    lineType line2(4, 6, 12); 
    lineType line3(3, -2, 5); 
    lineType line4(2, 3, 8); 
    lineType line5(3, 2, 4);

    //Test for a
    cout << "1a: Non-vertical and Slope" << endl;
    if (line1.nonVertical(line1.getB())) {
        cout << "Slope of line1: " << line1.slope(line1.getA(), line1.getB(), line1.getC()) << endl;
    } else {
        cout << "Line1 is vertical, slope is undefined." << endl;
    }

    if (line3.nonVertical(line3.getB())) {
        cout << "Slope of line3: " << line3.slope(line3.getA(), line3.getB(), line3.getC()) << endl;
    } else {
        cout << "Line3 is vertical, slope is undefined." << endl;
    }

    cout << endl;

    //Test for b
    cout << "1b: Line Equality" << endl;
    cout << "Are line1 and line2 equal? " << (line1.lineEquality(line1, line2) ? "Yes" : "No") << endl;
    cout << "Are line1 and line4 equal? " << (line1.lineEquality(line1, line4) ? "Yes" : "No") << endl;
    cout << endl;

    //Test for c
    cout << "1c: Parallel Lines" << endl;
    cout << "Are line1 and line2 parallel? " << (line1.parallelLines(line1, line2) ? "Yes" : "No") << endl;
    cout << "Are line1 and line4 parallel? " << (line1.parallelLines(line1, line4) ? "Yes" : "No") << endl;
    cout << "Are line1 and line3 parallel? " << (line1.parallelLines(line1, line3) ? "Yes" : "No") << endl;
    cout << endl;

    //Test for d
    cout << "1d: Perpendicular Lines" << endl;
    cout << "Are line3 and line5 perpendicular? " << (line1.perpendicularLines(line3, line5) ? "Yes" : "No") << endl;
    cout << "Are line1 and line2 perpendicular? " << (line1.perpendicularLines(line1, line2) ? "Yes" : "No") << endl;
    cout << endl;

    //Test for e
    cout << "1e: Intersection Point" << endl;
    pair<double, double> intersection = line1.intersectionPoint(line1, line3);
    if (intersection.first != NULL && intersection.second != NULL) {
        cout << "Intersection of line1 and line3: (" << intersection.first << ", " << intersection.second << ")" << endl;
    } else {
        cout << "Line1 and Line3 do not intersect." << endl;
    }

    intersection = line1.intersectionPoint(line1, line2);
    if (intersection.first != NULL && intersection.second != NULL) {
        cout << "Intersection of line1 and line2: (" << intersection.first << ", " << intersection.second << ")" << endl;
    } else {
        cout << "Line1 and Line2 do not intersect (they are parallel)." << endl;
    }

    return 0;
}