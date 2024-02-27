#include <stdio.h>
int main() 
{
    char operation;
    float num1, num2, result;

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

    printf("Enter operation (+ for addition, - for subtraction, * for multiplication, / for division): ");
    scanf(" %c", &operation);

    switch (operation) 
    {
        case '+':
            result = num1 + num2;
            printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error! Division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
                printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
            }
            break;
        default:
            printf("Invalid operation!\n");
    }

    return 0;
}
