#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <set>
#include <numeric>
using namespace std;

int main(void)
{
    int N;
    std::cin >> N;
    std::vector< int > V(N);
    for (int & cur: V)
        std::cin >> cur;
    std::vector< int >::iterator res = std::find_if(V.begin(), V.end(), [](int &H) -> bool {return H <= 437;});
    if (res == V.end())
        std::cout << "No crash" << std::endl;
    else
        std::cout << "Crash " << std::distance(V.begin(), res) + 1 << std::endl;

    return 0;
}
