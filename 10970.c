#include <stdio.h>

int main ()
{
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF)
    {
        printf("%d\n", (m-1) + m*(n-1));
    }
    return 0;
}
