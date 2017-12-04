#include <stdio.h>

int main ()
{

    char a[10000], b;
    while (scanf("%[^\n]s", a) != EOF)
    {
        printf("%s\n", a);
        scanf("%c", &b);
    }
    return 0;

}
