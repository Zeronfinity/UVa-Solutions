#include <stdio.h>
#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <utility>
#include <queue>

using namespace std;

#define ll int
#define sl(n) scanf("%d", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <long long, long long>

template<class T>inline bool read(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}


bool p[1000100];
ll ans[1000100];
int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, q, m, temp, add = 0;

    for (i = 2; i <= 1000000; i += 2)
    {
        if (p[i] == 0)
        {

            for (j = i; j <= 1000000; j += i)
            {
                if (j != i)
                    p[j] = 1;
                temp = j;
                while(temp%i == 0)
                {
                    temp /= i;
                    ans[j]++;
                }
           //     cout << i << " " << j << " " << ans[j] << endl;
            }
        }
        if (i == 2)
            i = 1;
    }


    for (i = 3; i <= 1000000; i++)
    {
        ans[i] = ans[i] + ans[i-1];
    }

    for (; read(n);)
    {
        printf("%d\n", ans[n]);
    }

    return 0;
}
