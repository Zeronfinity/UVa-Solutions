#include <stdio.h>

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main ()
{
    unsigned long long a, b, c;
    while (scanf("%lld %lld", &a, &b)!=EOF)
    {
        c = a/b;
        printf("[%lld;", c);
        a = a - c*b;
        while(b!=1)
        {
            swap(&a, &b);
            c = a/b;
            printf("%lld", c);
            a=a-c*b;
            if (b==1)
                break;
            printf(",");
        }
        printf("]\n");
    }
    return 0;
}
