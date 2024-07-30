#include<stdio.h>
int main()
{
    int a,b,c,o;
    printf("\nEnter two values:");
    scanf("%d %d",&a,&b);
    o=a,b;
    switch (o)
    {
    case '+':
    c=a+b;
    printf("\nThe value of number is %d",c);
        break;
    case '-':
    c=a-b;
    printf("\nThe value of number is %d",c);
    break;
    case '*':
    c=a*b;
    printf("\nThe value of number is %d",c);
    break;
    case '/':
    c=a/b;
    printf("\nThe value of number is %d",c);
    break;
    default:
    printf("\noperator invalid");
        break;
    }
    return 0;
}