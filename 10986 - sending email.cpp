#include <stdio.h>
#include <climits>
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

vector <ll> ed[20010], cost[20010];

priority_queue <pll, vector<pll>, greater<pll> > pq;

ll dis[20010];

ll dijk(ll src, ll dst)
{
    pq.push(pll(0, src));
    dis[src] = 0;

    while(!pq.empty())
    {
        pll u = pq.top();
        pq.pop();

        if (u.second == dst)
        {
            return u.first;
        }

        for (ll i = 0; i < ed[u.second].size(); i++)
        {
            ll v = ed[u.second][i];

            if (dis[u.second] + cost[u.second][i] < dis[v])
            {
                dis[v] = dis[u.second] + cost[u.second][i];
                pq.push(pll(dis[v], v));
            }
        }
    }
    return -1;
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m, src, dst;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);
        sl(src);
        sl(dst);

        for (i = 0; i <= n; i++)
        {
            ed[i].clear();
            cost[i].clear();
            dis[i] = LLONG_MAX;
        }

        while(!pq.empty())
        {
            pq.pop();
        }

        while(m--)
        {
            sl(x);
            sl(y);
            sl(z);
            ed[x].pb(y);
            ed[y].pb(x);
            cost[x].pb(z);
            cost[y].pb(z);
        }

        ans = dijk(src, dst);

        if (ans != -1)
            printf("Case #%lld: %lld\n", cs, ans);
        else printf("Case #%lld: unreachable\n", cs);
    }

    return 0;
}
