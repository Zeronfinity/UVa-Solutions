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

ll ar[100100];

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m, b, e, sum;

    for (cs = 1; ; cs++)
    {
        if (sl(n) == -1)
            break;

        sl(m);

        for (i = 0; i < n; i++)
            sl(ar[i]);

        b = e = sum = 0;
        ll mn = 200000;
        ll cn = 0;

     /*   for (e = 0; e < n; e++)
        {
            sum += ar[e];

            if (sum >= m)
        } */


        while (e < n)
        {
      //      cn++;
        //    if (cn > 20)
          //      break;
          //  cout << b << " " << e << " " << sum << " " << mn << endl;

            if (sum < m)
            {
                sum += ar[e];

                if (sum < m)
                    e++;
            }
            else
            {
                if (e - b + 1 < mn)
                    mn = e - b + 1;

                sum -= ar[b];

                b++;

                if (sum < m)
                    e++;
            }

        }

        if (mn != 200000)
            printf("%lld\n", mn);
        else printf("0\n");
    }

    return 0;
}
