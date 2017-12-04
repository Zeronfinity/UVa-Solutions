#include <stdio.h>
#include <string.h>

int main()
{
    int i, n, j, k, sum, flag;
    char a[250], b[250], c[250], d[250], e,carry;
    scanf("%d",&n);
    while(n--)
    {
        scanf(" %s %s", a, b);


        sum = 0, flag = 0;

        for (i=0, j=strlen(a)-1; j>=0 ; i++, j--)
            c[i] = a[j];
        c[i] = 0;

        for (i=0, j=strlen(b)-1; j>=0 ; i++, j--)
            d[i] = b[j];
        d[i] = 0;

        carry=0;
        for (i=strlen(c)-1, j=strlen(d)-1; i >= 0 || j >= 0 ; i--, j--)
        {
            sum=c[i]-'0'+d[j]-'0'+carry;
            if(sum>9)
            {

                sum=sum%10;
                carry++;
            }
            else carry=0;
            printf("%d",sum);
        }
        printf("\n");
    }
        return 0;
}
