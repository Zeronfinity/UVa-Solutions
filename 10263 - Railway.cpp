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

#define EPS 0.000000001

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
            return x < other.x;
        return y < other.y;
    }

    bool operator == (pointd other)
    {
        return ( fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS) );
    }
} root;

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

double dist(pointd p1, pointd p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

bool areParallel(line l1, line l2)
{
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); //checking if a and b of both lines are same
}

bool areSame(line l1, line l2)
{
    return areParallel(l1,l2) && (fabs(l1.c - l2.c) < EPS); //checking if both lines are parallel and c is same
}

bool areIntersect(line l1, line l2, pointd &p) //returns true if the lines intersect
{
    if (areParallel(l1, l2))
        return false; // no intersection

    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

    if (fabs(l1.b) > EPS)
        p.y = -(l1.a * p.x + l1.c)/l1.b;
    else p.y = -(l2.a * p.x + l2.c)/l2.b;

    return true;
}

struct vec
{
    double x, y;
    vec()
    {
        x = y = 0;
    }

    vec(double _x, double _y)
    {
        x = _x, y = _y;
    }
};

vec toVec(pointd a, pointd b)   // convert a and b points to vector a->b
{
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s)   // nonnegative s = [<1 .. 1 .. >1]
{
    return vec(v.x * s, v.y * s);
}

pointd translate(pointd p, vec v)   // translate p according to v
{
    return pointd(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b)
{
    return (a.x * b.x + a.y * b.y);
}
double vec_magni(vec v) // square of magnitude
{
    return sqrt(v.x * v.x + v.y * v.y);
}
double norm_sq(vec v) // square of magnitude
{
    return (v.x * v.x + v.y * v.y);
}
double distToLine(pointd p, pointd a, pointd b, pointd &c)   //also creates closest point c, distance from point p to line ab
{
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // u = ap.ab/|ab| * ab/|ab|
    return dist(p, c);
}

double distToLineSeg(pointd p, pointd a, pointd b, pointd &c)   //also creates closest point c, distance from point p to line segment ab
{
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0)
    {
        c = pointd(a.x, a.y); // closer to a
        return dist(p, a);
    }
    if (u > 1.0)
    {
        c = pointd(b.x, b.y); // closer to b
        return dist(p, b);
    }
    c = translate(a, scale(ab, u));
    return dist(p, c);
}



int main ()
{
  //  freopen("inl.txt", "r", stdin);
    //freopen("outu.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, q, m, n;
    double mn;

    while(sf(root.x) != EOF)
    {
        sf(root.y);

        sl(n);

        pointd a, b, c, ans;

        sf(a.x);
        sf(a.y);

        mn = 100000000000000000;

        while(n--)
        {
            sf(b.x);
            sf(b.y);

            double dis = distToLineSeg(root, a, b, c);

            if (dis < mn)
            {
                ans = c;
                mn = dis;
            }
         //   cout << a.x << " " << a.y << " " << b.x << " " << b.y << " " << c.x << " " << c.y << " " << dis << endl;

            a = b;

        }

        printf("%0.4lf\n%0.4lf\n", ans.x, ans.y);
    }

    return 0;
}
