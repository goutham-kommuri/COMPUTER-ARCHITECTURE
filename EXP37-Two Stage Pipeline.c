#include <stdio.h>

int main() {
    int counter = 1, a, b, choice, res, ins;
    int performance_measure;

    printf("Enter number 1: ");
    scanf("%d", &a);
    counter += 1;

    printf("Enter number 2: ");
    scanf("%d", &b);
    counter += 1;

    printf("1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Performing addition\n");
            res = a + b;
            counter += 1;
            break;

        case 2:
            printf("Performing subtraction\n");
            res = a - b;
            counter += 1;
            break;

        case 3:
            printf("Performing multiplication\n");
            res = a * b;
            counter += 1;
            break;

        case 4:
            if (b == 0) {
                printf("Error: Division by zero is not allowed.\n");
                counter += 1; // Increment counter for error handling
            } else {
                printf("Performing division\n");
                res = a / b;
                counter += 1;
            }
            break;

        default:
            printf("Wrong input\n");
            counter += 3; // Increment counter for invalid input
            break;
    }

    printf("The cycle value is: %d\n", counter);

    printf("Enter the number of instructions: ");
    scanf("%d", &ins);

    if (counter > 0) {
        performance_measure = ins / counter;
        printf("The performance measure is: %d\n", performance_measure);
    } else {
        printf("Cycle count is zero, cannot calculate performance measure.\n");
    }

    return 0;
}

