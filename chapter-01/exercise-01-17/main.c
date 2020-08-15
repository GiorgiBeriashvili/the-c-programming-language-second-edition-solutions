/* Write a program to print all input lines that are longer than 80 characters.
 */

#include <stdio.h>

#define SIZE 1000    /* maximum input line size */
#define THRESHOLD 80 /* minimum size threshold */

int get_line_size(char buffer[], int size);

int main() {
    int size;        /* current line size */
    char line[SIZE]; /* current input line */

    while ((size = get_line_size(line, SIZE)) > 0) {
        if (size > THRESHOLD) {
            printf("%s", line);
        }
    }

    return 0;
}

/* get_line_size: read a line into buffer, return size */
int get_line_size(char buffer[], int size) {
    int input, index;

    for (index = 0;
         index < size - 1 && (input = getchar()) != EOF && input != '\n';
         index++) {
        buffer[index] = input;
    }

    if (input == '\n') {
        buffer[index++] = input;
    }

    buffer[index] = '\0';

    return index;
}
