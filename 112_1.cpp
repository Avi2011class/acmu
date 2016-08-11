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

template<typename T>
class FenwickTree
{
private:
    std::vector< T > data;
    int size;
public:
    FenwickTree(int size) : size(size)
    {
        data.assign(size, (T)(0));
    }
    FenwickTree(std::vector< T > array) : size(array.size())
    {
        data.assign(size, (T)(0));
        for(int i = 0; i < size; i++)
            inc(i, array[i]);
    }
    T sum(int right)
    {
        T result = (T)0;
        for(; right >= 0; right = (right & (right + 1)) - 1)
            result += data[right];
        return result;
    }
    void inc(int index, T delta)
    {
        for(; index < size; index = (index | (index + 1)))
            data[index] += delta;
    }
    T sum(int left, int right)
    {
        return sum(right) - sum(left - 1);
    }
    T operator [] (int index)
    {
        return sum(index, index);
    }
};

template< typename T >
class PrefixTree
{
private:
    FenwickTree< T > prefix_sums;
    int size;
public:
    PrefixTree(int size) : size(size), prefix_sums(FenwickTree< T >(size)) {}
    void add(int begin_add, int end_add, T value)
    {
        prefix_sums.inc(begin_add, value);
        if (end_add < size - 1)
            prefix_sums.inc(end_add + 1, -value);
    }
    T operator [] (int index)
    {
        return prefix_sums.sum(index);
    }
};


int main(void)
{
    /*
    PrefixTree< int > P(10);
    for (int i = 0; i < 10; i++)
        std::cout << P[i] << " ";
    std::cout << std::endl;
    P.add(0, 4, 1);
    for (int i = 0; i < 10; i++)
        std::cout << P[i] << " ";
    std::cout << std::endl; //*/

    int result = 0;
    int N, K, t;
    std::cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        PrefixTree< int > P(N);
        for (int j = 0; j < N; j++)
        {
            std::cin >> t;
            result += P[t - 1];
            P.add(0, t - 1, 1);
        }

    }
    std::cout << result << std::endl;

	return 0;
}
