#include <stdio.h>

int main() {
    float cr, cpi, ct, max;
    int p, i;
    float cpu[5] = {0};

    printf("\nEnter the number of processors: ");
    scanf("%d", &p);

    for (i = 0; i < p; i++) {
        printf("\nEnter the Cycles per Instruction of processor %d: ", i + 1);
        scanf("%f", &cpi);

        printf("Enter the clockrate in GHz: ");
        scanf("%f", &cr);

        ct = 1000 * cpi / cr;
        printf("The CPU time is: %f\n", ct);

        cpu[i] = ct;
    }

    max = cpu[0];

    for (i = 1; i < p; i++) {
        if (cpu[i] < max) {
            max = cpu[i];
        }
    }

    printf("\nThe processor with the lowest execution time has a time of: %f\n", max);

    return 0;
}

