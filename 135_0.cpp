#include <iostream>
#include <cstdio>
#include <limits.h>
#include <algorithm>
using namespace std;
int main()
{
    // freopen(  "input.txt",  "r", stdin  );
    //freopen(  "output.txt", "w", stdout );
    int d[104][104];
    int n; cin >> n;
    for(size_t i = 0; i < n; i++)
        for(size_t j = 0; j < n; j++)
            cin >> d[i][j];

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min (d[i][j], d[i][k] + d[k][j]);

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
            cout << d[i][j] << " ";
        cout << endl;
    }

    return 0;
}
