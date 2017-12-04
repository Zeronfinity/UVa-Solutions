#include <stdio.h>
#include <string.h>

int main()
{
    int temp, i = 0, j, k;
    long long temps, templ, len, div4, div100, div400, div3, div5, div11;
    char y[1000000];

    while (1)
    {
        if(scanf("%s", y) == EOF)
            break;

        len = strlen(y);

        temp = 0;
        templ = 0;
        temps = 0;

        div4 = 0, div100 = 0, div400 = 0, div3 = 0, div5 = 0, div11 = 0;

        if (i != 0)
            printf("\n");
        i = 1;

        if ( ( (y[len-2]-'0')*10 + (y[len-1]-'0') ) % 4 == 0 )
            div4 = 1;
        if ( (y[len-2]-'0') == 0 && (y[len-1]-'0') == 0 )
            div100 = 1;

        if (div100 == 1 && ( (y[len-4]-'0')*10 + (y[len-3]-'0') ) % 4 == 0 )
            div400 = 1;


        if (div4 == 1)
            if (div100 != 1 || div400 == 1)
            {
                printf("This is leap year.\n");
                templ = 1;
            }

        for (j = 0; j < len; j++)
            temps = temps + y[j] - '0';

        if (temps%3 == 0)
            div3 = 1;

        if ((y[len-1]-'0') == 0 || (y[len-1]-'0') == 5)
            div5 = 1;

        if (div5 == 1 && div3 == 1)
        {
            printf("This is huluculu festival year.\n");
            temp = 1;
        }

        temps = 0;
        for (j = 0; j < len; j++)
        {
            k = 1;
            if (j%2 != 0)
                k = -1;
            temps = temps + k*(y[j] - '0');
        }

        if (temps%11 == 0)
            div11 = 1;

        if (templ == 1)
            if (div5 == 1 && div11 == 1)
            {
                printf("This is bulukulu festival year.\n");
                temp = 1;
            }

        if (temp == 0 && templ == 0)
            printf("This is an ordinary year.\n");
    }
    return 0;
}
