#include <stdio.h>
#include <stdlib.h>

int add(int num_1, int num_2) {
    int result;

    result = num_1 + num_2;

    return result;
}

int main() {
    int result;
    
    result = add(7,6);

    printf("Result = %d\n", result);

    return EXIT_SUCCESS;
}