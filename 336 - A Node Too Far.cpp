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

map <ll, vector <ll> > edges;
deque <ll> dq;
map <ll, ll> level;
set <ll> node;

ll cnt;

void BFS(ll s, ll t)
{
    ll u, v, i;

    dq.push_back(s);
    level[s] = 1;
    cnt++;

    while(dq.empty() == false)
    {

        if (level[dq[0]] - 1 < t)
        {
            for (i = 0; i < edges[dq[0]].size(); i++)
            {
             //   cout << dq[0] << " " << level[dq[0]] << " " << edges[dq[0]][i] << " " << level[edges[dq[0]][i]] << " " << cnt << endl;
                if (level[edges[dq[0]][i]] == 0)
                {
                    level[edges[dq[0]][i]] = level[dq[0]] + 1;
                    cnt++;
                    dq.push_back(edges[dq[0]][i]);
                }
            }
        }

        dq.pop_front();
    }
}

int main ()
{
    ll cs, t, i, j, k, n, x, y, ans, q, ns;

    for (cs = 1; ;)
    {
        sl(n);

        if (n == 0)
            break;

        while(n--)
        {
            sl(x);
            sl(y);

            edges[x].push_back(y);
            edges[y].push_back(x);

            node.insert(x);
            node.insert(y);
        }

        ns = node.size();

        while(1)
        {
            dq.clear();
            level.clear();
            cnt = 0;

            sl(x);
            sl(y);
            if (x == 0 && y == 0)
                break;

            BFS(x, y);

            printf("Case %lld: %lld nodes not reachable from node %lld with TTL = %lld.\n", cs++, ns - cnt, x, y);
        }
        edges.clear();
        node.clear();
    }

    return 0;
}
