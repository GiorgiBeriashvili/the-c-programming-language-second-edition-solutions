/* Rewrite the temperature conversion program of Section 1.2 to use a function
 * for conversion. */

#include <stdio.h>

#define VALID_CONVERSION 1
#define INVALID_CONVERSION 0
#define CELSIUS_TO_FAHRENHEIT '1'
#define FAHRENHEIT_TO_CELSIUS '2'
#define LOWER_VALUE 0
#define UPPER_VALUE 300
#define STEP 20

float celsius_to_fahrenheit(float value);
float fahrenheit_to_celsius(float value);
int prompt_decision();

int main() {
    int input, conversion;

    conversion = INVALID_CONVERSION;

    printf("1. Convert celsius to fahrenheit.\n");
    printf("2. Convert fahrenheit to celsius.\n");

    prompt_decision();

    while (conversion == INVALID_CONVERSION) {
        input = getchar();

        if (input == CELSIUS_TO_FAHRENHEIT) {
            printf("\nConverting celsius to fahrenheit:\n\n");

            for (int value = LOWER_VALUE; value <= UPPER_VALUE; value += STEP) {
                printf("%3d -> %.1f\n", value, celsius_to_fahrenheit(value));
            }

            conversion = VALID_CONVERSION;
        } else if (input == FAHRENHEIT_TO_CELSIUS) {
            printf("\nConverting fahrenheit to celsius:\n\n");

            for (int value = LOWER_VALUE; value <= UPPER_VALUE; value += STEP) {
                printf("%3d -> %.1f\n", value, fahrenheit_to_celsius(value));
            }

            conversion = VALID_CONVERSION;
        } else if (input == '\n') {
            prompt_decision();
        }
    }

    return 0;
}

float celsius_to_fahrenheit(float value) {
    return (value * (9.0 / 5.0)) + 32.0;
}

float fahrenheit_to_celsius(float value) {
    return (5.0 / 9.0) * (value - 32.0);
}

int prompt_decision() {
    printf("\nEnter your decision (1 or 2): ");

    return 0;
}
