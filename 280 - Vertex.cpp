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

map <ll, vector <ll> > ed;

bool visited[200];
ll cnt;

void DFS(ll n)
{
 //   cout << "work " << n << " " << ed[n].size() << endl;

    ll i;

    for (i = 0; i < ed[n].size(); i++)
    {
   //     cout << n << " " << i << " " << ed[n][i] << endl;

        if (visited[ed[n][i]] == false)
        {
            visited[ed[n][i]] = true;

            cnt++;

     //       cout << "hey " << ed[n][i] << endl;

            DFS(ed[n][i]);
        }
    }
}

int main ()
{
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, z, ans, q, m;

    while (1)
    {
        sl(n);

        if (n == 0)
            break;

        ed.clear();

        while(1)
        {
            sl(i);

            if (i == 0)
                break;

            while(1)
            {
                sl(j);

                if (j == 0)
                    break;

                ed[i].push_back(j);
            }
        }

        sl(y);

        while(y--)
        {
            sl(x);

        //    cout<< "hi " << i << " " << x << endl;

            cnt = 0;

            memset(visited, 0, sizeof(visited));

            DFS(x);

            printf("%lld", n - cnt);
            for (i = 1; i <= n; i++)
                if (visited[i] == false)
                    printf(" %lld", i);
            printf("\n");
        }
    }

    return 0;
}
