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

struct ed
{
    string u, v;
    int w;
} edge[20000];

bool comp(ed left, ed right)
{
    if (left.w > right.w)
        return true;
    else return false;
}

map <string, string> par;

string rfind(string n)
{
    if (par[n] == n)
        return n;
    return (par[n] = rfind(par[n]));
}

int main ()
{
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, ans, q, m, mx;
    string src, dst;

    string x, y;

    for (cs = 1; ; cs++)
    {
        sl(n);
        sl(m);

        if (n == 0 && m == 0)
            break;

        par.clear();

        for (i = 0; i < m; i++)
        {
            cin >> edge[i].u >> edge[i].v;
            si(edge[i].w);
            par[edge[i].u] = edge[i].u;
            par[edge[i].v] = edge[i].v;
        }

        cin >> src >> dst;

        sort(edge, edge + m, comp);

        mx = 30000;

        for (i = 0; i < m; i++)
        {
            x = rfind(edge[i].u);
            y = rfind(edge[i].v);

            if (x != y)
            {
                par[x] = y;
                mx = min((ll) edge[i].w, mx);
            }
            if (rfind(src) == rfind(dst))
                break;
        }

        printf("Scenario #%lld\n", cs);
        printf("%lld tons\n\n", mx);
    }

    return 0;
}
