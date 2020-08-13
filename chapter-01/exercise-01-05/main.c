/* Modify the temperature conversion program to print the table in reverse
 * order, from 300 degrees to 0. */

#include <stdio.h>

/* print Fahrenheit-Celsius table */
int main() {
    int fahr;

    printf("Fahrenheit-Celsius table\n");

    for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}
