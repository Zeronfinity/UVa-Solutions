#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *year,print=0;

    year = (int*)malloc(2*10000000000000000000000000000000);

    while(scanf("%d", year)!=EOF)
    {
        if(print!=0)
            printf("\n");
        print=1;
        if(*year%4==0)
        {
            if(*year%400==0 || *year%100!=0)
            {
                if(*year%55==0 && *year%15==0)
                {
                    printf("This is leap year.\nThis is huluculu festival year.\nThis is bulukulu festival year.\n");
                }
                else if(*year%55==0)
                {
                    printf("This is leap year.\nThis is bulukulu festival year.\n");
                }
                else if(*year%15==0)
                {
                printf("This is leap year.\nThis is huluculu festival year.\n");
                }
                else
                    printf("This is leap year.\n");
            }
            else
            {
                printf("This is an ordinary year.\n");
            }
        }
        else if(*year%15==0)
                {
                    printf("This is huluculu festival year.\n");
                }

        else if(*year%15==0)
                {
                printf("This is huluculu festival year.\n");
                }
        else{
            printf("This is an ordinary year.\n");
        }
    }
    return 0;
}
