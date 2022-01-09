#include <bits/stdc++.h>
#include <cmath>            // need this for atan2
using namespace std;
#define pll pair <long long, long long>

pll hull[100005];    // collection of points
pll center;          // average of points

bool sortCmd(const pll &a,const pll &b) // sorting condition
{
    long long x1 = center.first - a.first, x2 = center.first - b.first;
    long long y1 = center.second - a.second, y2 = center.second - b.second;
    double angle1 = atan2 (y1, x1), angle2 = atan2(y2, x2); // angles of points from center

    if (angle1 == angle2)                                       // if angles are same
    {
        if (a.first == b.first)     return a.second > b.second; // if x same, sort by y (desc)
        if (a.second == b.second)   return a.first < b.first;   // if y same, sort by x (asc)
    }

    return angle1 < angle2;                                     // sort by angles (asc)
}

int main()
{
    long long n, points, hullCount, x, y;
    char status;
    scanf("%lld", &n);
    while (n--)
    {
        hullCount = 0;                      // number of points on hull
        center = {0, 0};

        scanf("%lld", &points);
        for (long long i=0; i<points; i++)
        {
            scanf("%lld %lld %c", &x, &y, &status);
            if (status == 'Y')
            {
                hull[hullCount] = {x, y};
                center.first += x;          // adding points to center; will average at end
                center.second += y;
                hullCount++;
            }
        }

        center = {center.first/hullCount, center.second/hullCount}; // finding average

        printf("%lld\n", hullCount);
        sort(hull, hull + hullCount, sortCmd);  // sort based on angle with center

        pll minimal = {LONG_LONG_MAX, LONG_LONG_MAX};   // minimal point
        long long minInd = -1;  // index of minimal points

        for (long long i=0; i<hullCount; i++)   // find minimal point
        {
            if ((hull[i].first < minimal.first) || ((hull[i].first == minimal.first) && (hull[i].second < minimal.second)))
            {
                minimal = hull[i];
                minInd = i;
            }
        }

        // loop over sorted array starting from minimal point; actual array starts from negative x
        for (long long i=minInd; i<hullCount; i++)    printf("%lld %lld\n", hull[i].first, hull[i].second);
        for (long long i=0; i<minInd; i++)            printf("%lld %lld\n", hull[i].first, hull[i].second);
    }
}