#include <stdlib.h>
#include <stdio.h>

int main() {

    int number;
    printf("Please enter a number:\n");
    scanf("%d", &number);

    switch(number) {
        case 1: 
            printf("number equals one\n");
            // IMPORTANT: insert a break statement, else it 
            // will "fall through"
            break;
        case 2:
            printf("number equals two\n");
            break;
        default:
            printf("number equals %i\n", number);    
    }

    return EXIT_SUCCESS;
}

/*
As you can see, the code above is easier to read.
Once you have to check for 5 or more cases, if else if else 
constructs become ugly and hard to keep track of.

int main() {
    int number;
    printf("Please enter a number:\n");
    scanf("%d", &number);

    if (number == 1) {
        printf("number equals one\n");
    } else if (number == 2) {
        printf("number equals two\n");
    } else {
        printf("number equals %i\n", number);
    }

    return EXIT_SUCCESS;
}
*/