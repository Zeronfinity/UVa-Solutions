#include <stdio.h>
int main ()
{
    int i, j;
    char a[10000], g, ke[] = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
    while(scanf("%[^\n]s", a) != EOF)
    {
        for(i=0; a[i] != 0; i++)
        {
            for(j=0; j < 47; j++)
                if (a[i] == ke[j])
                    a[i] = ke[j-1];
        }
        printf("%s\n", a);
        scanf("%c", &g);
    }
}
