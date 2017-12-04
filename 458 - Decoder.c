#include <stdio.h>
int main ()
{
    int i;
    char s[2000], g;

    while(scanf("%s", s) != EOF)
    {
        scanf("%c", &g);
        for (i=0; s[i] != 0; i++)
            s[i] -= 7;

        printf("%s\n", s);
    }
    return 0;
}
