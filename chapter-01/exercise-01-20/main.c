/* Write a program detab that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops, say
 * every n columns. Should n be a variable or a symbolic parameter? */

#include <stdio.h>

#define TAB_SIZE 8

int get_remainder(int dividend, int divisor);

int main() {
    int input, offset = 0;

    while ((input = getchar()) != EOF) {
        if (input == '\t') {
            int remainder = TAB_SIZE - get_remainder(offset, TAB_SIZE);

            for (int index = 0; index < remainder; index++) {
                putchar(' ');
            }

            offset = 0;
        } else if (input == '\n') {
            putchar(input);

            offset = 0;
        } else {
            putchar(input);

            offset++;
        }
    }

    return 0;
}

int get_remainder(int dividend, int divisor) {
    return (dividend - divisor * (dividend / divisor));
}
