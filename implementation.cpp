
#include"header.h"
#include <iostream>
using namespace std;

bool lineType::nonVertical(double b){
    if(b == 0){
        return false;
    }else{
        return true;
    }
}

double lineType::slope(double a, double b, double c){
    if(nonVertical(b)){
        return NULL;
    }
    
    if(a == 0){
        return 0;
    }else{
        double slope = -(a / b);
        return slope;
    }
}

bool lineType::lineEquality(lineType line1, lineType line2){
    if((line1.a == line2.a) && (line1.b == line2.b) && (line1.c == line2.c)){
        return true;
    }else{
        double k = line1.a / line2.a;
        if((line1.a == line2.a * k) && (line1.b == line2.b * k) && (line1.c == line2.c * k)){
            return true;
        }

        return false;
    }
}

bool lineType::parallelLines(lineType line1, lineType line2){
    if(slope(line1.a, line1.b, line1.c) == slope(line2.a, line2.b, line2.c) && (line1.c != line2.c)){
        return true;
    }else{
        return false;
    }
}

bool lineType::perpendicularLines(lineType line1, lineType line2){

}

bool lineType::intersectionPoint(lineType line1, lineType line2){

}