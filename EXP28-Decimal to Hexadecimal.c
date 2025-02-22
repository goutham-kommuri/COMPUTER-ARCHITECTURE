#include <stdio.h>

int main() {
    long int decimalNumber, remainder, quotient;
    int i = 1, j, temp;
    char hexadecimalNumber[100];

    printf("Enter any decimal number: ");
    scanf("%ld", &decimalNumber);

    quotient = decimalNumber;

    while (quotient != 0) {
        temp = quotient % 16;

        // To convert integer into character
        if (temp < 10)
            temp = temp + 48; // ASCII value of 0 is 48
        else
            temp = temp + 55; // ASCII value of A is 65, so 55 + 10 = 65

        hexadecimalNumber[i++] = temp;
        quotient = quotient / 16;
    }

    printf("Equivalent hexadecimal value of decimal number %ld: ", decimalNumber);
    for (j = i - 1; j > 0; j--)
        printf("%c", hexadecimalNumber[j]);

    return 0;
}

