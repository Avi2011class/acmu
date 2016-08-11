#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
int main(void)
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long int a, b; cin >> a >> b;
    if(a < b) swap(a, b);
    while(b != 0)
    {
        a = a % b;
        swap(a, b);
    }
    cout << a << endl;
    return 0;
}
