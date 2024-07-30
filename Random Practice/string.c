#include <stdio.h>
#include <string.h>

int main() {
   char str1[100], str2[100];
   int result;

   printf("Enter the first string: ");
   scanf("%s", str1);

   printf("Enter the second string: ");
   scanf("%s", str2);

   result = strcmp(str1, str2);

   if (result == 0) {
      printf("The strings are equal.\n");
   } 
   else if(result>0){
    printf("\nFirst string comes after second");
   }
   else{
    printf("\nFirst string comes first");
   }

   return 0;
}
