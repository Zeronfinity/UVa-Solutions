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
#define pll pair <ll, ll>
#define plp pair <int, pll >
#define pb push_back

#define tsz 2500000

map <ll, ll> mp;

ll ar[500010], srt[500010];
ll tree[tsz];

void create(ll node, ll b, ll e)
{
    if (b == e) {
        tree[node] = 0;
        return ;
    }

    ll left = node* 2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    create(left, b, mid);
    create(right, mid + 1, e);

    tree[node] = tree[left] + tree[right];
}

ll query(ll node, ll b, ll e, ll i, ll j)
{
    if (i > j)
        return 0;

    if (e < i || j < b)
        return 0;

    if (i <= b && e <= j)
        return tree[node];

    ll left = node*2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid + 1, e, i, j);

    return p1 + p2;
}

void update(ll node, ll b, ll e, ll i)
{
    if (e < i || i < b)
        return;
    if (i <= b && e <= i) {
        tree[node]++;
        return;
    }
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    update(left, b, mid, i);
    update(right, mid + 1, e, i);

    tree[node] = tree[left] + tree[right];
}


int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n;

    for (; sl(n) != EOF;)
    {
        if (n == 0)
        {
            break;
        }

         for (i = 1; i <= n; i++)
        {
            sl(ar[i]);
            srt[i] = ar[i];
        }

        sort(srt + 1, srt + n + 1);

        mp.clear();

        for (i = 1; i <= n; i++)
        {
            mp[srt[i]] = i;
        }

        create(1, 1, n);

        ans = 0;

        for (i = 1; i <= n; i++)
        {
            ans += query(1, 1, n, mp[ar[i]] + 1, n);

//            cout << i << " " << ans << endl;

            update(1, 1, n, mp[ar[i]]);
        }

        printf("%lld\n", ans);
    }

    return 0;
}
