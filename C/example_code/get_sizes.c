#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Different types have different sizes!\n");
    printf("An int allocates %i bytes.\n", sizeof(int));
    printf("A double allocates %i bytes.\n", sizeof(double));
    printf("A float allocates %i bytes.\n", sizeof(float));

    return EXIT_SUCCESS;
}