/* Write a function reverse(s) that reverses the character string s. Use it to
 * write a program that reverses its input a line at a time. */

#include <stdio.h>

#define SIZE 1000 /* maximum input line size */

int get_line_size(char buffer[], int size);
void reverse(char buffer[]);

int main() {
    int size;        /* current line size */
    char line[SIZE]; /* current input line */

    while ((size = get_line_size(line, SIZE)) > 0) {
        reverse(line);

        printf("%s", line);
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

/* reverse: read a line into buffer, reverse its content */
void reverse(char buffer[]) {
    int index = 0, size;

    while ((buffer[index] != '\n') && (buffer[index] != '\0')) {
        index++;
    }

    index--;

    if (index > 0) {
        size = index;

        while (index > (size / 2)) {
            int origin = buffer[size - index];

            buffer[size - index] = buffer[index];

            buffer[index] = origin;

            index--;
        }
    }

    if (buffer[++size] == '\0') {
        buffer[size] = '\n';
        buffer[++size] = '\0';
    }
}
