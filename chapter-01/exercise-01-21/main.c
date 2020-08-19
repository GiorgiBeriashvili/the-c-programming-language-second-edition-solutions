/* Write a program entab that replaces strings of blanks by the minimum number
 * of tabs and blanks to achieve the same spacing. Use the same tab stops as for
 * detab. When either a tab or a single blank would suffice to reach a tab stop,
 * which should be given preference? */

#include <stdio.h>

#define TAB_SIZE 8

int get_remainder(int dividend, int divisor);

int main() {
    int input, offset, blanks, tabs;

    offset = 1, blanks = tabs = 0;

    while ((input = getchar()) != EOF) {
        if (input == ' ') {
            if (get_remainder(offset, TAB_SIZE) != 0) {
                blanks++;
            } else {
                blanks = 0;

                tabs++;
            }
        } else {
            while (tabs > 0) {
                putchar('\t');

                tabs--;
            }

            if (input == '\t') {
                blanks = 0;
            } else {
                while (blanks > 0) {
                    putchar(' ');

                    blanks--;
                }
            }

            putchar(input);

            if (input == '\n') {
                offset = 0;
            } else if (input == '\t') {
                offset =
                    offset + TAB_SIZE - get_remainder(offset - 1, TAB_SIZE) - 1;
            }
        }

        offset++;
    }

    return 0;
}

int get_remainder(int dividend, int divisor) {
    return (dividend - divisor * (dividend / divisor));
}
