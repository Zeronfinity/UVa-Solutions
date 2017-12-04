#include <bits/stdc++.h>
using namespace std;

unsigned int prime[100000];

int main ()
{
    long long n, i, j , k = 1, temp, flag, sq;

    prime[0] = 2;

    for (i = 3; i <= 100000; i += 2)
    {
        if (prime[i] == 0)
        {
            prime[k++] = i;
            if (i*i <= 100050)
                for (j = i*i; j <= 100000; j += i)
                    prime[j] = 1;
        }
    }

    while(cin >> n)
    {
        if (n == 0)
            break;
        flag = 0;
        cout << n << " = ";
        if (n < 0)
        {
            temp = n*(-1);
            cout << "-1";
            flag = 1;
        }
        else temp = n;
        sq = sqrt((double) temp);
        for (j = 0; prime[j] <= sq; j++)
        {
            while (temp % prime[j] == 0)
            {
                if (flag == 1)
                    cout << " x ";
                flag = 1;
                cout << prime[j];
                temp /= prime[j];
            }
        }
        if (temp!=1)
        {
            if (flag == 1)
                cout << " x ";
            flag = 1;
            cout << temp;
        }
        cout << endl;
    }

    return 0;
}
