#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iterator>
#include <algorithm>
using namespace std;
int main(void)
{
    freopen("input.txt", "r", stdin);
    int n, start, stop;
    cin >> n >> start >> stop;
    start--; stop--;
    vector< vector<int> > V(n);
    for(size_t i = 0; i < n; i++) V[i].resize(n);
    for(size_t i = 0; i < n; i++)
        for(size_t j = 0; j < n; j++)
            cin >> V[i][j];
    vector<bool> en(n, false);
    vector<int> ro(n, 10000000);
    ro[start] = 0;
    en[start] = true;

    while(true)
    {
        for(size_t i = 0; i < n; i++)
            if(en[i])
            {
                for(size_t j = 0; j < n; j++)
                    if( (i != j) && (V[i][j] > 0) && (ro[j] > ro[i] + V[i][j]) )
                    {
                        ro[j] = ro[i] + V[i][j];
                        en[j] = true;
                    }
                en[i] = false;
            }
        int count = 0;
        for(size_t i = 0; i < n; i++)
            if(en[i]) count++;
        if(count == 0) break;
    }
    cout << (ro[stop] == 10000000 ? -1 : ro[stop]) << endl;
    return 0;
}
