#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <stack>

int main(void)
{
    std::stack< int > V;
    int N; 
    std::cin >> N;
    if (N == 0)
    {
        std::cout << 10 << std::endl;
        return 0;
    }
    if (N == 1)
    {
        std::cout << 1 << std::endl;
    }
    for (int i = 9; i > 1; i--)
        while (N % i == 0)
        {
            N /= i;
            V.push(i);
        }
    if (N != 1)
        std::cout << -1 << std::endl;
    else
    {
        while (!V.empty())
        {
            std::cout << V.top();
            V.pop();
        }
        std::cout << std::endl;
    }
    return 0;
}
