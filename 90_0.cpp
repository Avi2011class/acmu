#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;
struct triangle
{
    int x1, x2, x3, y1, y2, y3;
};
int pr(int a, int b, int c, int d)
{
    return a * d - b * c;
}
int main(void)
{
    int x, y;   cin >> x >> y;
    //cout << pr(0, 4, 0, 2) << endl;
    int count;  cin >> count;
    vector<triangle> a(count);
    for(size_t i = 0; i < count; i++)
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2 >> a[i].x3 >> a[i].y3;
    vector<int> res;
    int v1x, v1y, v2x, v2y, v3x, v3y;
    for(size_t i = 0; i < count; i++)
    {
        int pr3 = pr(a[i].x1 - x, a[i].y1 - y, a[i].x2 - x, a[i].y2 - y);
        int pr1 = pr(a[i].x2 - x, a[i].y2 - y, a[i].x3 - x, a[i].y3 - y);
        int pr2 = pr(a[i].x3 - x, a[i].y3 - y, a[i].x1 - x, a[i].y1 - y);
        if(pr1 > 0 && pr2 > 0 && pr3 > 0)
            res.push_back(i + 1);
        else if(pr1 < 0 && pr2 < 0 && pr3 < 0)
            res.push_back(i + 1);

    }
    cout << res.size() << endl;
    for(size_t i = 0; i < res.size(); i++) cout << res[i] << endl;
    return 0;
}
