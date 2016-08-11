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
    int n, res = 1; cin >> n;
    vector<int> P(n);
    vector<bool> en(n, false);
    for(size_t i = 0; i < n; i++)
        cin >> P[i];
    for(size_t i = 0; i < n; i++)
        P[i]--;
    int result = 1;
    for(size_t i = 0; i < n; i++)
    {
        if(!en[i])
        {
            en[i] = true;
            int size = 1;
            int cur = P[i];
            while(!en[cur])
            {
                en[cur] = true;
                size++;
                cur = P[cur];
            }
            res = nok(res, size);
        }
    }
    cout << res << endl;
    return 0;
}
