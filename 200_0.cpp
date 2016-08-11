#include <iostream>
#include <cmath>
#include <cstdio>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    set<int> fk;
    int i = 2;
    int k0 = k;
    while(k0 != 1)
        if(k0 % i == 0)
        {
            fk.insert(i);
            k0 = k0 / i;
        }
        else
        {
            i++;
        }
    int res = 1000000000;

    for(set<int>::iterator it = fk.begin(); it != fk.end(); it++)
    {
         int count = 0;
         int cur = *it;
         while( cur <= n)
         {
             count += n / cur;
             cur *= *it;
         }
         int mn = 1;
         cur = (*it);
         while(k % (cur * (*it)) == 0)
         {
             cur *= (*it);
             mn++;
         }
         //cout << *it << " " << mn << " " << count << endl;
         res = min(res, count / mn);
    }
    cout << res << endl;
    return 0;
}
