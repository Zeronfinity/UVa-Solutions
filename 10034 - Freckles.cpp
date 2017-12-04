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
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <long long, long long>

struct node
{
    double x, y;
} nd[110];

struct edge
{
    ll ui, vi;
    double dist;
} ed[50000];

bool comp (edge left, edge right)
{
    if (left.dist < right.dist)
        return true;
    else return false;
}

ll par[200];

ll rfind(ll n)
{
    if (par[n] == n)
        return n;

    return (par[n] = rfind(par[n]));
}

int main ()
{
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, q, m, esz, u, v;

    double ans;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        esz = 0;

        for (i = 0; i < n; i++)
        {
            sf(nd[i].x);
            sf(nd[i].y);

            par[i] = i;

            for (j = 0; j < i; j++)
            {
                if (i != j)
                {
                    ed[esz].ui = j;
                    ed[esz].vi = i;
                    ed[esz].dist = sqrt( (nd[i].x - nd[j].x)*(nd[i].x - nd[j].x) + (nd[i].y - nd[j].y)*(nd[i].y - nd[j].y) );

//                    cout << endl << nd[i].x - nd[j].x << " " << nd[i].y - nd[j].y << endl;

  //                  cout << esz << " " << ed[esz].ui << " " << ed[esz].vi << " " << ed[esz].dist << endl << endl;
                    esz++;
                }
            }
        }

        sort(ed, ed + esz, comp);

        ans = 0;

        for (i = 0; i < esz; i++)
        {
            u = rfind(ed[i].ui);
            v = rfind(ed[i].vi);

        //    cout << i << " " << ed[i].ui << " " << ed[i].vi << " " << ed[i].dist << endl;

            if (u != v)
            {
                par[u] = v;
                ans += ed[i].dist;
      //          cout << ed[i].dist << " " << ans << endl;
            }
        }

        if (cs != 1)
            printf("\n");

        printf("%0.2lf\n", ans);
    }

    return 0;
}
