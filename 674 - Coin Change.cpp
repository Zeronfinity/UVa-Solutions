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

ll coin[] = {50, 25, 10, 5, 1};
ll dp[6][7500];

ll ksack(ll i, ll w)
{
    if (i == 5)
    {
        if (w == 0)
            return 1;
        else return 0;
    }

    if (dp[i][w] != -1)
    {
        return dp[i][w];
    }

    ll p1= 0, p2 = 0;

    if (w - coin[i] >= 0)
        p1 = ksack(i, w - coin[i]);

    p2 = ksack(i + 1, w);

    dp[i][w] = p1+p2;

    return dp[i][w];
}

int main ()
{
    ll cs, t, i, j, k, n, x, y, ans, q;

    memset(dp, -1, sizeof(dp));

    while (sl(n) != EOF)
    {
        ans = ksack(0, n);
        printf("%lld\n", ans);
    }

    return 0;
}
