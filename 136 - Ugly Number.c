#include <stdio.h>
int main ()
{
    long long n[6000], a, b, c, j, i, temp, l, flag = 0;

    n[0] = 1;
    n[1] = 2;
    n[2] = 3;
    n[3] = 4;
    n[4] = 5;
    n[5] = 6;

    a = 3;
    b = 2;
    c = 1;

    for (l = 5; l < 5000; a++, b++, c++)
    {

        temp = n[a]*2;

        for (i=l; i>=0 && temp <= n[i] ; i--)
        {
            if (temp == n[i])
            {
                flag = 1;
                for (i++; i<=l; i++)
                    n[i] = n[i+1];
                break;
            }
            else n[i+1] = n[i];
        }

        if (flag == 0)
        {
            n[i+1] = temp;
            l++;
        }
        else flag = 0;

        temp =  n[b]*3;

        for (i=l; i>=0 && temp <= n[i] ; i--)
        {
            if (temp == n[i])
            {
                flag = 1;
                for (i++; i<=l; i++)
                    n[i] = n[i+1];
                break;
            }
            else n[i+1] = n[i];
        }
        if (flag == 0)
        {
            n[i+1] = temp;
            l++;
        }
        else flag = 0;

        temp = n[c]*5;

        for (i=l; i>=0 && temp <= n[i] ; i--)
        {
            if (temp == n[i])
            {
                flag = 1;
                for (i++; i<=l; i++)
                    n[i] = n[i+1];
                break;
            }
            else n[i+1] = n[i];
        }
        if (flag == 0)
        {
            n[i+1] = temp;
            l++;
        }
        else flag = 0;

    }
        printf("The 1500'th ugly number is %lld.\n", n[1499]);
    return 0;
}
