#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <set>
#include <numeric>
using namespace std;
long long int sum(long long int a, long long int b)
{
    long long int pow = 1, result = 0;
    while (a > 0 || b > 0)
    {
        int tmp = (a % 10) + (b % 10);
        result += tmp * pow;
        pow *= 10;
        if (tmp > 9)
            pow *= 10;
        a /= 10;
        b /= 10;
    }
    return result;
}
int main(void)
{
    long long int a, b, c;
    std::cin >> a >> b >> c;
    std::set< long long int > V;
    V.insert(sum(sum(a, b), c));
    V.insert(sum(a, sum(b, c)));
    V.insert(sum(b, sum(a, c)));
    std::cout << (V.size() > 1 ? "YES" : "NO") << std::endl;
    std::copy(V.begin(), V.end(), std::ostream_iterator< long long int >(std::cout, "\n"));

    return 0;
}
