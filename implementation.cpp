#include "header.h"
#include <utility> 
#include <iostream>
using namespace std;

bool lineType::nonVertical(double b) {
    // Return true if b is not zero
    return b != 0; 
}

double lineType::slope(double a, double b, double c) {
    if (nonVertical(b)) {
        return -(a / b); // Calculate slope for non-vertical line
    } else {
        return NULL; 
    }
}

bool lineType::lineEquality(lineType line1, lineType line2) {
    // Check if lines are identical or one line is a multiple of the other
    if ((line1.a == line2.a) && (line1.b == line2.b) && (line1.c == line2.c)) {
        return true;
    } else {
        double k = line1.a / line2.a;
        return (line1.a == line2.a * k && line1.b == line2.b * k && line1.c == line2.c * k);
    }
}

bool lineType::parallelLines(lineType line1, lineType line2) {
    // Compares slopes to see if parallel
    return slope(line1.a, line1.b, line1.c) == slope(line2.a, line2.b, line2.c);
}

bool lineType::perpendicularLines(lineType line1, lineType line2) {
    // If one is vertical and the other horizontal, they are perpendicular
    if ((line1.b == 0 && line2.a == 0) || (line1.a == 0 && line2.b == 0)) {
        return true;
    }
    
    // Check if slopes multiply to -1 for perpendicularity
    double slope1 = slope(line1.a, line1.b, line1.c);
    double slope2 = slope(line2.a, line2.b, line2.c);
    return slope1 * slope2 == -1;
}

pair<double, double> lineType::intersectionPoint(lineType line1, lineType line2) {
    if (parallelLines(line1, line2)) {
        return make_pair(NULL, NULL); // No intersection for parallel lines
    } else {
        double a1 = line1.a;
        double b1 = line1.b;
        double c1 = line1.c;
        double a2 = line2.a;
        double b2 = line2.b;
        double c2 = line2.c;

        // Determinant for Cramer's Rule
        double determinant = a1 * b2 - a2 * b1;

        // Cramer's rule to find intersection point
        double x = (c1 * b2 - c2 * b1) / determinant;
        double y = (a1 * c2 - a2 * c1) / determinant;

        return make_pair(x, y);
    }
}
