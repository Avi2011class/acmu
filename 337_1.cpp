#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <set>
#include <map>
#include <iterator>
#include <cmath>

typedef long long int lli;
using namespace std;
int n, k;
lli result;
vector<int> req;
bool sr(int a, int b)
{
    return (a > b);
}
lli nod(lli a, lli b)
{
    while(b != 0)
    {
        a = a % b;
        swap(a, b);
    }
    return a;
}
inline lli nok_t(lli a, lli b)
{
    return a / nod(a, b) * b;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(req));
    ///cleaning
    sort(req.begin(), req.end(), sr);
    for(size_t i = 0; i < req.size() / 2; i++)
        swap(req[i], req[req.size() - 1 - i]);
    //cout << "req = "; copy(req.begin(), req.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    vector<int> req_t;
    for(size_t i = 0; i < req.size(); i++)
    {   if(i < req.size() - 1)
            {if(req[i] != req[i + 1]) req_t.push_back(req[i]); else i++;}
        else req_t.push_back(req[i]);
    }
    req.clear();
    copy(req_t.begin(), req_t.end(), back_inserter(req));
    k = req.size();
    //cout << "req = "; copy(req.begin(), req.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    ///end cleaning
    map<int, int> m;
    for(size_t i = 0; i < k; i++)
    {
        map<int, int> buf;
        buf = m;
        pair<int, int> p = make_pair(req[i], 1);
        m[p.first] += p.second;
        for(std::map<int, int>::iterator it = buf.begin(); it != buf.end(); it++)
        {
            lli tmp = nok_t((*it).first, p.first);
            if(tmp <= n)
                m[tmp] -= 2 * (*it).second * p.second;
        }
        /*
        cout << endl << i << endl;
        for(std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
            cout << (*it).first << " " << (*it).second << endl;*/

    }
    int result = 0;
    for(std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
        result += (int)(n / (*it).first) * (*it).second;
    cout << result << endl;
    //sum k in m (n /pk) *ik
    return 0;
}
