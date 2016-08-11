#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <limits>

using namespace std;

inline int get_sum(std::vector< std::vector< int > > & part_sum, int i0, int j0, int i1, int j1)
{
    int result = 0;
    result += part_sum[i1][j1];
    if (i0 > 0)
        result -= part_sum[i0 - 1][j1];
    if (j0 > 0)
        result -= part_sum[i1][j0 - 1];
    if (i0 > 0 && j0 > 0)
        result += part_sum[i0 - 1][j0 - 1];
    return result;
}

int main (void)
{
    int H, W;
    cin >> H >> W;
    std::vector< std::vector< int > > V(H);
    for (auto & __1: V)
    {
        __1.resize(W);
        for (auto & __2: __1)
            cin >> __2;
    }

    std::vector< std::vector< int > > V_line_sum(H);
    for (size_t i = 0; i < H; i++)
        partial_sum(V[i].begin(), V[i].end(), back_inserter(V_line_sum[i]));


    std::vector< std::vector< int > > V_full_sum(H);
    std::copy(V_line_sum[0].begin(), V_line_sum[0].end(), back_inserter(V_full_sum[0]));
    for(size_t i = 1; i < H; i++)
    {
        V_full_sum[i].resize(W);
        for (size_t j = 0; j < W; j++)
            V_full_sum[i][j] = V_full_sum[i - 1][j] + V_line_sum[i][j];
    }

    int result = numeric_limits< int >::min();
    for(int i0 = 0; i0 < H; i0++)
        for (int i1 = i0; i1 < H; i1++)
            for (int j0 = 0; j0 < W; j0++)
                for (int j1 = j0; j1 < W; j1++)
                    result = max(result, get_sum(V_full_sum, i0, j0, i1, j1));
    cout << result;



    return 0;
}
