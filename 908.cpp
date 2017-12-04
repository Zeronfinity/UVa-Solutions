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
    ll u, v, w;
} edge[20000];

bool comp(ed left, ed right)
{
    if (left.w < right.w)
        return true;
    else return false;
}
map <ll, ll> par;

ll rfind(ll n)
{
    if (par[n] == n)
        return n;

    return (par[n] = rfind(par[n]));
}


int main ()
{
  // freopen("outu.txt", "w", stdout);

  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, cnt, z, ans1, ans2, q, m, esz, nd;

    cs = 1;

    while(sl(n) != EOF)
    {
        nd = n;
        par.clear();
        ans1 = 0;
        n--;

        while(n--)
        {
            sl(x);
            sl(y);
            sl(z);

            ans1 += z;
        }

        esz = 0;

       // cout << n << endl;

        sl(k);
        while(k--)
        {
            sl(edge[esz].u);
            sl(edge[esz].v);
            sl(edge[esz].w);
            par[edge[esz].u] = edge[esz].u;
            par[edge[esz].v] = edge[esz].v;
            esz++;
        }
//        cout <<k << endl;

        sl(m);
        while(m--)
        {
            sl(edge[esz].u);
            sl(edge[esz].v);
            sl(edge[esz].w);
            par[edge[esz].u] = edge[esz].u;
            par[edge[esz].v] = edge[esz].v;
            esz++;
        }

        sort(edge, edge + esz, comp);
        ans2 = 0;
        cnt = 0;
        for (i = 0; i < esz; i++)
        {
            x = rfind(edge[i].u);
            y = rfind(edge[i].v);

            if (x != y)
            {
                cnt++;
              //  cout << edge[i].u << " " << edge[i].v << " " << edge[i].w << " " << x << " " << y << endl;
                par[x] = par[y];
 //               cout << edge[i].u << " " << edge[i].v << " " << edge[i].w << " " << rfind(edge[i].u) << " " << rfind(edge[i].v) << endl;
                ans2 += edge[i].w;
            }
            if (cnt == nd-1)
                break;
        }

        if (cs == 2)
            printf("\n");
        cs = 2;

        printf("%lld\n%lld\n", ans1, ans2);
    }

    return 0;
}
