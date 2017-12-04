#include <stdio.h>
int main ()
{
    long N, B, H, W, P, a, i, j, cost, min;

    while (scanf("%ld %ld %ld %ld", &N, &B, &H, &W) != EOF)
    {
        min = 2000000;
        for (i = 0; i < H; i++)
        {
            scanf("%ld", &P);
            for (j = 0; j < W; j++)
            {
                scanf("%ld", &a);
                if (a >= N)
                    if (P*N < min)
                        min = P*N;
            }

        }
    if (min < B)
        printf("%ld\n", min);
    else printf("stay home\n");
    }
}
