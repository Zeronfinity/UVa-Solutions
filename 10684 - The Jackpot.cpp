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

#define ll long long
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <long long, long long>
#define pb push_back

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m;


    for (; ;)
    {
        sl(n);

        if (n == 0)
            break;

        sl(x);
        ans = m = x;
        n--;
        while(n--)
        {
            sl(x);

            if (m + x >= x)
            {
                m = m + x;
            }
            else
                m = x;

            if (m > ans)
                ans = m;
        }

        if (ans > 0)
            printf("The maximum winning streak is %lld.\n", ans);
        else printf("Losing streak.\n");
    }

    return 0;
}
