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

vector <ll> edges[23];
deque <ll> dq;

map <ll, ll> level;

ll BFS(ll s, ll d)
{
    level.clear();
    dq.clear();

    ll i;

    if (s == d)
        return 0;

    dq.push_back(s);
    level[s] = 0;

    while(dq.empty() == false)
    {
        for (i = 0; i < edges[dq[0]].size(); i++)
        {
            if (!level.count(edges[dq[0]][i]))
            {
                level[edges[dq[0]][i]] = level[dq[0]] + 1;

                if (edges[dq[0]][i] == d)
                    return level[edges[dq[0]][i]];

                dq.push_back(edges[dq[0]][i]);
            }

        }

        dq.pop_front();
    }
}

int main ()
{
    ll cs = 1, t, i, j, k, n, x, y, ans, q;

    while(sl(n) != EOF)
    {
        printf("Test Set #%lld\n", cs++);

        for (i = 0; i < 22; i++)
            edges[i].clear();

        while(n--)
        {
            sl(x);
            edges[1].push_back(x);
            edges[x].push_back(1);
        }

        for (i = 2; i <= 19; i++)
        {
            sl(n);
            while(n--)
            {
                sl(x);
                edges[i].push_back(x);
                edges[x].push_back(i);
            }
        }

        sl(n);

        while(n--)
        {
            sl(x);
            sl(y);
            printf("%2lld to %2lld: %lld\n", x, y, BFS(x, y));
        }
        printf("\n");
    }

    return 0;
}
