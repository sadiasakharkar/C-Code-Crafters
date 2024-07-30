#include<stdio.h>
int main()
{
    float per;

    printf("Enter percentage:");
    scanf("%f",&per);

    if(per>=60)
    {
        printf("First class");
    }
    else if(per>=40)
    {
        printf("Second class");
    }
    else if(per>=35)
    {
        printf("Third class");
    }
    else
    {
        printf("Student fail");
    }
    return 0;
}