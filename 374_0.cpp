#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
struct point
{
    long double x;
    long double y;
};
long double ca(point a, point b)
{
    return (a.x * b.x + a.y * b.y) / sqrt((a.x * a.x + a.y * a.y) * (b.x * b.x + b.y * b.y));
}
long double rast(point a, point b)
{
    point tmp;
    tmp.x = a.x - b.x;
    tmp.y = a.y - b.y;
    return sqrt(tmp.x * tmp.x + tmp.y * tmp.y);
}
int main(void)
{
    freopen("INPUT.TXT", "r", stdin);
    freopen("OUTPUT.TXT", "w", stdout);
    size_t count; cin >> count;
    size_t points[1001], tmp=0;
    point a[1001], vector, vector_tmp;
    long double angle;
    for(size_t i = 0; i < count; i++) cin >> a[i].x >> a[i].y;
    size_t now = 0, start, next;
    for(size_t i = 0; i < count; i++) if(a[i].x < a[now].x) now = i; else if ((a[i].x == a[now].x) && (a[i].y < a[now].y)) now = i;
    start = now;
    vector.x = 0;
    vector.y = -1;
    while(true)
    {
        next =(now + 1) % count; angle = -5;
        for(size_t i = 0; i < count; i++)
        {
            if(i != now)
            {
                vector_tmp.x = -a[i].x + a[now].x; vector_tmp.y = -a[i].y + a[now].y;
                if(ca(vector, vector_tmp) > angle) {angle = ca(vector, vector_tmp); next = i;}
            }
        }
        vector.x = a[now].x - a[next].x; vector.y = a[now].y - a[next].y;
        now = next;
      //  cout<<"("<<a[next].x<<", "<<a[next].y<<")  ";
        points[tmp] = next; tmp++;
        if (now == start) break;
    }
    long double ro = 0;
    for(size_t i = 0; i < tmp; i++)
    {
        ro += rast(a[points[i]], a[points[(i+1) % tmp]]);
    }
    cout << round(ro * 10) / 10;
    return 0;
}
