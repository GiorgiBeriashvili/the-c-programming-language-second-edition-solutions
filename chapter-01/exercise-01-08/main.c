/* Write a program to count blanks, tabs and newlines. */

#include <stdio.h>

int main() {
    int input, blanks, tabs, newlines;

    blanks = tabs = newlines = 0;

    while ((input = getchar()) != EOF) {
        if (input == ' ') {
            blanks++;
        }

        if (input == '\t') {
            tabs++;
        }

        if (input == '\n') {
            newlines++;
        }
    }

    printf("Detected %d blanks, %d tabs, %d newlines.\n", blanks, tabs,
           newlines);
}
