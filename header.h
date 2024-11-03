#ifndef HEADER_H
#define HEADER_H

#include <utility>
#include <iostream>
using namespace std;

class lineType {
    private:
        double a;
        double b;
        double c;
    public:
        // Constructor with default values
        lineType(double a = 1.0, double b = 1.0, double c = 0.0) : a(a), b(b), c(c) {}

        // Member functions to access private members
        double getA() const { return a; }
        double getB() const { return b; }
        double getC() const { return c; }

        // Function prototypes
        bool nonVertical(double b);
        double slope(double a, double b, double c);
        bool lineEquality(lineType line1, lineType line2);
        bool parallelLines(lineType line1, lineType line2);
        bool perpendicularLines(lineType line1, lineType line2);
        std::pair<double, double> intersectionPoint(lineType line1, lineType line2);
};

#endif
