#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

int main(void)
{
    int M, N;
    std::cin >> M >> N;
    std::vector< int > begins(M), ends(M), points(N);
    for (int i = 0; i < M; i++)
    {
        std::cin >> begins[i] >> ends[i];
        if (begins[i] > ends[i])
            std::swap(begins[i], ends[i]);
    }

    for (int i = 0; i < N; i++)
        std::cin >> points[i];
    std::sort(begins.begin(), begins.end());
    std::sort(ends.begin(), ends.end());
    for (auto & point: points)
        std::cout << (std::distance(begins.begin(), std::upper_bound(begins.begin(), begins.end(), point)) -
                    std::distance(ends.begin(), std::lower_bound(ends.begin(), ends.end(), point))) << " ";
    std::cout << std::endl;
	return 0;
}
