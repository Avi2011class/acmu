#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;
int main(void)
{
    int n, k, t1, t2; cin >> n >> k;
    vector< vector<int> > v(n + 1);
    while (true)
    {
        cin >> t1;
        if(t1 == 0) break;
        else
        {
            cin >> t2;
            v[t1].push_back(t2);
        }
    }
    vector<bool> en(n + 1, false);
    en[k] = true;
    while(true)
    {
        bool flag = false;
        for(size_t i = 1; i <= n; i++)
            if(en[i])
                for(size_t j = 0; j < v[i].size(); j++)
                    if(!en.at(v[i][j]))
                    {
                        flag = true;
                        en[v[i][j]] = true;
                    }
        if(!flag) break;
    }
    int count = 0;
    for(std::vector<bool>::iterator it = en.begin(); it != en.end(); it++)
        if(*it) count++;
    if(count == n) cout << "Yes"<< endl; else cout << "No" << endl;
    return 0;
}
