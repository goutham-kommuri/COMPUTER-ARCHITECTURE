#include <stdio.h>
#include <math.h>

int OctalToDecimal(int n) {
    int p = 0, decimal = 0, r;
    while (n > 0) {
        r = n % 10;
        n = n / 10;
        decimal = decimal + r * pow(8, p);
        ++p;
    }
    return decimal;
}

int main() {
    int n;
    printf("Enter Octal: ");
    scanf("%d", &n);
    printf("\nDecimal of Octal Number %d is: %d\n", n, OctalToDecimal(n));
    return 0;
}

