#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin >> n;
    string s;
    getline(cin, s);
    for(size_t i = 0; i < n; i++)
    {
        getline(cin, s);
        while(s.length() % 3 != 0) s = "0" + s;
        int sum = 0;
        for(size_t i = 0; i < s.length(); i += 3)
            sum += (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + (s[i + 2] - '0');
        if(sum % 7 == 0) cout << "Yes" << endl; else cout << "No" << endl;
    }
    return 0;
}
