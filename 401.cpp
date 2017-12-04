#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define grb getchar()

map <char, char> mp;

int main ()
{
    ll cs, t, i, j, k, n, x, y, ans, q, flg1, flg2, l;

    char s[500], r[500], m[500];

    mp['A'] = 'A';
    mp['E'] = '3';
    mp['H'] = 'H';
    mp['I'] = 'I';
    mp['J'] = 'L';
    mp['L'] = 'J';
    mp['M'] = 'M';
    mp['O'] = 'O';
    mp['S'] = '2';
    mp['T'] = 'T';
    mp['U'] = 'U';
    mp['V'] = 'V';
    mp['W'] = 'W';
    mp['X'] = 'X';
    mp['Y'] = 'Y';
    mp['Z'] = '5';
    mp['1'] = '1';
    mp['2'] = 'S';
    mp['3'] = 'E';
    mp['5'] = 'Z';
    mp['8'] = '8';

    while(ss(s) != EOF)
    {
        grb;

        l = strlen(s);

        for (i = 0; i <= l/2; i++)
        {
            r[i] = s[l-i-1];
            r[l-i-1] = s[i];
        }

        r[l] = 0;


        for (i = 0; i <= l/2; i++)
        {
            m[i] = mp[s[l-i-1]];
            m[l-i-1] = mp[s[i]];
        }

        m[l] = 0;

        if (strcmp(s, r) == 0 && strcmp(s, m) == 0)
            printf("%s -- is a mirrored palindrome.\n\n", s);
        else if (strcmp(s, m) == 0)
            printf("%s -- is a mirrored string.\n\n", s);
        else if (strcmp(s, r) == 0)
            printf("%s -- is a regular palindrome.\n\n", s);
        else printf("%s -- is not a palindrome.\n\n", s);
    }

    return 0;
}
