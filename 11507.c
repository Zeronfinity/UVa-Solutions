#include <stdio.h>
#include <string.h>
int main()
{
    int i, x;
    long L;

    char bend[3], dir[3];

    while(scanf("%ld", &L), L != 0)
    {
        strcpy(dir, "+x");

        for (i = L-1; i > 0; i--)
        {
            scanf(" %s", bend);

            if (strcmp(bend, "No") == 0)
                continue;
            if (strcmp(dir, "+x") == 0)
            {
                strcpy(dir, bend);
                continue;
            }
            if (strcmp(dir, "-x") == 0)
            {
                strcpy(dir, bend);
                if (dir[0] == '+')
                    dir[0] = '-';
                else dir[0] = '+';
                continue;
            }


            if (bend[0] == dir[0] && bend[1] == dir[1])
            {
                if (dir[0] == '+')
                    dir[0] = '-';
                else dir[1] = '+';
                dir[1] = 'x';
            }

            if (bend[0] != dir[0] && bend[1] == dir[1])
            {
                dir[0] = '+';
                dir[1] = 'x';
            }

        }
        printf("%s\n", dir);
    }

    return 0;
}
