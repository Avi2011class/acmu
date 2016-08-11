#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <cstdio>
#include <cmath>
using namespace std;
int main(void)
{
    vector<bool> b(1001, true);
    for(size_t i = 2; i < 1001; i++)
    {
        if(b[i])
            for(size_t j = i * 2; j < 1001; j += i)
                b[j] = false;
    }
    //for(size_t i = 0; i < 1001; i++)
       // if(b[i]) cout << i << "  ";

    int n; cin >> n;
    vector< vector<long long int> > v(100000);

    for(size_t i = 0; i < n + 1; i++)
        v[i].resize(100);

    for(size_t i = 0; i < n + 1; i++)
        for(size_t j = 0; j < 100; j++)
            v[i][j] = 0;

    for(size_t i = 100; i < 1000; i++)
        if(b[i]) v[3][i % 100]++;

    for(size_t i = 4; i < n + 1; i++)
        for(size_t j = 10; j < 100; j++)
            for(size_t k = 1; k < 10; k++)
            {
                if(b[j + 100 * k])
                {
                    v[i][j] += v[i - 1][10 * k + (int)(j / 10)];
                    v[i][j] %= 1000000009;
                }
            }


    long long int res = 0;
    for(size_t i = 0; i < 100; i++)
    {
        res += v[n][i];
        res %= 1000000009;
    }
    cout << res;
    return 0;
}
