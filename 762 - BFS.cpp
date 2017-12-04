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

map <string, vector <string> > edges;

deque <string> dq, ans;
map <string, ll> lv;

map <string, string> parent;

string bfs(string s, string d)
{
    ll i;

    dq.clear();
    lv.clear();
    parent.clear();

    dq.push_back(s);
    lv[s] = 0;

    while(dq.empty() == false)
    {
        for(i = 0; i < edges[dq[0]].size(); i++)
        {
            if (lv.count(edges[dq[0]][i]) == 0)
            {
                lv[edges[dq[0]][i]] = lv[dq[0]] + 1;
                parent[edges[dq[0]][i]] = dq[0];
                dq.push_back(edges[dq[0]][i]);

                if (d == edges[dq[0]][i])
                    return d;
            }
        }

        dq.pop_front();
    }
    return "No route";
}

int main ()
{
    ios_base::sync_with_stdio(0);
 //   freopen("outu.txt", "w", stdout);
    string x, y;
    ll cs, t, i, j, k, n, q;

    k = 0;

    while(cin >> n)
    {
        ans.clear();
        edges.clear();

        if (k == 1)
            cout << "\n";
        k = 1;

        for (i = 1; i <= n; i++)
        {
            cin >> x;
            cin >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        cin >> x >> y;

        if (x == y)
        {
            cout << x << " " << y << "\n";
            continue;
        }

        if (bfs(x, y) == "No route")
            cout << "No route\n";
        else {
            while(1)
            {
                ans.push_front(y);
                if (y == x)
                    break;
             //   cout << y << " " << parent[y] << endl;
                y = parent[y];
            }
            for (i = 0; i < ans.size() - 1; i++)
            {
                cout << ans[i] << " " << ans[i+1] << "\n";
            }
        }
    }

    return 0;
}
