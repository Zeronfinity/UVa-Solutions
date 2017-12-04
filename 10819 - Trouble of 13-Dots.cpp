#include <stdio.h>
#include <iostream>
#include <climits>
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

ll cost[110], fav[110], m, n;

pll dp[110][10310];

pll solve(ll i, ll wt)
{
    if (i >= n)
    {
        return pll(0, wt);
    }

    if (dp[i][wt].first != -1)
        return dp[i][wt];

    pll p1(0,0), p2(0,0), p3(0,0);

    if (wt + cost[i] <= m + 200)
    {
        p1 = solve(i + 1, wt + cost[i]);

        p1.first += fav[i];
        p1.second += cost[i];

        if (p1.second <= 2000)
            p1 = pll(0,0);
    }

    if (wt + cost[i] <= m)
    {
        p3 = solve(i + 1, wt + cost[i]);
        p3.first += fav[i];
        p3.second += cost[i];
    }

    p2 = solve(i + 1, wt);

//    cout << i << " " << wt << " " << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << " " << p3.first << " " << p3.second << endl;

    if (p1.first >= p2.first && p1.first >= p3.first)
        dp[i][wt] = p1;
    else if (p2.first >= p1.first && p2.first >= p3.first)
        dp[i][wt] = p2;
    else dp[i][wt] = p3;

    return dp[i][wt];
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q;

    for (; sl(m) != EOF; )
    {
        sl(n);

        for (i = 0; i < n; i++)
        {
            sl(cost[i]);
            sl(fav[i]);
        }

        for (i = 0; i <= n; i++)
            for (j = 0; j <= m + 210; j++)
                dp[i][j].first = -1;

        printf("%lld\n", solve(0, 0).first);
    }

    return 0;
}
