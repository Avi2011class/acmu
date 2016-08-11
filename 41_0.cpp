#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;
vector<int> a;
void qsort(int start, int stop)
{
    if(start < stop)
    {
        srand(time(0));
        int k = start + rand() % (stop - start);
        qsort(start, k);
        qsort(k + 1, stop);
        vector<int> b;
        b.clear();
        int i0 = start, j0 = k + 1;
        while(i0 <= k && j0 <= stop)
            if(a[i0] < a[j0])
            {
                b.push_back(a[i0]);
                i0++;
            }
            else
            {
                b.push_back(a[j0]);
                j0++;
            }
            for(i0; i0 <= k; i0++) b.push_back(a[i0]);
            for(j0; j0 <= stop; j0++) b.push_back(a[j0]);
            for(int i0 = start, i1 = 0; i0 <= stop; i0++, i1++)
                a[i0] = b[i1];
    }


}
int main(void)
{
    srand(time(0));
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count, tmp; cin >> count;
    for(size_t j = 0; j < count; j++) { cin >> tmp; a.push_back(tmp); }
    //for(size_t j = 0; j < count; j++) cout << a[j] << " "; cout << endl;
    qsort(0, a.size() - 1);
   // cout << "------------------------------------------------------" << endl;
    for(size_t j = 0; j < count; j++) cout << a[j] << " "; cout << endl;
    return 0;
}
