#include "header.h"
#include <cmath>
#include <utility>
#include <iostream>
using namespace std;

bool lineType::nonVertical(double b) {
    return (b != 0);
}

double lineType::slope(double a, double b, double c) {
    if (nonVertical(b)) {
        return -(a / b);
    } else {
        return 0;             
    }
}

bool lineType::lineEquality(lineType line1, lineType line2) {
    if ((line1.a == line2.a) && (line1.b == line2.b) && (line1.c == line2.c)) {
        return true;
    } else {
        double k = line1.a / line2.a;
        return (line1.a == line2.a * k && line1.b == line2.b * k && line1.c == line2.c * k);
    }
}

bool lineType::parallelLines(lineType line1, lineType line2) {
    // Both lines are vertical
    if (!nonVertical(line1.b) && !nonVertical(line2.b)) {
        return true;
    }
    // Both lines are horizontal
    if (line1.a == 0 && line2.a == 0) {
        return true;
    }
    // Otherwise, compare slopes for non-vertical, non-horizontal lines
    if (nonVertical(line1.b) && nonVertical(line2.b)) {
        return abs(slope(line1.a, line1.b, line1.c) - slope(line2.a, line2.b, line2.c)) < 1e-9;
    }
    return false;
}

bool lineType::perpendicularLines(lineType line1, lineType line2) {
    // Check if one line is vertical and the other is horizontal
    if ((!nonVertical(line1.b) && line2.a == 0) || (line1.a == 0 && !nonVertical(line2.b))) {
        return true;
    }

    // Otherwise, check if the product of their slopes is -1
    double slope1 = slope(line1.a, line1.b, line1.c);
    double slope2 = slope(line2.a, line2.b, line2.c);
    return abs(slope1 * slope2 + 1) < 1e-9;
}

pair<double, double> lineType::intersectionPoint(lineType line1, lineType line2) {
    double a1 = line1.a;
    double b1 = line1.b;
    double c1 = line1.c;
    double a2 = line2.a;
    double b2 = line2.b;
    double c2 = line2.c;

    double determinant = a1 * b2 - a2 * b1;

    if (abs(determinant) < 1e-9) {
        // Lines are parallel or coincident, no unique intersection
        return make_pair(NAN, NAN);
    }

    // Calculate intersection using Cramer's rule
    double x = (b1 * c2 - b2 * c1) / determinant;
    double y = (a2 * c1 - a1 * c2) / determinant;
    return make_pair(x, y);
}