/* Verify that the expression getchar() != EOF is 0 or 1. */

#include <stdio.h>

int main() {
    int input;

    input = getchar();

    /* != operator either returns 1 (true) or 0 (false) depending on whether or
     * not the operants are non-equal
     * in order to return 0, we can press Ctrl + D to send a signal to the
     * terminal to close the input stream
     * whereas, if we input a letter for example, the expression will return 1
     * due to non-equality check being satisfied */
    printf("EOF is %d.\n", input != EOF);
}
