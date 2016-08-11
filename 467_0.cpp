#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <iomanip>
#include <set>
using namespace std;

template< typename _T1, typename _T2 = int >
void print_container(_T1 container)
{
    std::copy (container.begin(), container.end(), std::ostream_iterator< _T2 >(std::cout, " "));
    std::cout << std::endl;
}

int main(void)
{
    int N;
    std::cin >> N;
    std::set< int > se;
    se.insert(0);
    se.insert(1000000000);
    int k, t;
    for (int i = 0; i < N; i++)
    {
        std::cin >> k >> t;
        if (se.find(k) != se.end())
            se.erase(se.find(k));
        else
            se.insert(k);
        if (se.find(t) != se.end())
            se.erase(se.find(t));
        else
            se.insert(t);
    }
    int result = 0;
    std::set< int >::iterator it = se.begin(), iq = it;
    iq ++;
    while (it != se.end())
    {
        result = std::max(result, *iq - *it);
        it++; it++;
        iq++; iq++;
    }
    std::cout << result << std::endl;
	return 0;
}
