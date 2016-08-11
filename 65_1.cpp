#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <iomanip>
#include <set>
#include <numeric>
#include <string>
using namespace std;

template< typename _T1, typename _T2 = int >
void print_container(_T1 container)
{
    std::copy (container.begin(), container.end(), std::ostream_iterator< _T2 >(std::cout, " "));
    std::cout << std::endl;
}

int main(void)
{
    std::string message; std::cin >> message;
    int N; std::cin >> N;
    if (N == 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }
    std::vector< std::string > V(N);
    for (int i = 0; i < N; i++)
        std::cin >> V[i];
    std::vector< int > Dist;
    std::function< int(std::string) > lambda = [&message](std::string __str) -> int
    {
        int result = 0;
        for (int i = 0; i < __str.length(); i++)
            if (__str[i] != message[i])
                result++;
        return result;
    };
    std::transform(V.begin(), V.end(), std::back_inserter(Dist), lambda);
    int min_dist = *std::min_element(Dist.begin(), Dist.end());

    std::cout << std::count(Dist.begin(), Dist.end(), min_dist) << std::endl;
    for (int i = 0; i < N; i++)
        if (Dist[i] == min_dist)
            std::cout << i + 1 << " ";
    std::cout << std::endl;
	return 0;
}
