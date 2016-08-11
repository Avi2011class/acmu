#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

int main(void)
{
    int n, m, k, t;
    cin >> n >> m;
    vector<set<int> > V(n);
    for(size_t i = 0; i < m; i++)
    {
        cin >> k >> t;
        k--;
        t--;
        V[k].insert(t);
        V[t].insert(k);
    }
    vector<int> color(n + 3, 0);
    int iter = 0, cur;
    stack<int> st;
    while(iter < n)
    {
        color[iter] = 1;
        st.push(iter);
        while(!st.empty())
        {
            cur = st.top();
            st.pop();
            for(set<int>::iterator it = V[cur].begin(); it != V[cur].end(); it++)
            {
                if(color[*it] == 0)
                {
                    color[*it] = 3 - color[cur];
                    st.push(*it);
                }
                else if(color[*it] == color[cur])
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        while(color[iter] != 0)
            iter++;
    }
    cout << "YES" << endl;
    return 0;
}
