#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct mcq
{
    long long d, s;
    char r;
};

long long cnt=0;

bool comp(mcq a, mcq b)
{
    cnt++;
    //if (cnt <= 50)
        cout << a.d << " " << b.d << " " << a.r << " " << b.r << " " << cnt <<endl;
    if (a.d < b.d)
    {
        return true;
    }
    else if (a.d == b.d)
    {
        if (a.r < b.r)
            return true;
        else return false;
    }
    else
        return false;
}
mcq qs[50100];

int main ()
{
   // freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    long long t, q, i, c, ans;

    scanf("%lld", &t);

    while (t--)
    {
        scanf("%lld", &q);

        c = 0;
        ans = 0;
        for (i = 0; i < q; i++)
        {
            scanf("%lld %lld %c", &qs[i].d, &qs[i].s, &qs[i].r);
        }
 /*       printf("\nprinting\n");
        for (i = 0; i < q; i++)
        {
            printf("%lld: %lld %lld %c\n", i, qs[i].d, qs[i].s, qs[i].r);
        }
        printf("printed\n\n"); */

        sort(qs,qs+q,comp);

     /*   printf("\nprinting\n");
        for (i = 0; i < q; i++)
        {
            printf("%lld: %lld %lld %c\n", i, qs[i].d, qs[i].s, qs[i].r);
        }
        printf("printed\n\n"); */

        for (i = 0; i < q; i++)
        {
            if (qs[i].s == 1 && qs[i].r == 'c')
                ans += c;

            if (qs[i].s == 0 && qs[i].r == 'i')
                c++;
        }
        printf("%lld %lld\n", cnt, ans);
    }

    return 0;
}
