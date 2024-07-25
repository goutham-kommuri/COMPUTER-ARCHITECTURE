#include <stdlib.h>
#include <stdio.h>

int acum[100] = {0};

void add(int acum[], int b[], int n);

int q[100], b[100];

int main() {
    int x, y;

    printf("Enter the Numbers: ");
    scanf("%d%d", &x, &y);

    int i = 0;
    while (x > 0 || y > 0) {
        if (x > 0) {
            q[i] = x % 2;
            x = x / 2;
        } else {
            q[i] = 0;
        }

        if (y > 0) {
            b[i] = y % 2;
            y = y / 2;
        } else {
            b[i] = 0;
        }
        i++;
    }

    int n = i;
    int bc[50] = {0}; // Initialize bc array to zero

    for (i = 0; i < n; i++) {
        bc[i] = b[i] == 0 ? 1 : 0;
    }

    bc[n] = 1; // Adding 1 to the end of bc for two's complement

    for (i = 0; i <= n; i++) {
        if (bc[i] == 0) {
            bc[i] = 1;
            break;
        } else {
            bc[i] = 0;
        }
    }

    for (i = 0; i <= n; i++) {
        b[i] = b[i] == 0 ? 0 : 1; // Adjust b array for correct length
    }

    for (i = n; i > 0; i--) {
        for (int j = n; j > 0; j--) {
            acum[j] = acum[j - 1];
        }

        acum[0] = q[n - 1];
        for (int j = n - 1; j > 0; j--) {
            q[j] = q[j - 1];
        }

        add(acum, bc, n + 1);
        if (acum[n] == 1) {
            q[0] = 0;
            add(acum, b, n + 1);
        } else {
            q[0] = 1;
        }
    }

    printf("\nQuotient: ");
    for (int l = n - 1; l >= 0; l--) {
        printf("%d", q[l]);
    }

    printf("\nRemainder: ");
    for (int l = n; l >= 0; l--) {
        printf("%d", acum[l]);
    }

    return 0;
}

void add(int acum[], int bo[], int n) {
    int temp = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum = acum[i] + bo[i] + temp;
        if (sum == 0) {
            acum[i] = 0;
            temp = 0;
        } else if (sum == 2) {
            acum[i] = 0;
            temp = 1;
        } else if (sum == 1) {
            acum[i] = 1;
            temp = 0;
        } else if (sum == 3) {
            acum[i] = 1;
            temp = 1;
        }
    }
}

