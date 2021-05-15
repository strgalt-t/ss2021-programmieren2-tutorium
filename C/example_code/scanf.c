#include <stdio.h>
#include <stdlib.h>

int main() {
    int age;
    
    printf("How old are you? \n");

    scanf("%i", &age);

    printf("You're %i years old \n", age);

    return EXIT_SUCCESS;

}