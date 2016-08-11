#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<long long int, long long int> mem;
//f(0)=0, f(1)=1, f(2n)=f(n), f(2n+1)=f(n)+f(n+1).
long long int f(long long int n)
{
    std::map<long long int, long long int>::iterator it = mem.find(n);
    if(it != mem.end()) return (*it).second;
    else
    {
        long long int res = (n % 2 == 0) ? f(n / 2) : (f(n / 2) + f (n / 2 + 1));
        mem[n] = res;
        return res;
    }
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    mem[0] = 0;
    mem[1] = 1;
    long long int n;
    cin >> n;
    cout << f(n);
    return 0;
}
