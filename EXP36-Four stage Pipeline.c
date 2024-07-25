#include <stdio.h>

int main() {
    int counter = 0;
    int input;
    int num1, num2;
    int op;
    int res;
    int ins;
    int performance_measure = 0;

    printf("\nEnter 1st value: ");
    scanf("%d", &num1);
    counter += 1;

    printf("\nEnter 2nd value: ");
    scanf("%d", &num2);
    counter += 1;

    printf("\nEnter the option:\n1) Addition\n2) Subtraction\n3) Multiplication\n4) Division\n");
    scanf("%d", &op);

    switch (op) {
        case 1:
            printf("Performing addition operation\n");
            res = num1 + num2;
            counter += 1;
            break;

        case 2:
            printf("Performing subtraction operation\n");
            res = num1 - num2;
            counter += 1;
            break;

        case 3:
            printf("Performing multiplication operation\n");
            res = num1 * num2;
            counter += 1;
            break;

        case 4:
            if (num2 == 0) {
                printf("\nDenominator can't be zero\n");
            } else {
                printf("Performing division operation\n");
                res = num1 / num2;
                counter += 1;
            }
            break;

        default:
            printf("Invalid option...\n");
            counter += 3;
            break;
    }

    printf("\nCycle value is: %d\n", counter);

    printf("Enter the number of instructions: ");
    scanf("%d", &ins);

    if (counter > 0) {
        performance_measure = ins / counter;
    } else {
        printf("Cycle count is zero, cannot calculate performance measure.\n");
    }

    printf("Performance measure is: %d\n", performance_measure);

    return 0;
}

