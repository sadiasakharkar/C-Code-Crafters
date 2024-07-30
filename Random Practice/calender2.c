#include<stdio.h>

int main()
{
    int month,year,day,days_in_month,starting_day;

    printf("\n\nEnter month(1-12) and year (yyyy) seperated by space:");
    scanf("%d %d",&month,&year);

    switch(month)
    {
        case 2:
          if(year%4==0 &&(year%100!=0 || year%400==0))
          {
            days_in_month=29;
          }
          else
          {
            days_in_month =28;
          }
         break;
        case 4:
        case 6:
        case 9:
        case 11:
            days_in_month =30;
            break;
        default:
            days_in_month=31;
            break;
    }

    day=1;
    starting_day=(day+((13*(month+1))/5)+(year%100)+((year/100)/4)-2*(year/100))%7;
     
     printf("\n        %D/%d\n", month ,year);
     printf(" su  mo  tu  we  th  fr  sa\n");

     for(int i=1;i<=days_in_month;i++)
     {
        printf("%3d",i);
        if((i+starting_day)%7==0 || i== days_in_month)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
     }
     return 0;
}