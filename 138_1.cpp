#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <climits>
using namespace std;
struct line
{
    long long int start, stop, weight;
};
long long int min(long long int a, long long int b)
{
    return (a < b) ? a : b;
}
int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    line tmp;
    vector<line> r;
    for(size_t j = 0; j < m; j++)
    {
        cin >> tmp.start >> tmp.stop >> tmp.weight;
        tmp.start--;
        tmp.stop--;
        tmp.weight;
        r.push_back(tmp);
    }
    vector<long long int> s;
    for(size_t j = 0; j < n; j++) s.push_back(LLONG_MAX);
    s[0] = 0;
 
    for(size_t i = 0; i < n; i++)
        for(size_t j = 0; j < m; j++)
            if(s[ r[j].start ] != LLONG_MAX)
                s[ r[j].stop ] = min(s[ r[j].stop ], s[ r[j].start ] + r[j].weight);
    for(size_t j = 0; j < n; j++) cout << ((s[j] == LLONG_MAX) ? 30000 : s[j]) << " ";
    return 0;
}