/* Write a program to copy its input to its output, replacing each tab by \t,
 * each backspace by \b, and each backslash by \\. This makes tabs and
 * backspaces visible in an unambiguous way. */

#include <stdio.h>

/* character depiction states */
#define ALTERED 1
#define UNALTERED 0

int main() {
    int input, depiction;

    depiction = UNALTERED;

    while ((input = getchar()) != EOF) {
        if (input == '\t') {
            printf("\\t");

            depiction = ALTERED;
        }

        if (input == '\b') {
            printf("\\b");

            depiction = ALTERED;
        }

        if (input == '\\') {
            printf("\\\\");

            depiction = ALTERED;
        }

        if (depiction == UNALTERED) {
            putchar(input);
        }

        depiction = UNALTERED;
    }
}
