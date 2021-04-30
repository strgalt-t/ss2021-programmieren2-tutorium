#include <stdio.h>
#include <stdlib.h>
#include "variable_extern.h"

extern const int semesters;

const int many_semesters = 11;

int example_extern() {
    printf("I've been enrolled for %d semesters!\n", semesters);

    return EXIT_SUCCESS;
}

int example_local() {
    int few_semesters = 4;

    printf("Hah, I've been enrolled for %i semesters.\n", few_semesters);

    return EXIT_SUCCESS;
}

int example_global() {
    printf("That's nothing, I've been enrolled for %i semesters.\n", many_semesters);

    return EXIT_SUCCESS;
}

int example_static_local() {
    static int mhh_semesters = 6;
    printf("Not sure, I think I've been enrolled for %i semesters.\n", mhh_semesters);
    mhh_semesters++;

    return EXIT_SUCCESS;
}

int main() {

    example_extern();

    example_local();

    example_global();

    example_static_local();

    example_static_local();

    return EXIT_SUCCESS;
}