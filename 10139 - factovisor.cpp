#include <bits/stdc++.h>
using namespace std;

int prime[46341];

int main ()
{
  //  freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, m, i, j, k = 1, temp, sq, c, tenp, cn;
    bool yes;

    prime[0] = 2;

    for (i = 3; i <= 217; i += 2)
    {
        if (prime[i] == 0)
        {
            prime[k++] = i;
            for (j = i*i; j <= 46341; j += 2*i)
                prime[j] = 1;
        }
    }

    for (; i <= 46341; i += 2)
    {
        if (prime[i] == 0)
        {
            prime[k++] = i;
        }
    }

    while(scanf("%d %d", &n, &m) != EOF)
    {
        temp = m;
        yes = true;
        sq = sqrt(m);
        if (n != 0 && m != 0)
        {
            for (j = 0; prime[j] <= sq && temp != 1; j++)
            {
                c = 0;
                while(temp%prime[j] == 0)
                {
                    c++;
                    temp /= prime[j];
                }
                if (c > 0)
                {
                    tenp = n;
                    cn = 0;

                    while (tenp != 0)
                    {
                        cn += tenp/prime[j];
                        tenp /= prime[j];
                    }
                    if (cn < c)
                    {
                        yes = false;
                        break;
                    }
                }
            }
            if (temp != 1)
            {
                if (n < temp)
                    yes = false;
            }
        }
        else yes = false;
        if ( (n == 0 && m == 1) )
            yes = true;

        if (yes == true)
            printf("%d divides %d!\n", m, n);
        else printf("%d does not divide %d!\n", m, n);
    }

    return 0;
}

