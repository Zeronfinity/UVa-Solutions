#include <stdio.h>
int main ()
{
    char text[1000], a;
    int temp = 0, i, j;

    while(gets(text))
    {
        for (i = 0; text[i] != '\0'; i++)
        {
            if (text[i] == '"' && temp == 0)
            {
                text[i] = '`';
                for(j = 499; j > i; j--)
                    text[j+1] = text[j];
                text[i+1] = '`';
                temp = 1;
                continue;
            }
            if (text[i] == '"' && temp == 1)
            {
                text[i] = 39;
                for(j = 499; j > i; j--)
                    text[j+1] = text[j];
                text[i+1] = 39;
                temp = 0;
            }
        }
        printf("%s", text);
        printf("\n");
    }
    return 0;
}
