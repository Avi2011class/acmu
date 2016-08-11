#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
vector<string> V;
void step(string s1, string s2)
{
    if(s2.length() == 1) V.push_back(s1 + s2);
    else
    {
        string tmp1, tmp2;
        for(size_t i = 0; i < s2.length(); i++)
        {
            tmp1 = s1 + s2[i];
            tmp2 = s2;
            tmp2 = tmp2.erase(i, 1);
            step(tmp1, tmp2);
        }
    }
}
using namespace std;
int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    step("", s);
    sort(V.begin(), V.end());
    for(size_t i = 0; i < V.size(); i++)
        cout << V[i] << endl;
    return 0;
}

