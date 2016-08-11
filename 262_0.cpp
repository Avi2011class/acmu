#include <iostream>
#include <set>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <iterator>
using namespace std;
int main(void)
{
    int n, t, x, y; cin >> n;
    multiset<int>::iterator it, it1;

    multiset<int> se;
    for(size_t i = 0; i < n; i++)
    {
        cin >> t;
        se.insert(t);
    }
    double res = 0;
    while(se.size() > 1)
    {
        it = se.begin();
        x = *it;
        se.erase(it);
        it = se.begin();
        y = *it;
        se.erase(it);
        res += (x + y);
        se.insert(x + y);
    }
    cout << fixed << setprecision(2) << res / 20 << endl;
    return 0;
}
