#include <stdio.h>
int main()
{
    int i;
    char s[32], a;

    while(scanf("%s", s) != EOF)
    {
        scanf("%c", &a);
        for (i = 0; s[i] != 0; i++)
            if (s[i] >= 'A' && s[i] <= 'C')
                printf("2");
            else if (s[i] >= 'D' && s[i] <= 'F')
                printf("3");
            else if (s[i] >= 'G' && s[i] <= 'I')
                printf("4");
            else if (s[i] >= 'J' && s[i] <= 'L')
                printf("5");
            else if (s[i] >= 'M' && s[i] <= 'O')
                printf("6");
            else if (s[i] >= 'P' && s[i] <= 'S')
                printf("7");
            else if (s[i] >= 'T' && s[i] <= 'V')
                printf("8");
            else if (s[i] >= 'W' && s[i] <= 'Z')
                printf("9");
            else printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}
