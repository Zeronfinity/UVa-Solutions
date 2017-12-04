#include <bits/stdc++.h>
using namespace std;

unsigned int prime[10100];

int main ()
{
    long long t, i, j, n, sq, a, b, m, k = 0, mx;


    for (i = 2; i <= 10100; i += 2)
    {
        if (prime[i] == 0)
        {
            prime[k++] = i;
            if (i*i <= 10100)
                for (j = i*i; j <= 10100; j += i)
                    prime[j] = 1;
        }
        if (i == 2)
            i = 1;
    }


    cin >> t;

    while(t--)
    {
        cin >> n;
        mx = 0;

        for (i = 0; prime[i] <= n; i++)
        {
            if ( (((n/prime[i])+1)*prime[i]) > n)
            {
                if ( (n - (n/prime[i])*prime[i]) > mx)
                {
                    m = prime[i];
                    mx = n - (n/prime[i])*prime[i];
                }
            }
        }
        cout << m << endl;
    }

    return 0;
}
