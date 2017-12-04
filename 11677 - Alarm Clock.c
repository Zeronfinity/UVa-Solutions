#include <stdio.h>
int main ()
{
    int H1, M1, H2, M2;
    while(scanf("%d %d %d %d", &H1, &M1, &H2, &M2))
    {
        if (H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0)
            break;
        if (H2 < H1)
            H2 += 24;
        if (H2 == H1 && M2 < M1)
            H2 += 24;
        printf("%d\n", ((H2*60+M2)-(H1*60+M1)));
    }
    return 0;
}
