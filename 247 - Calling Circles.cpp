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

string s;

vector <ll> ed[40], red[40];

ll vis[40], rvis[40], et[40], tm;

map <ll, ll> pos;

void dfs(ll u)
{
    vis[u] = 1;

    for (ll i = 0; i < ed[u].size(); i++)
    {
        ll v = ed[u][i];

        if (vis[v] == 0)
        {
            dfs(v);
        }
    }

    et[u] = tm++;
    pos[et[u]] = u;

}

void rdfs(ll u)
{
    rvis[u] = 1;

    for (ll i = 0; i < red[u].size(); i++)
    {
        ll v = red[u][i];

        if (rvis[v] == 0)
        {
            cout << ", " << rmp[v];
            rdfs(v);
        }
    }
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m, avail;

    for (cs = 1; ; cs++)
    {
        sl(n);
        sl(m);

        if (n == 0 && m == 0)
            break;

        if (cs != 1)
            printf("\n");


        avail = 0;

        while(m--)
        {
            cin >> s;
            if (mp.count(s) == 0)
            {
                mp[s] = avail;
                rmp[avail] = s;
                avail++;
            }

            x = mp[s];

            cin >> s;
            if (mp.count(s) == 0)
            {
                mp[s] = avail;
                rmp[avail] = s;
                avail++;
            }

            y = mp[s];

            ed[x].pb(y);

            red[y].pb(x);
        }

        tm = 0;

        for (i = 0; i < avail; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i);
            }
        }

        sort(et, et + avail, greater<ll>());

        printf("Calling circles for data set %lld:\n", cs);

        for (i = 0; i < avail; i++)
        {
            x = pos[et[i]];

            if (rvis[x] == 0)
            {
                cout << rmp[x];
                rdfs(x);
                printf("\n");
            }
        }

        for (i = 0; i <= avail; i++)
        {
            ed[i].clear();
            red[i].clear();
            vis[i] = rvis[i] = 0;
        }
        mp.clear();
        rmp.clear();
    }

    return 0;
}
