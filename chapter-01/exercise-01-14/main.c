/* Write a program to print a histogram of the frequencies of different
 * characters in its input. */

#include <stdio.h>

#define START_CODE 33
#define END_CODE 126
#define MAXIMUM_LENGTH (END_CODE - START_CODE)

int main() {
    int input, character_frequencies[MAXIMUM_LENGTH];

    for (int index = 0; index < MAXIMUM_LENGTH; index++) {
        character_frequencies[index] = 0;
    }

    printf("Please enter characters (Ctrl + D to submit): ");

    while ((input = getchar()) != EOF) {
        if (input >= START_CODE && input <= END_CODE) {
            character_frequencies[input - START_CODE]++;
        }
    }

    int maximum_frequency = 0;

    for (int index = 0; index < MAXIMUM_LENGTH; index++) {
        if (maximum_frequency < character_frequencies[index]) {
            maximum_frequency = character_frequencies[index];
        }
    }

    printf("\n\nCharacter frequency histogram (vertical orientation):\n\n");

    for (int index = maximum_frequency; index != 0; index--) {
        printf("%3d |", index);

        for (int length = 0; length < MAXIMUM_LENGTH; length++) {
            if (index <= character_frequencies[length]) {
                putchar('*');
            } else {
                putchar(' ');
            }
        }

        printf("\n");
    }

    printf("     ");

    for (int index = START_CODE; index <= END_CODE; index++) {
        putchar('-');
    }

    printf("\n     ");

    for (int index = START_CODE; index <= END_CODE; index++) {
        putchar(index);
    }

    putchar('\n');
}
