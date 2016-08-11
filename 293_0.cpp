#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> mon(n);
    vector<int> per(n);
    for(size_t i = 0; i < n; i++)
        cin >> mon[i];
    for(size_t i = 0; i < n; i++)
        cin >> per[i];
    int res = 0;
    for(size_t i = 0; i < n; i++)
        res = max(res, per[i] * mon[i]);
    for(size_t i = 0; i < n; i++)
    {
        if(per[i] * mon[i] == res)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}
