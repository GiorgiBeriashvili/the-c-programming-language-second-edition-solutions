/* Write a program to print all input lines that are longer than 80 characters.
 */

#include <stdio.h>

#define SIZE 1000    /* maximum input line size */
#define THRESHOLD 80 /* minimum length threshold */

int get_line(char line[], int maxline);

int main() {
    int length;      /* current line length */
    char line[SIZE]; /* current input line */

    while ((length = get_line(line, SIZE)) > 0) {
        if (length > THRESHOLD) {
            printf("%s", line);
        }
    }

    return 0;
}

/* get_line: read a line into buffer, return length */
int get_line(char buffer[], int size) {
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
