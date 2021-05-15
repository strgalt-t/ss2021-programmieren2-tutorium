#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 12
/*
Using const for initialization  only works in clang, not with GCC.
const int ARRAY_SIZE = 12;
*/
// struct Point for X and Y coordinates.
typedef struct Point {
    int x;
    int y;
} Point;

// constructor-method for Point struct
Point constructorPoint(int x, int y) {
    Point point = {
        .x = x,
        .y = y,
    };

    return point;
}

// passes pointer to Point, print out the X and Y coordinates
int printCoordinates(Point * point) {
    printf("(%i/%i)\n", point->x, point->y);

    return EXIT_SUCCESS;
}
// ---------------------------------------------------------------------
// Hexagon is defined as an array with 6 Points
typedef struct Hexagon {
    Point hexagonPoints [6];
} Hexagon;

// constructor for Hexagon
Hexagon constructorHexagon(int array []) {
    Hexagon hexagon;
    int j = 0;

    for(int i = 0; i < ARRAY_SIZE; i += 2) {
        Point point = constructorPoint(array[i], array[i + 1]);
        hexagon.hexagonPoints[j] = point;
        j++;
    }

    return hexagon;

}
// print coordinates of all hexagon points
int printHexagon(Hexagon hexagon) {
    for(int i = 0; i < sizeof(hexagon.hexagonPoints)/sizeof(Point) ; i++) {
        printCoordinates(&hexagon.hexagonPoints[i]);
    }

    return EXIT_SUCCESS;
}
// ----------------------------------------------------------------------


int main() {
   /*
    continuing here next week!
   */

    return EXIT_SUCCESS;
}