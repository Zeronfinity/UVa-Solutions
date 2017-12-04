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

vector <ll> ed[200], cost[200];

priority_queue <pll, vector<pll>, greater<pll> > pq;

ll dis[200];

void dijk(ll src)
{
    pq.push(pll(0, src));
    dis[src] = 0;

    while(!pq.empty())
    {
        pll u = pq.top();
        pq.pop();

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
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m, e, tm;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(e);
        sl(tm);
        sl(q);

        if (cs != 1)
        {
            for (i = 1; i <= n; i++)
            {
                ed[i].clear();
                cost[i].clear();
            }
            printf("\n");
        }


        while(q--)
        {
            sl(x);
            sl(y);
            sl(z);
            ed[y].pb(x);
            cost[y].pb(z);
        }

        for (i = 0; i <= n; i++)
            dis[i] = LLONG_MAX;

        dijk(e);

        ans = 0;

        for (i = 1; i <= n; i++)
        {
          //  cout << i << " " << dis[i] << " " << tm << endl;
            if (dis[i] <= tm)
            {
          //      cout << i << endl;
                ans++;
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}
