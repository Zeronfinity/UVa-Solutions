#include <bits/stdc++.h>
using namespace std;

long long pwr(long long b, long long p, long long m)
{
    long long ans, x;

    if (p == 0)
        return 1;

    x = (pwr(b, p/2, m))%m;
    if (p%2 == 0)
        ans = (x*x)%m;
    else ans = ((x*x)%m*b%m)%m;

    return ans%m;
}

int main (){

    long long x, y, n, t;

    cin >> t;

    while(t--)
    {
        cin >> x >> y >> n;
        cout << pwr(x, y, n) << endl;
    }

    cin >> t;
    return 0;
}
