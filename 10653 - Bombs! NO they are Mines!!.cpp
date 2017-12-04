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
#define pii pair<int,int>

bool grid[1005][1005];

int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1 };

ll level[1005][1005];
deque <pii> dq;

ll r, c;

ll bfs(ll sx, ll sy, ll dx, ll dy)
{
    ll nx, ny, i;

    memset(level, -1, sizeof(level));

    dq.clear();

    pii s(sx, sy);

    dq.push_back(s);
    level[sx][sy] = 0;

    while(dq.empty() == false)
    {
        for (i = 0; i < 4; i++)
        {
            nx = dq[0].first + dirx[i];
            ny = dq[0].second + diry[i];

            if (nx == dx && ny == dy)
                return level[dq[0].first][dq[0].second] + 1;

            pii n(nx, ny);


            if (grid[nx][ny] != 1 && level[nx][ny] == -1 && 0 <= nx && nx <= r && 0 <= ny && ny <= c)
            {
                level[nx][ny] = level[dq[0].first][dq[0].second] + 1;
                dq.push_back(n);
            }
        }
        dq.pop_front();
    }
}

int main ()
{
    ll cs, t, i, j, k, n, x, y, ans, q, br, sx, sy, dx, dy;

    while(1)
    {
        sl(r);
        sl(c);

        if (r == 0 && c == 0)
            break;

        memset(grid, 0, sizeof(grid));

        sl(br);

        while(br--)
        {
            sl(x);
            sl(n);
            while(n--)
            {
                sl(y);
                grid[x][y] = 1;
            }
        }

        sl(sx);
        sl(sy);
        sl(dx);
        sl(dy);


        printf("%lld\n", bfs(sx, sy, dx, dy));
    }

    return 0;
}
