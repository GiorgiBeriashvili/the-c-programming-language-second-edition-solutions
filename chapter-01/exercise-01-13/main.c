/* Write a program to print a histogram of the lengths of words in its input. It
 * is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging. */

#include <stdio.h>

#define MAXIMUM_LENGTH 10

/* write a program to print a histogram of the lengths of words in its input */
int main() {
    int input, state, word_length, word_frequencies[MAXIMUM_LENGTH];

    word_length = 0;

    for (int index = 0; index < MAXIMUM_LENGTH; index++) {
        word_frequencies[index] = 0;
    }

    printf("Input a sentence (Ctrl + D to submit): ");

    while ((input = getchar()) != EOF) {
        if (input == ' ' || input == '\n' || input == '\b') {
            if (word_length > 0 && word_length <= MAXIMUM_LENGTH) {
                word_frequencies[word_length - 1]++;
            } else if (word_length > 0) {
                word_frequencies[MAXIMUM_LENGTH - 1]++;
            }

            word_length = 0;
        } else {
            word_length++;
        }
    }

    int maximum_frequency = 0;

    for (int index = 0; index < MAXIMUM_LENGTH; index++) {
        if (maximum_frequency < word_frequencies[index]) {
            maximum_frequency = word_frequencies[index];
        }
    }

    printf("\n\nHistogram (horizontal orientation):\n\n");

    for (int index = 0; index < MAXIMUM_LENGTH; index++) {
        if (index < MAXIMUM_LENGTH - 1) {
            printf("%d: ", index + 1);
        } else {
            printf("+: ");
        }

        for (int count = 0; count < word_frequencies[index]; count++) {
            printf("*");
        }

        printf("\n");
    }

    printf("\n\nHistogram (vertical orientation):\n\n");

    for (int index = maximum_frequency; index != 0; index--) {
        printf("%2d |", index);

        for (int length = 0; length < MAXIMUM_LENGTH; length++) {
            if (index <= word_frequencies[length]) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }

        printf("\n");
    }

    printf("    -----------------------------\n");
    printf("     1  2  3  4  5  6  7  8  9  +\n");
}
