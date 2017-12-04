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

struct node
{
    string s;
    ll num;
};

map <string, node> par;
map <string, node> :: iterator mit;

string rfind(string s)
{
    if(par[s].s == s)
        return s;
    return (par[s].s = rfind(par[s].s));
}

int main ()
{
    //freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, ans, q, c, r;

    string s, d, u, v;

    for (cs = 1; ; cs++)
    {
        ans = 0;
        par.clear();

        sl(c);
        sl(r);

        if (c == 0 && r == 0)
        {
            break;
        }

        while (c--)
        {
            cin >> s;
            par[s].s = s;
            par[s].num = 1;
        }

        while(r--)
        {
            cin >> s >> d;

//            u = rfind(s);
 //           v = rfind(d);
      //      cout << par[s].s << " " << par[d].s << " " << par[rfind(s)].num << " " << par[rfind(d)].num << endl;

            if (par[rfind(s)].s != par[rfind(d)].s)
                par[rfind(s)].num += par[rfind(d)].num;

            par[rfind(d)].s = rfind(s);
        //    cout << rfind(s) << " " << rfind(d) << " " << par[rfind(s)].num << " " << par[rfind(d)].num << endl;

        }

        for (mit = par.begin(); mit != par.end(); mit++)
        {
            if ((mit->second).num > ans)
                ans = (mit->second).num;
        }

        printf("%lld\n", ans);
    }

    return 0;
}
