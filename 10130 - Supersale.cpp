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

using namespace std;

#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)

ll pr[1010], wt[1010], n, dp[1010][31][31];

ll ksack(ll i, ll w, ll mx)
{
    if (i == n + 1)
        return 0;

//    cout << i << " " << w << " " << dp[i][w] << endl;

    if (dp[i][w][mx] != -1)
    {
        return dp[i][w][mx];
    }

    ll p1 = 0, p2 = 0;

    if (w + wt[i] <= mx)
        p1 = pr[i] + ksack(i + 1, w + wt[i], mx);

   // cout << "p1 " << i << " " << w << " " << p1 << " " << pr[i] << " " << ksack(i+1, w + wt[i], mx) << " " << p2 << " " << ksack(i+1, w, mx) << endl;


    p2 = ksack(i + 1, w, mx);

    //cout << "p2 "  << i << " " << w << " " << p1 << " " << pr[i] << " " << ksack(i+1, w + wt[i], mx) << " " << p2 << " " << ksack(i+1, w, mx) << endl;

    dp[i][w][mx] = max(p1, p2);

   // cout << i << " " << w << " " << p1 << " " << p2 << " " << dp[i][w] << endl;

    return dp[i][w][mx];
}

int main ()
{
    ll cs, t, i, j, k, x, y, ans, q;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        for (i = 0; i <= 1001; i++)
            for (j = 0; j <= 30; j++)
                for (k = 0; k <= 30; k++)
                    dp[i][j][k] = -1;

        sl(n);

        for (i = 1; i <= n; i++)
        {
            sl(pr[i]);
            sl(wt[i]);
        }

        sl(y);

        ans = 0;


        for (k = 1; k <= y; k++)
        {
            sl(x);

//            for (i = 0; i <= 1001; i++)
  //              for (j = 0; j <= 30; j++)
    //                dp[i][j] = -1;

            ans += ksack(1, 0, x);

     //       cout << x << " " << ksack(1, 0, x) << endl;
        }

        printf("%lld\n", ans);
    }

    return 0;
}
