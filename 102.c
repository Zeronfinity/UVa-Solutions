#include <stdio.h>

int main ()
{
    long b[9], min;
    int i, temp;

    while (scanf("%ld", &b[0]) != EOF)
    {
        min = 2147483647;

        for (i=1; i < 9; i++)
            scanf("%ld", &b[i]);

        if (b[1] + b[2] + b[3] + b[4] + b[6] + b[8] < min)
        {
            min = b[1] + b[2] + b[3] + b[4] + b[6] + b[8];
            temp = 1;
        }

        if (b[1] + b[2] + b[3] + b[5] + b[6] + b[7] < min)
        {
            min = b[1] + b[2] + b[3] + b[5] + b[6] + b[7];
            temp = 2;
        }
        if (b[0] + b[1] + b[4] + b[5] + b[6] + b[8] < min)
        {
            min = b[0] + b[1] + b[4] + b[5] + b[6] + b[8];
            temp = 3;
        }

        if (b[0] + b[1] + b[3] + b[5] + b[7] + b[8] < min)
        {
            min = b[0] + b[1] + b[3] + b[5] + b[7] + b[8];
            temp = 4;
        }

        if (b[0] + b[2] + b[4] + b[5] + b[6] + b[7] < min)
        {
            min = b[0] + b[2] + b[4] + b[5] + b[6] + b[7];
            temp = 5;
        }

        if (b[0] + b[2] + b[3] + b[4] + b[7] + b[8] < min)
        {
            min = b[0] + b[2] + b[3] + b[4] + b[7] + b[8];
            temp = 6;
        }

        if (temp == 1)
            printf("BCG %ld\n", min);
        if (temp == 2)
            printf("BGC %ld\n", min);
        if (temp == 3)
            printf("CBG %ld\n", min);
        if (temp == 4)
            printf("CGB %ld\n", min);
        if (temp == 5)
            printf("GBC %ld\n", min);
        if (temp == 6)
            printf("GCB %ld\n", min);

    }

    return 0;
}
