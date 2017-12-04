#include <stdio.h>
int main ()
{
    long K, N, M, a, b, i;
    while (1)
    {
        scanf("%ld", &K);
        if (K == 0)
            break;
        scanf("%ld %ld", &N, &M);
        for (i = 1; i <= K; i++)
        {
            scanf("%ld %ld", &a, &b);
            if (N == a || M == b)
                {printf("divisa\n");
                continue;}
            if (a < N && b > M)
                printf("NO\n");
            if (a < N && b < M)
                printf("SO\n");
            if (a > N && b > M)
                printf("NE\n");
            if (a > N && b < M)
                printf("SE\n");
        }
    }
}
