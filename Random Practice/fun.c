#include <stdio.h>

// Function prototype
int add(int a, int b);

// Main function
int main() {
    int num1, num2, sum;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Call the add function
    sum = add(num1, num2);

    printf("The sum of %d and %d is %d.\n", num1, num2, sum);

    return 0;
}

// Function definition
int add(int a, int b) {
    int result = a + b;
    return result;
}
