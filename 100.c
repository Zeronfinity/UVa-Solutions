#include <stdio.h>
int main ()
{
    long i, j, num, count, temp, max, a, iori, jori;

    while ((scanf("%ld %ld", &i, &j)) != EOF)
    {   max = 0;

        iori = i;
        jori = j;

        if (i > j)
        {
            temp = i;
            i = j;
            j = temp;
        }
        for (a = i; a <= j; a++)
        {
            num = a;
            count = 1;
            while (num != 1)
            {
                if (num % 2 == 1)
                {
                    num = 3*num + 1;
                }
                else
                {
                    num /= 2;
                }
                count++;
            }
            if (count > max)
                max = count;
        }
        printf("%ld %ld %ld\n", iori, jori, max);
    }
    return 0;
}
