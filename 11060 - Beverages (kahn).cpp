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
#define pll pair <int, int>
#define plp pair <int, pll >
#define pb push_back


map <string, ll> mp;
map <ll, string> mr;

ll in[110], n;
vector <ll> vc[110];
vector <string> vt;

priority_queue <ll, vector<ll>, greater<ll> > pq;

void kahn_top_sort()
{
    ll i, u;
    for(i = 1; i <= n; i++)
    {
        if(in[i]==0)
            pq.push(i); //using priority queue for ordering according to i
                        // i is input order, lowest i = first in input
    }

    while(pq.empty() == false)
    {
        u = pq.top();
        pq.pop();
        vt.pb(mr[u]); //mr is a map, u is node number after sorting by input order, mr[u] is original node

        for (i = 0; i < vc[u].size(); i++) //vc is adjacent list
        {
            if (in[vc[u][i]] > 0)
            {
                in[vc[u][i]]--;

                if (in[vc[u][i]] == 0)
                    pq.push(vc[u][i]);
            }
        }
    }
}

char ss[1000], pp[1000];


int main()
{
    ll m, i, j, l, u, v, cs=0, f;
    string s, p;
    while(scanf("%lld", &n)!=EOF)
    {

        f=0;
        for(i=1; i<=n; i++)
        {
            scanf(" %s", ss);
            l = strlen(ss);
            s.clear();
            for(j=0; j<l; j++)
                s+=ss[j];
            mp[s]=i;
            mr[i]=s;
        }
        scanf("%lld", &m);

      //  cout << n << " " << m << endl;

        while(m--)
        {
            scanf(" %s", ss);
            l = strlen(ss);
            s.clear();
            for(j=0; j<l; j++)
                s+=ss[j];
            scanf(" %s", pp);
            l = strlen(pp);
            p.clear();
            for(j=0; j<l; j++)
                p+=pp[j];

            u = mp[s];
            v = mp[p];
            in[v]++;
            vc[u].push_back(v);
        }

        kahn_top_sort();

        printf("Case #%lld: Dilbert should drink beverages in this order:", ++cs);
        p.clear();
        for(i=0; i<vt.size(); i++)
        {
            printf(" ");
            p = vt[i];
            l = p.size();
            for(j=0; j<l; j++)
                printf("%c", p[j]);

        }
        printf(".\n\n");
        memset(in, 0, sizeof(in));
        for(i=0; i<=n; i++)
            vc[i].clear();
        mp.clear();
        mr.clear();
        vt.clear();
    }
    return 0;

}

