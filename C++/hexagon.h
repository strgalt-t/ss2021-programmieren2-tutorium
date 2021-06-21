#ifndef HEXAGON_H
#define HEXAGON_H

#include <iostream>
#include <vector>

using namespace std;

class Point {
    int x;
    int y;

    public:
        Point(int x, int y);
        void printCoordinates();
        int getXValue();
        int getYValue();
};

class Hexagon {
    vector<Point> hexagonPoints;
    float area;
    public:
        Hexagon(vector<Point> vec);
        void printHexagon();
        float calculateArea();
};

#endif