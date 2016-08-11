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

    int H;
    char ch;
    short res = 0;

    cin >> H;
    short S[1001][1001];
    for (size_t i = 0; i < H; i++)
        for (size_t j = 0; j < H; j++)
        {
            cin >> ch;
            S[i][j] = (short)(ch - '0');
            res = MAX(res, S[i][j]);
        }

    short u, l;

    for (int i = 1; i < H; i++)
        for (int j = 1; j < H; j++)
        {
            if (S[i][j] == 1)
            {
                u = S[i - 1][j];
                l = S[i][j - 1];
                if (u != l)
                    S[i][j] = MIN(u, l) + 1;
                else
                    if (S[i - u][j - l])
                        S[i][j] = u + 1;
                    else
                        S[i][j] = u;
            }
            res = MAX(res, S[i][j]);
        }

    cout << (res * res) << endl;
    return 0;
}
