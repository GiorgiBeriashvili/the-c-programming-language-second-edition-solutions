/* Write a program to print the corresponding Celsius to Fahrenheit table. */

#include <stdio.h>

int main() {
    float fahrenheit, celsius;
    int lower, upper, step;

    lower = 0;   /* lower limit of temperature table */
    upper = 300; /* upper limit */
    step = 20;   /* step size */

    celsius = lower;

    printf("Celsius-Fahrenheit table\n");

    while (celsius <= upper) {
        fahrenheit = (9.0 / 5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahrenheit);
        celsius = celsius + step;
    }
}
