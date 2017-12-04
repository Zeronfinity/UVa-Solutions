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
#include <sstream>

using namespace std;

#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <long long, long long>

vector <string> blank;

map <string, vector <string> > edges;
map <string, vector <string> > :: iterator mit;

deque <string> dq;
map <string, ll> lv;

ll bfs(string s, string d)
{
   // cout <<"bfs " << s << " " << d << endl;

    if (s == d)
        return 0;

    ll i;

    dq.clear();
    lv.clear();

    dq.push_back(s);
    lv[s] = 0;

//    cout << dq[0] << endl;

    while(dq.empty() == false)
    {
     //   cout << edges[dq[0]].size() << endl;

        for (i = 0; i < edges[dq[0]].size(); i++)
        {
         //   cout << edges[dq[0]][i] << endl;

            if (lv.count(edges[dq[0]][i]) == 0)
            {
                lv[edges[dq[0]][i]] = lv[dq[0]] + 1;
                dq.push_back(edges[dq[0]][i]);
            }

            if (edges[dq[0]][i] == d)
                return lv[edges[dq[0]][i]];
        }
        dq.pop_front();
    }
    return 0;
}

int main ()
{
    ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, ans, q, c;
    //char g;
    string x, y, str;

    cin >> t;

    for (cs = 1; cs <= t ; cs++)
    {
        edges.clear();

        while(1)
        {
            cin >> x;

            if (x == "*")
                break;


            for (mit = edges.begin(); mit != edges.end(); mit++)
            {
                c = 0;

                y = mit->first;

                if ( y.size() == x.size() )
                    for (i = 0; i < x.size(); i++)
                    {
                        if (x[i] != y[i])
                            c++;
                    }

             //   cout << x << " " << y << " " << c << endl;

                if (c == 1)
                {
                    edges[x].push_back(y);
                    edges[y].push_back(x);
                }
            }

            if (edges.count(x) == 0)
                edges[x] = blank;
        }

        if (cs != 1)
            cout << "\n";

       // getchar();
        getline(cin, str);

        while(1)
        {
            getline(cin, str);

           // cout << "hi " << str << endl;

            if (str.size() == 0)
            {
                break;
            }

            stringstream strm;

            strm << str;

            strm >> x >> y;

        //    getchar();

            cout << x << " " << y << " " << bfs(x, y) << "\n";
            str.clear();
        }

//        getchar();
    }

    return 0;
}
