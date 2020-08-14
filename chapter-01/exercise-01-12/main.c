/* Write a program that prints its input one word per line. */

#include <stdio.h>

int main() {
    int input, previous_input;

    previous_input = EOF;

    while ((input = getchar()) != EOF) {
        if (input == ' ' || input == '\t') {
            if (previous_input != ' ' && previous_input != '\t') {
                putchar('\n');
            }
        } else if (input != '\n') {
            putchar(input);
        }

        previous_input = input;
    }
}
