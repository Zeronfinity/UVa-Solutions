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
#define pb push_back

ll a[50];

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m;

    a[0] = 9;

    for (i = 1; ; i++)
    {
        if (i%2 == 0)
            a[i] = a[i-1]*9;
        else a[i] = a[i-1]*2;

        if (a[i] >= 5000000000)
            break;
    }

    for (cs = 1; sl(n) != EOF; cs++)
    {
        for (i = 0; ; i++)
        {
            if (a[i] >= n)
                break;
        }
        if (i%2 == 0)
            printf("Stan wins.\n");
        else printf("Ollie wins.\n");
    }

    return 0;
}
