#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <algorithm>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <numeric>
#include <cstdint>
using namespace std;

int main (void)
{
    int N;
    cin >> N;
    vector< int > V(N);
    for (int i = 0; i < N; i++)
        cin >> V[i];
    vector< short > enabled(N * 200, 0);
    enabled[0] = 1;

    int ma = 0;
    for (std::vector< int >::iterator it = V.begin(); it != V.end(); it++)
        for (int i = ma; i >= 0; i--)
            if (enabled[i] == 1)
            {
                enabled[i + *it] = 1;
                ma = max(ma, i + *it);
            }
    //for(int i = 0; i <= ma; i++)
    //    cout << i << ": " << enabled[i] << endl;
    int result = count(enabled.begin(), enabled.end(), 1);
    cout << result << endl;
    return 0;
}
