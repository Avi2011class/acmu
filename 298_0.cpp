#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <cmath>
using namespace std;
int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    
    while(b != 0)
    {
        a = a % b;
        swap(a, b);
    }
    return a;
}
int main(void)
{
    int n, x, y;
    cin >> n;
    set< pair<int, int > > se;
    for(size_t i = 0; i < n; i++)
    {
        cin >> x >> y;
        se.insert(make_pair(x, y));
    }
    int count = 0;
    pair<int, int> cur, tmp;
    while(!se.empty())
    {
        count++;
        cur = *(se.begin());
        se.erase(se.begin());
        int gc = gcd(cur.first, cur.second);
        cur.first /= gc;
        cur.second /= gc;
        for(size_t i = 0; i < 20; i++)
        {
            tmp = make_pair(cur.first * i, cur.second * i);
            if(se.find(tmp) != se.end())
                se.erase(se.find(tmp));
        }

    }
    cout << count << endl;
    return 0;
}
