#include <stdio.h>
#include <string.h>
int main ()
{
    char a[11], b[11], temp = 0, c[14], k, x, y, count;
    c[13] = 0;
    int lena, lenb;

    while(scanf(" %s %s", a, b))
    {
        if (a[0] == '0' && b[0] == '0')
            break;

        temp = 0;
        count = 0;
        lena = strlen(a) - 1;
        lenb = strlen(b) - 1;

        for (k=12; lena >= 0 || lenb >= 0; lena--, lenb--, k--)
        {
            if (lena < 0)
                x = 0;
            else x = a[lena] - '0';

            if (lenb < 0)
                y = 0;
            else y = b[lenb] - '0';

            c[k] = (x + y + temp)%10 + '0';

            if((x+y+temp) > 9)
            {
                temp = 1;
                count++;
            }
            else temp = 0;

        }
        if (count == 0)
            printf("No");
        else printf("%d", count);
        printf(" carry operation");
        if (count > 1)
            printf("s");
        printf(".\n");
    }
    return 0;
}
