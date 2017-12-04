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
#define plxy pair <long long, pll>
#define pb push_back

ll grid[1000][1000];

ll dirx[] = {0, 0, 1, -1};
ll diry[] = {1, -1, 0, 0};

ll dis[1000][1000];

void dijkstra(ll x, ll y, ll n, ll m)
{
    priority_queue <plxy, vector <plxy>, greater<plxy> > pq;
    dis[x][y] = grid[x][y];
    pq.push(plxy(dis[x][y], pll(x, y)));

    while (pq.empty() == false)
    {
        ll ux = pq.top().second.first;
        ll uy = pq.top().second.second;
        pq.pop();

        for (ll i = 0; i < 4; i++)
        {
            ll vx = ux + dirx[i];
            ll vy = uy + diry[i];

            if (0 <= vx && vx < n && 0 <= vy && vy < m)
            {
                if (dis[ux][uy] + grid[vx][vy] < dis[vx][vy])
                {
                //    cout << ux << " " << uy << " " << dis[ux][uy] << " " << vx << " " << vy << " " << dis[vx][vy] << " " << grid[vx][vy] << endl;

                    dis[vx][vy] = dis[ux][uy] + grid[vx][vy];

                    pq.push(plxy(dis[vx][vy], pll(vx, vy)) );
                }
            }

        }
    }
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
 //   freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);

        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                dis[i][j] = LLONG_MAX - 10000;

        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                sl(grid[i][j]);

        if (n == 1 && m == 1)
        {
            printf("%lld\n", grid[0][0]);
            continue;
        }

        dijkstra(0, 0, n, m);
        printf("%lld\n", dis[n-1][m-1]);
    }

    return 0;
}
