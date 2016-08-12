#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <numeric>
using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false);
    long long int N; std::cin >> N;
    if (N == 0)
    {
        std::cout << 1 << std::endl;
        return 0;
    }
    std::vector< long long int > V(N), prefix;
    for (auto & cur: V)
        std::cin >> cur;
    std::sort(V.begin(), V.end());
    std::partial_sum(V.begin(), V.end(), std::back_inserter(prefix));
    if (V[0] != 1)
    {
        std::cout << 1 << std::endl;
        return 0;
    }
    for (int i = 1; i < V.size(); i++)
        if (prefix[i - 1] + 1 < V[i])
        {
            std::cout << prefix[i - 1] + 1 << std::endl;
            return 0;
        }
    std::cout << prefix[prefix.size() - 1] + 1 << std::endl;
	return 0;
}
