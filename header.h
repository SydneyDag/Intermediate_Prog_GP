#include <utility>
using namespace std;

class lineType {
    private:
        double a;
        double b;
        double c;
    public:
        // Constructor
        lineType(double a, double b, double c) : a(a), b(b), c(c) {}

        lineType(double a = 1.0, double b = 1.0, double c = 0.0){}

        // Member functions
        double getA() const { return a; }
        double getB() const { return b; }
        double getC() const { return c; }

        bool nonVertical(double b);
        double slope(double a, double b, double c);
        bool lineEquality(lineType line1, lineType line2);
        bool parallelLines(lineType line1, lineType line2);
        bool perpendicularLines(lineType line1, lineType line2);
        pair<double, double> intersectionPoint(lineType line1, lineType line2);
};
