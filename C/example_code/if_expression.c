#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 2;
    int x = 5;

    if (i == 2) {
        printf("i equals two\n");
    } else {
        printf("i doesn't equal two\n");
    }

    if (i != 2) {
        printf("i doesn't equal two\n");
    }

    if (i == 2 && x == 5) {
        printf("i equals two and x equals five\n");
    }

    if (i == 2 || x == 3) {
        printf("i equals two or x equals three\n");
    }

    return EXIT_SUCCESS;
}