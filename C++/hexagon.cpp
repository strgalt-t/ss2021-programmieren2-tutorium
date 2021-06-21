#include "hexagon.h"

// ------------------------Point----------------------------------

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::getXValue() {
    return this->x;
}

int Point::getYValue() {
    return this->y;
}

void Point::printCoordinates() {
    cout << "(" << this->x << "/" << this->y << ")" << endl;
}

// ---------------------------Hexagon---------------------------- 

Hexagon::Hexagon(vector<Point> vec) {
    if (vec.size() != 6) {
        cerr << "Error: Initializing Vector must contain exactly 6 elements" << endl;
        exit(EXIT_FAILURE);
    }

    this->hexagonPoints = vec;

    cerr << "Info: Hexagon created successfully!" << endl;

}

void Hexagon::printHexagon() {
    for (Point p: this->hexagonPoints) {
        p.printCoordinates();
    }

    cout << "Area: " << this->area << endl;
    
}

float Hexagon::calculateArea() {
    vector<Point> tmpVec;

    int xSum = 0;
    int ySum = 0;

    for (Point p: this->hexagonPoints) {
        tmpVec.push_back(p);
    }

    tmpVec.push_back(this->hexagonPoints[0]);

    for (int i = 0; i < 6; i++) {
        xSum += tmpVec[i].getXValue() * tmpVec[i+1].getYValue();
    }

    for (int i = 0; i < 6; i++) {
        ySum = tmpVec[i].getYValue() * tmpVec[i+1].getXValue();
    }

    float zErg = xSum - ySum;
    if (zErg < 0) {
        zErg = zErg * -1;
    }

    float erg = zErg/2;

    this->area = erg;

    return erg;
}


// ----------------------------------------------------------------
int main() {
    vector<Point> vecPoints { Point(1,2), Point(3,4), Point(5,6), Point(7,8), Point(9,10), Point(11,12)};
    Hexagon hexagon(vecPoints);

    hexagon.calculateArea();

    hexagon.printHexagon();

}