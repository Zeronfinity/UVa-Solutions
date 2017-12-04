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

map <ll, vector <ll> > ed;

int vis[300];
bool bic;

void dfs(ll n)
{
    for (ll i = 0; i < ed[n].size(); i++)
    {
        if (vis[ed[n][i]] == 0)
        {
            if (vis[n] == 1)
            {
                vis[ed[n][i]] = 2;
            }
            else
                vis[ed[n][i]] = 1;
            dfs(ed[n][i]);
        }
        else
        {
            if (vis[n] == vis[ed[n][i]])
                bic = false;
        }
    }
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m;


    for (cs = 1; ; cs++)
    {
        sl(n);

        if (n == 0)
            break;

        sl(m);
        ed.clear();
        memset(vis, 0, sizeof(vis));
        bic = true;
        while(m--)
        {
            sl(x);
            sl(y);

            ed[x].push_back(y);
            ed[y].push_back(x);
        }

        for (i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                vis[i] = 1;
                dfs(i);
            }
        }
        if (bic == false)
            printf("NOT BICOLORABLE.\n");
        else printf("BICOLORABLE.\n");
    }

    return 0;
}
