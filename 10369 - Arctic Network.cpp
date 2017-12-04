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

struct nodee
{
    int x, y;
} node[550];

struct ed
{
    nodee x, y;
    double z;
} edge[550];

bool comp (ed left, ed right)
{
    if (left.z > right.z)
        return true;
    else return false;
}



int main ()
{
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, ans, q, esz;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);

        esz = 0;

        for (i = 0; i < m; i++)
        {
            sl(node[m].x);
            sl(node[m].y);

            for (j = 0; j < i; j++)
            {
                edge[esz].x = node[i];
                edge[esz].y = node[j];

                edge[esz].z = sqrt((node[i].x - node[j].x)*(node[i].x - node[j].x) + (node[i].y - node[j].y)*(node[i].y - node[j].y));
            }
        }

        sort(edge, edge + esz, comp);

        mst();

        printf("Case %lld: ", cs);
    }

    return 0;
}
