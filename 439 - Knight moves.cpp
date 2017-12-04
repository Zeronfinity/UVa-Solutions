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

using namespace std;

#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <long long, long long>

deque <pii> dq;
ll lv[68][68];

ll drx[] = {1, 1, -1, -1, 2, -2, 2, -2};
ll dry[] = {2, -2, 2, -2, 1, 1, -1, -1};

ll bfs(ll sx, ll sy, ll dx, ll dy)
{
   // cout << sx << " " << sy << " " << dx << " " << dy << endl;

    ll i, nx, ny;

    dq.clear();
    memset(lv, 0, sizeof(lv));

    dq.push_back(pii (sx, sy));
    lv[sx][sy] = 0;

    while(dq.empty() == false)
    {
        for (i = 0; i < 8; i++)
        {
            nx = dq[0].first + drx[i];
            ny = dq[0].second + dry[i];


            if (lv[nx][ny] == 0 && 1 <= nx && nx <= 8 && 1 <= ny && ny <= 8)
            {
                lv[nx][ny] = lv[dq[0].first][dq[0].second] + 1;

           //     cout << dq[0].first << " " << dq[0].second << " " << nx << " " << ny << " " << lv[nx][ny] << endl;

                if (nx == dx && ny == dy)
                    return lv[nx][ny];

                dq.push_back(pii (nx, ny));
            }
        }
        dq.pop_front();
    }
}

int main ()
{
    ll cs, t, i, j, k, n, x, y, ans, q;
    char s[3], d[3];

    while(ss(s) != EOF)
    {
        ss(d);

        printf("To get from %s to %s takes %lld knight moves.\n", s, d, bfs(s[0] - 'a' + 1, s[1] - '0', d[0] - 'a' + 1, d[1] - '0'));
    }

    return 0;
}
