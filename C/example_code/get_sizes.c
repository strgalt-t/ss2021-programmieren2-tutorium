#include <stdio.h>
#include <stdlib.h>

int main() {
    int size_of_int = sizeof(int);
    int size_of_double = sizeof(double);
    int size_of_float = sizeof(float);

    printf("Different types have different sizes!\n");
    printf("An int has %i bytes.\n", size_of_int);
    printf("A double has %i bytes.\n", size_of_double);
    printf("A float has %i bytes.\n", size_of_float);

    return EXIT_SUCCESS;
}