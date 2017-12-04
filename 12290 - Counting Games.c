#include <stdio.h>
int main ()
{
    long long r, n, m, k, i, p, x, c, flag;

    while (1)
    {
        x = 1;
        c = 0;
        scanf("%lld %lld %lld", &n, &m, &k);

        if (n==0 && m==0 && k==0)
            break;

        for (i=1, p=1; p != - 5 ; i++)
        {
            flag = 0;

            if (m == p)
            {
                r = i;
                while (r!=0)
                {
                    if (r%10 == 7)
                    {
                        flag = 1;
                        break;
                    }
                    r = r/10;
                }
                if (flag == 1 || i%7==0)
                    c++;
                if (k == c)
                    break;
            }

            if (p == n || (p == 1 && i != 1))
                x *= -1;
            p += x;
        }

        printf("%lld\n", i);
    }
    return 0;
}


