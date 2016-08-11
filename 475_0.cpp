#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <iomanip>
#include <set>
#include <numeric>
using namespace std;

template< typename _T1, typename _T2 = int >
void print_container(_T1 container)
{
    std::copy (container.begin(), container.end(), std::ostream_iterator< _T2 >(std::cout, " "));
    std::cout << std::endl;
}

int main(void)
{
    std::vector< int > V, VB;
    std::set< int > se;
    std::copy (std::istream_iterator< int >(std::cin), std::istream_iterator< int >(), std::back_inserter(V));
    std::sort(V.begin(), V.end());
    std::adjacent_difference(V.begin(), V.end(), std::back_inserter(VB));
    std::copy(VB.begin() + 1, VB.end(), std::inserter(se, se.begin()));
    std::cout << (se.size() <= 1 ? "Yes" : "No") << std::endl;
	return 0;
}
