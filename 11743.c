#include <stdio.h>
int doublee(int i)
{
    i = 2*(i-'0');
    int a;
    a = i/10 + i%10;
    return a;
}
int main ()
{
    int n, a, b, i;
    char num[25];
    scanf("%d", &n);
    for (; n > 0; n--)
    {
        scanf(" %[^\n]s", num);
        a = doublee(num[0]) + doublee(num[2]) + doublee(num[5]) + doublee(num[7]) + doublee(num[10]) + doublee(num[12]) + doublee(num[15]) + doublee(num[17]);
        b = num[1] + num[3] + num[6] + num[8] + num[11] + num[13] + num[16] + num[18] - 8*'0';
        if ((a+b)%10 == 0)
            printf("Valid\n");
        else printf("Invalid\n");
    }
    return 0;
}
