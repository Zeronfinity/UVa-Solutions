#include <bits/stdc++.h>

#define m 20000005

using namespace std;

long long s[m], ans[m];

int main ()
{
    long long n, i, j;

    for (i = 1; i <= m; i++)
        for (j = i; j <= m; j += i)
            s[j] += i;


    ans[2] = 3;

    for (i = 3; i <= m; i++)
        ans[i] = ans[i-1] + s[i];

///    for (i = 2; i <= 20; i++)
   //     cout << i << " " << s[i] << " " << ans[i] << endl;

    while (cin >> n)
    {
        if (n == 0)
            break;
        cout << ans[n] << endl;
    }

    return 0;
}
