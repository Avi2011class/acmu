#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, t1, t2;
    cin >> n >> m;
    vector< vector<int> > b(n);
    for(size_t i = 0; i < m; i++)
    {
        cin >> t1 >> t2;
        b[t1 - 1].push_back(t2 - 1);
    }
    bool flag = true;
    //for(size_t i = 0; i < n; i++){for(size_t j = 0; j < b[i].size(); j++) cout << b[i][j];cout << endl;}

    for(size_t i = 0; i < n; i++)
    {
        int start = i, now;
        vector<bool> enabled(n, false);
        enabled[start] = true;
        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            now = q.front();
            q.pop();
            for(size_t j = 0; j < b[now].size(); j++)
            {
                if(b[now][j] == start)
                {
                    flag = false;
                    while(!q.empty()) q.pop();
                }
                else if(!enabled[ b[now][j] ] )
                {
                    q.push( b[now][j] );
                    enabled[ b[now][j] ] = true;
                }
            }
        }
        if(!flag) break;

    }
    cout << ((flag) ? "Yes" : "No") << endl;
    return 0;
}
