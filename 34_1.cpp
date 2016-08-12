#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <set>
#include <numeric>
using namespace std;

long long int power_module(long long int a, long long int b, long long int c)
{
    long long int result = 1;
    while (b)
        if (b % 2 == 1)
        {
            result = (result * a) % c;
            b -= 1;
        }
        else
        {
            a = (a * a) % c;
            b /= 2;
        }
    return result;
}

inline bool check(std::vector< char > & V, int b1, int b2, int len)
{
    if (b1 == b2)
        return false;
    if (std::max(b1, b2) + len > V.size())
        return false;
    for (int i = 0; i < len; i++)
        if (V[b1 + i] != V[b2 + i])
        {
            return false;
        }

    return true;
}

int main(void)
{
    int N, K;
    std::cin >> N >> K;

    std::vector< char > V(N);
    for (char & ch: V) std::cin >> ch;

    if (K >= N)
    {
        std::cout << "NO" << std::endl;
        return 0;
    }
    long long int module = 514229;
    long long int primitive_root = 17;
    long long int max_power = power_module(primitive_root, K - 1, module);


    std::vector< std::set< int > > hash_control(module);
    std::vector< long long int > hash_line(1);
    long long int ha = 0;
    for (int i = 0; i < K; i++)
        ha = (ha * primitive_root + (long long int)V[i] + module) % module;

    hash_line[0] = ha;
    hash_control[ha].insert(0);

    for (int i = 0; i < N - K; i++)
    {
        long long int new_hash = ((hash_line[i] + (module - V[i]) * max_power) * primitive_root + V[i + K]) % module;
        hash_line.push_back(new_hash);
        hash_control[new_hash].insert(i + 1);
    }
    /*for (int i = 0; i < module; i++)
        if (!hash_control[i].empty())
        {
            std::copy(hash_control[i].begin(), hash_control[i].end(), std::ostream_iterator< int >(std::cout, " "));
            std::cout << std::endl;
        }//*/
    for (int i = 0; i < module; i++)
        if (!hash_control[i].empty())
        {
            for (std::set< int >::iterator it = hash_control[i].begin(); it != hash_control[i].end(); it++)
                for (std::set< int >::iterator iq = it; iq != hash_control[i].end(); iq++)
                    if (check(V, *it, *iq, K))
                    {
                        std::cout << "YES" << std::endl;
                        return 0;
                    }
        }
    std::cout << "NO" << std::endl;

    return 0;
}
