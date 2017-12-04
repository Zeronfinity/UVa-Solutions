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

map <string, ll> mp;
map <ll, string> rmp;

vector <ll> ed[200];

ll tm, cn, vis[200], ap[200], par[200], low[200], dis[200];

vector <string> res;

void artidfs(ll u)
{
    vis[u] = 1;
    dis[u] = low[u] = tm++;

    ll child = 0;

    for (ll i = 0; i < ed[u].size(); i++)
    {
        ll v = ed[u][i];

        if (vis[v] == false)
        {
            child++;
            par[v] = u;
            artidfs(v);

            low[u] = min(low[u], low[v]);

            if (par[u] != -1 && dis[u] <= low[v])
            {
                if (ap[u] == 0)
                {
                    cn++;
                    ap[u] = 1;
                }
            }
            if (par[u] == -1 && child > 1)
            {
                if (ap[u] == 0)
                {
                    cn++;
                    ap[u] = 1;
                }

            }
        }
        else if (par[u] != v)
            low[u] = min(low[u], dis[v]);
    }
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m, avail;
    string a;
    char ta[50];

    for (cs = 1; ; cs++)
    {
        sl(n);

        if (n == 0)
            break;

        avail = tm = cn = 0;

        for (i = 0; i <= n; i++)
        {
            vis[i] = ap[i] = 0;
            par[i] = -1;
            ed[i].clear();
        }

        for (i = 0; i < n; i++)
        {
            ss(ta);
            a.clear();
            for (j = 0; ta[j] != 0; j++)
            {
                a.push_back(ta[j]);
            }
            mp[a] = i;
            rmp[i] = a;
        }


        sl(m);

        while(m--)
        {
            ss(ta);
            a.clear();
            for (i = 0; ta[i] != 0; i++)
            {
                a.push_back(ta[i]);
            }
            x = mp[a];

            ss(ta);
            a.clear();
            for (i = 0; ta[i] != 0; i++)
            {
                a.push_back(ta[i]);
            }
            y = mp[a];

            ed[x].pb(y);
            ed[y].pb(x);
        }

        for (i = 0; i < n; i++)
        {
            if (vis[i] == 0)
                artidfs(i);
        }

        if (cs != 1)
            printf("\n");

        printf("City map #%lld: %lld camera(s) found\n", cs, cn);

        res.clear();

        for (i = 0; i < n; i++)
        {
            if (ap[i] == 1)
            {
                res.pb(rmp[i]);
            }
        }
        sort(res.begin(), res.end());

        for (i = 0; i < res.size(); i++)
            cout << res[i] << "\n";
    }

    return 0;
}
