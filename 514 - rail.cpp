#include <bits/stdc++.h>
using namespace std;
unsigned int a[100000000];
int main ()
{
    stack <unsigned int> s;
    s.push(0);
    long long i, n, j, flag = 0;

    while (scanf("%lld", &n))
    {
        if (n == 0)
            break;

        while (cin >> a[0])
        {
            if (a[0] == 0)
                break;
            for (i = 1; i < n; i++)
                cin >> a[i];

            for (i = j = n-1; i >= 0; i--)
            {
                if ((j >= 0) && a[j] == i+1)
                {
                    j--;
                }
                else if (s.top() != 0 && s.top()==i+1)
                {
                    if (s.top() == i+1)
                        s.pop();
                    else if (j < 0)
                        flag = 1;
                }
                else
                {
                    while(1)
                    {
                        if(a[j] == i+1)
                        {
                            j--;
                            break;
                        }
                        else
                        {
                            if (j == -1)
                            {
                                flag = 1;
                                break;
                            }
             //           cout << i + 1 << " " << a[j] << endl;
                            s.push(a[j]);
                            j--;
                        }
                    }
                }
          //      cout << i + 1 << " " << a[j] << " " << flag << endl;
                if (flag == 1)
                    break;
            }
            if (flag == 0 && i == -1)
                printf("Yes\n");
            else cout << "No" << endl;
            flag = 0;
            while (s.top()!=0)
                s.pop();
        }
        cout << endl;
    }
    return 0;
}
