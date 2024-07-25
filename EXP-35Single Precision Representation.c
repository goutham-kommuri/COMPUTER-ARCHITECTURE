#include <stdio.h>

// Function to print binary representation of a number
void printBinary(int n, int bits) {
    int k;
    for (k = bits - 1; k >= 0; k--) {
        if ((n >> k) & 1)
            printf("1");
        else
            printf("0");
    }
}

// Union for IEEE 754 representation
typedef union {
    float f;
    struct {
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
    } raw;
} myfloat;

// Function to print the IEEE 754 representation
void printIEEE(myfloat var) {
    printf("%d | ", var.raw.sign);
    printBinary(var.raw.exponent, 8);
    printf(" | ");
    printBinary(var.raw.mantissa, 23);
    printf("\n");
}

int main() {
    myfloat var;
    var.f = 1259.125;

    printf("IEEE 754 representation of %f is : \n", var.f);
    printIEEE(var);

    return 0;
}

