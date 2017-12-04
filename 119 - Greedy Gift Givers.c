#include <stdio.h>
int main ()
{
    int n, i, j, k, l, p, mo, g, t=0;

    while(scanf("%d", &n) == 1)
    {
        if (t==0)
            t = 1;
        else printf("\n");

        char name[n+2][100];
        int m[n];

        for (i=0; i<n; i++)
        {
            scanf(" %s", name[i]);
            m[i] = 0;
        }

        for (i=0; i<n; i++)
        {
            scanf(" %s", name[n]);

            for (j=0; j<n; j++)
            {
                if (strcmp(name[n], name[j]) == 0)
                {
                    scanf("%d %d", &mo, &p);
                    if (p != 0)
                        m[j] -= (mo/p)*p;
                    else continue;

                    for (k=0; k<p; k++)
                    {
                        scanf(" %s", name[n+1]);
                        for (l = 0; l<n; l++)
                            if (strcmp(name[n+1],name[l]) == 0)
                                m[l] += mo/p;
                    }
                    break;
                }
            }
        }
        for (i=0; i<n; i++)
            printf("%s %d\n", name[i], m[i]);
    }

    return 0;
}
