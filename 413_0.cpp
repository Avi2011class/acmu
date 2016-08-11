#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m, n, count = 0;
    cin >> m >> n;
    bool a[502][502];
    for(int i = 0; i < 501; i++)
        for(int j = 0; j < 501; j++)
            a[i][j] = false;


    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            char tmp; cin >> tmp; a[i][j] = ((tmp == '#') ? true : false);
        }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            if(a[i][j])
            {
                count++;
                int i0 = i, j0 = j;
                while(((i0<501)&&(j0<501))&&(a[i0+1][j0])) i0++;
                while(((i0<501)&&(j0<501))&&(a[i0][j0+1])) j0++;
               //cout<<i<<" "<<j<<" "<<i0<<" "<<j0<<endl;
                for(int i1 = i; i1 <= i0; i1++)
                    for(int j1 = j; j1 <= j0; j1++)
                        a[i1][j1] = false;
            }
        }
        cout << count;
    return 0;
}
