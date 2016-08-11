#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    size_t count; cin >> count;
    vector< vector<int> > a(count);
    vector<bool> b(count, false);
    for(size_t i = 0; i < count; i++)
        a[i].resize(count);
    for(size_t i = 0; i < count; i++)
        for(size_t j = 0; j < count; j++)
            cin >> a[i][j];
    bool flag = true, res = true;
    b[0] = true;
    while(flag)
    {
        flag = false;
        for(size_t i = 0; i < count; i++)
            if(b[i])
                for(size_t j = 0; j < count; j++)
                if((!b[j]) && (a[i][j] == 1))
                    {
                        flag = true;
                        b[j] = true;
                    }
    }
    int TC = 0;
    for(size_t i = 0; i < count; i++)
         for(size_t j = 0; j < count; j++)
            if(a[i][j] == 1) TC++;
    flag = true;
    for(size_t i = 0; i < count; i++) flag = flag && b[i];
    if(flag && (TC == count + count - 2))
        cout << "YES";
    else
        cout << "NO";
    return 0;

}
