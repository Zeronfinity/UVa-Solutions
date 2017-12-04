#include <stdio.h>
#include <iostream>
#include <climits>
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

ll n, l;

struct data
{
    ll a[3];
} temp;

vector <data> ar;

bool comp (data left, data right)
{
    if (left.a[0] != right.a[0])
        return left.a[0] > right.a[0];
    else if (left.a[1] != right.a[1])
        return left.a[1] > right.a[1];
    else return left.a[2] > right.a[2];
}

ll dp[200][200][3][200][3];

ll solve(ll pos, ll i, ll io, ll j, ll jo)
{
  //  cout << pos << " " << i << " " << io << " " << j << " " << jo << endl;

    if (pos >= l)
        return 0;

    if (dp[pos][i][io][j][jo] != -1)
        return dp[pos][i][io][j][jo];

    ll x = 0;

    if (ar[pos].a[0] < ar[i].a[io] && ar[pos].a[1] < ar[j].a[jo])
        x = max(x, solve(pos, pos, 0, pos, 1) + ar[pos].a[2]);

    x = max(x, solve(pos+1, i, io, j, jo));

    dp[pos][i][io][j][jo] = x;

    return dp[pos][i][io][j][jo];
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs = 0, t, i, j, k, ans, q, m, a, b, c;

    while(1)
    {
        sl(n);

        if (n == 0)
            break;

        ar.clear();

        for (i = 1; i <= n; i++)
        {
            sl(a);
            sl(b);
            sl(c);

            temp.a[0] = a;
            temp.a[1] = b;
            temp.a[2] = c;
            ar.pb(temp);
            temp.a[0] = a;
            temp.a[1] = c;
            temp.a[2] = b;
            ar.pb(temp);
            temp.a[0] = b;
            temp.a[1] = a;
            temp.a[2] = c;
            ar.pb(temp);
            temp.a[0] = b;
            temp.a[1] = c;
            temp.a[2] = a;
            ar.pb(temp);
            temp.a[0] = c;
            temp.a[1] = b;
            temp.a[2] = a;
            ar.pb(temp);
            temp.a[0] = c;
            temp.a[1] = a;
            temp.a[2] = b;
            ar.pb(temp);
        }

        memset(dp, -1, sizeof(dp));

        sort(ar.begin(), ar.end(), comp);


        l = ar.size();

        temp.a[0] = LLONG_MAX;
        ar.pb(temp);

    //    cout << ar.size() << endl;

        printf("Case %lld: maximum height = %lld\n", ++cs, solve(0, l, 0, l, 0));
    }

    return 0;
}



