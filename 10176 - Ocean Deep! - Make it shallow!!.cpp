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

stack <int> st;

int main ()
{
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, n, x, y, ans, q;
    bool flag;
    char ch, s[20000];

    while (ss(s) != EOF)
    {
        for (i = 0; s[i] != 0; i++)
        {
            if (s[i] == '#')
            {
                flag = 1;
                break;
            }
            n = s[i] - '0';

            st.push(n);

        }

        if (flag == 1)
        {
            x = 1;
            y = 0;

            while(st.empty() == false)
            {
                y = (y + (st.top()*x)%131071)%131071;

                x = (x*2)%131071;

                st.pop();
            }

            if (y == 0)
                printf("YES\n");
            else printf("NO\n");
            flag = 0;
        }
    }

    return 0;
}
