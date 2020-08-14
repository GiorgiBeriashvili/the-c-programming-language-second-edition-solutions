/* Write a program to copy its input to its output, replacing each string of one
 * or more blanks by a single blank. */

#include <stdio.h>

int main() {
    int input, previous_input;

    previous_input = EOF;

    while ((input = getchar()) != EOF) {
        if (input == ' ') {
            if (previous_input != ' ') {
                putchar(input);
            }
        }

        if (input != ' ') {
            putchar(input);
        }

        previous_input = input;
    }
}
