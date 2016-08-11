#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <limits>
#define MIN(A, B) (((A) < (B)) ? (A) : (B))

#define MAX(A, B) (((A) > (B)) ? (A) : (B))

using namespace std;

int main (void)
{
    ios::sync_with_stdio(false);
    unsigned x, y;
    cin >> x;
    y = x;
    for(int i = 0; i < 32; i++)
        if (x & (1 << i))
            y++;
    cout << y << endl;
    return 0;
}
