#include <stdio.h>
#include <stdlib.h>

#define VAT_OLD 19.0

const float VAT_NEW = 17.0;

int main() {
    printf("The old tax has been %.2f percent, because of COVID it has been temporarly reduced to %.2f percent.\n", VAT_OLD, VAT_NEW);

    return EXIT_SUCCESS;
}