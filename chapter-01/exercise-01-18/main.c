/* Write a program to remove traililing blanks and tabs from each line of input,
 * and to delete entirely blank lines. */

#include <stdio.h>

#define SIZE 1000 /* maximum input line size */

int get_line_size(char buffer[], int size);
int trim_line(char buffer[]);

int main() {
    int size;        /* current line size */
    char line[SIZE]; /* current input line */

    while ((size = get_line_size(line, SIZE)) > 0) {
        if (trim_line(line) > 0) {
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

/* trim_line: read a line into buffer, trim the line */
int trim_line(char buffer[]) {
    int index = 0;

    while ((buffer[index] != '\n') && (buffer[index] != '\0')) {
        index++;
    }

    index--;

    while ((buffer[index] == ' ') || (buffer[index] == '\t')) {
        index--;
    }

    if (index >= 0) {
        buffer[++index] = '\n';
        buffer[++index] = '\0';
    }

    return index;
}
