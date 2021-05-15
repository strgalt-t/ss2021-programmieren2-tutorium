#include <stdio.h>
#include <stdlib.h>

int main() {
    int array [] = {0x41, 0x6c, 0x62, 0x73, 0x74, 0x61, 0x64, 0x74};

    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
        printf("Hex-Value: %x\n", array[i]);
    } 

    return EXIT_SUCCESS;
}