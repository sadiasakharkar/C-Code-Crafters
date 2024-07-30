#include <stdio.h>

int main() {
   int num1[10], num2[10], sum[10];
   int i, carry = 0;

   printf("Enter first number: ");
   for (i = 0; i < 10; i++) {
      scanf("%1d", &num1[i]);
   }

   printf("Enter second number: ");
   for (i = 0; i < 10; i++) {
      scanf("%1d", &num2[i]);
   }

   for (i = 9; i >= 0; i--) {
      sum[i] = num1[i] + num2[i] + carry;
      if (sum[i] >= 10) {
         carry = 1;
         sum[i] -= 10;
      } else {
         carry = 0;
      }
   }

   printf("Sum of the two numbers: ");
   if (carry == 1) {
      printf("1");
   }
   for (i = 0; i < 10; i++) {
      printf("%d", sum[i]);
   }

   return 0;
}
