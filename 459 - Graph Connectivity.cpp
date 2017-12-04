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

ll par[28];

ll sfind(ll n)
{
    if (par[n] == n)
        return n;

    return (par[n] = sfind(par[n]));
}

int main ()
{
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, ans, q;

    char s[4], g[2];

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        ss(g);

        getchar();

        for (i = 0; i < 26; i++)
            par[i] = i;

        while(scanf("%[^\n]s", s) != EOF)
        {
            getchar();

             if (s[0] == 0)
                break;

     //       cout << g << " " << s << endl;

          //  cout << sfind(s[0] - 'A') << " " << sfind(s[1] - 'A') << endl;;

             par[sfind(s[0] - 'A')] = sfind(s[1] - 'A');

    //        cout << par[s[0] - 'A'] << " " << par[s[1] - 'A'] << endl;;

             s[0] = 0;
        }

        ans = 0;

        for (i = 0; i <= g[0] - 'A'; i++)
            if (par[i] == i)
                ans++;

        if(cs != 1)
            printf("\n");

        printf("%lld\n", ans);
    }

    return 0;
}
