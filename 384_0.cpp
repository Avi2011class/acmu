#include <locale.h>
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iterator>
#include <stack>
#include <algorithm>
using namespace std;
int main(void)
{
    long long int i, j;
    cin >> i >> j;
    while(j != 0)
    {
        i %= j;
        swap(i, j);
    }
    long long int n = i, m = 1000000000;
    long long int a = 1;
    long long int b = 1;
    long long int c = 1;
    long long int d = 0;
    long long int rc = 0;
    long long int rd = 1;
    long long int ta;
    long long int tb;
    long long int tc;
    while( n > 0 )
    {
        if(n % 2 == 1)
        {
            tc = rc;
            rc = (rc * a + rd * c) % m;
            rd = (tc * b + rd * d) % m;
        }

        ta = a;
        tb = b;
        tc = c;
        a = (a * a + b * c) % m;
        b = (ta * b + b * d) % m;
        c = (c * ta + d * c) % m;
        d = (tc * tb + d * d) % m;
        n = n / 2;
    }
    cout << rc << endl;

    return 0;
}
