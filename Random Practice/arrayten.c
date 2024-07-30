#include <stdio.h>

int main() {
    int arr[10];
    int even_count = 0, odd_count = 0;

    printf("Enter 10 numbers: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 10; i++) {
        if (arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    printf("Number of even numbers: %d\n", even_count);
    printf("Number of odd numbers: %d\n", odd_count);

    return 0;
}
