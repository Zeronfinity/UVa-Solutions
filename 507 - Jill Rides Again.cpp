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
    ll cs, t, i, j, k, n, x, y, z, ans, q, m, p, pc, qc;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        sl(x);

        ans = m = x;
        p = q = pc = qc = 1;

        for (i = 2; i < n; i++)
        {
            sl(x);

            if (x + m >= x)
            {
                m = x + m;
                qc = i;
            }
            else
            {
                m = x;
                pc = qc = i;
            }

            if (m > ans)
            {
                ans = m;
                p = pc, q = qc;
            }
            else if (m == ans)
            {
                if (qc - pc > q - p)
                {
                    ans = m;
                    p = pc, q = qc;
                }
            }
        }

        if (ans > 0)
            printf("The nicest part of route %lld is between stops %lld and %lld\n", cs, p, q + 1);
        else printf("Route %lld has no nice parts\n", cs);
    }

    return 0;
}
