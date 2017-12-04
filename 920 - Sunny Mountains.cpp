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
#define pll pair <long long, long long>
#define pb push_back

#define EPS 0.0000000001

struct pointd
{
    double x, y;

    pointd()
    {
        x = y = 0;
    }

    pointd(double _x, double _y)
    {
        x = _x, y = _y;
    }

    bool operator < (pointd other)
    {
        if (fabs(x - other.x) > EPS)
            return x > other.x;
        return y < other.y;
    }

    bool operator == (pointd other)
    {
        return ( fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS) );
    }
} ar[200];

double dist(pointd p1, pointd p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct line
{
    double a, b, c; //ax + by + c = 0
};

void pointsToLine(pointd p1, pointd p2, line &l)
{
    if (fabs(p1.x - p2.x) < EPS)   // for vertical line
    {
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    }
    else
    {
        l.a = - (double) (p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // to check equality/parallelgiri etc of lines easier
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

int main ()
{
  //  freopen("inl.txt", "r", stdin);
   // freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, y, z, q, m, n;
    double ans, x;
    sl(t);

    while(t--)
    {
        sl(n);

        for (i = 0; i < n; i++)
        {
            sf(ar[i].x);
            sf(ar[i].y);
        }

        sort(ar, ar + n);

        m = ans = 0;

        for (i = 1; i < n; i++)
        {
            if (ar[i].y > m)
            {
                line ln;
                pointsToLine(ar[i], ar[i-1], ln);

                x = -(ln.c + ln.b*m)/ln.a;
             //   x = -(((ar[i].y - ar[i-1].y) / (ar[i].x - ar[i-1].x) * ar[i].x) - ar[i].y + m)*(ar[i].x - ar[i-1].x)/(ar[i].y - ar[i-1].y);

                pointd temp(x, m);

            //    cout << i << " a " << x << " " << m << endl;

                ans += dist(ar[i], temp);

                m = ar[i].y;
            }
          //  cout << i << " " << ans << endl;
        }
        printf("%0.2lf\n", ans);
    }

    return 0;
}
