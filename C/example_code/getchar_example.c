#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter a char:\n");
    
    char c = getchar();
    
    printf("You've entered: %c \n", c);

    return EXIT_SUCCESS;
}