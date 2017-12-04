#include <stdio.h>
#include <string.h>
int main()
{
    int i = 1;
    char s[6];
    while(scanf(" %s", s))
    {
        if (s[0] == '*')
            break;
        printf("Case %d: Hajj-e-", i);
        if (!strcmp(s, "Hajj"))
            printf("Akbar\n");
        if (!strcmp(s, "Umrah"))
            printf("Asghar\n");
        i++;
    }
    return 0;
}
