#include<stdio.h>
int main()
{
    int a;
    printf("\nEnter single digit number:");
    scanf("%d",&a);
    switch(a)
    {
        case 0:printf("Zero");
        break;
        case 1:printf("One");
        break;
        case 2:printf("Two");
        break;
        case 3:printf("Three");
        break;
        case 4:printf("Four");
        break;
        case 5:printf("Five");
        break;
        case 6:printf("six");
        break;
        case 7:printf("Seven");
        break;
        case 8:printf("Eight");
        break;
        case 9:printf("Nine");
        break;
        deafult:
        printf("\nThe number is not a single digit number");
    }
    return 0;
}