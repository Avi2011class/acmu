#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
#include <iterator>
using namespace std;
int main(void)
{
    int we, we0, we1;
    cin >> we0 >> we1;
    we = we1 - we0;
    int n;
    cin >> n;
    vector< pair<long long int, long long int> > money(n);
    for(size_t i = 0; i < n; i++)
        cin >> money[i].first >> money[i].second;

    vector<long long int> mi(we + 2, INT_MAX);
    mi[0] = 0;
    for(size_t i = 1; i <= we; i++)
        for(size_t j = 0; j < n; j++)
            if(money[j].second <= i)
                if(mi[i - money[j].second] != INT_MAX)
                    mi[i] = min(mi[i], mi[i - money[j].second] + money[j].first );

    vector<long long int> ma(we + 2, 0);
    ma[0] = 1;
    for(size_t i = 1; i <= we; i++)
        for(size_t j = 0; j < n; j++)
            if(money[j].second <= i)
                if(ma[i - money[j].second] != 0)
                    ma[i] = max(ma[i], ma[i - money[j].second] + money[j].first );

    for(size_t i = 0; i <= we; i++)
        ma[i] --;


    if(mi[we] == INT_MAX)
        cout << "This is impossible." << endl;
    else
        cout << mi[we] << " " << ma[we] << endl;
    return 0;
}
