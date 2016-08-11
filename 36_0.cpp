#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> pr;
    int n, count = 0; cin >> n;
    for(size_t i = 2; i < 2 * n; i++)
    {
        bool b = true;
        for(size_t j = 0; j < pr.size(); j++)
            if(i % pr[j] == 0)
            {
                b = false;
                break;
            }
        if(b)
        {
            pr.push_back(i);
            if(i > n) count++;
        }
    }
    cout << count << endl;
    return 0;
}
