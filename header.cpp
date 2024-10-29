class lineType {
    private:
        double a;
        double b;
        double c;
    public:
        bool nonVertical(double a, double b, double c);
        double slope(double a, double b, double c);
        bool lineEquality(lineType line1, lineType line2);
        bool parallelLines(lineType line1, lineType line2);
        bool perpendicularLines(lineType line1, lineType line2);
        bool intersectionPoint(lineType line1, lineType line2);
};