#include <iostream>
#include <vector>
using namespace std;

inline int gcd(int a, int b)
{
    while(b)
    {
        a = a % b;
        swap(a, b);
    }
    return a;
}
inline int nok(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main(void)
{
    int n; cin >> n;
    vector<int> P(n), res(n);
    vector<bool> en(n, false);
    for(size_t i = 0; i < n; i++)
        cin >> P[i];
    for(size_t i = 0; i < n; i++)
        P[i]--;
    for(size_t i = 0; i < n; i++)
    {
        res[P[i]] = i + 1;
    }
    for(size_t i = 0 ; i < n; i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
