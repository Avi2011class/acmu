#include <locale.h>
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
int min(int a, int b)
{
    return (a < b) ? a : b;
}
struct line
{
  int start, stop, len;
  void from(int xx, int yy, int zz)
  {
      start = xx;
      stop = yy;
      len = zz;
  }
};
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M, Len = 0, StartT, StopT, LenT;\
    line t;
    cin >> N >> M;
    vector<bool> a(N, false); a[0] = true;
    vector<line> b(0);
    for(size_t i = 0; i < M; i++)
    {
        cin >> StartT >> StopT >> LenT;
        t.from(StartT - 1, StopT - 1, LenT);
        b.push_back(t);
        t.from(StopT - 1, StartT - 1, LenT);
        b.push_back(t);

    }
    bool flag = true;
    while(flag)
    {
        int LM = 1000000000;
        int MR;
        for(size_t j = 0; j < b.size(); j++)
            if((a[b[j].start]) && (!a[b[j].stop]))
                if(LM > b[j].len)
                {
                    LM = b[j].len;
                    MR = j;
                }
        a[b[MR].stop] = true;
        Len += LM;
        flag = false;
        for(size_t i = 0; i < N; i++)
            if(!a[i])
            {
                flag = true;
                break;
            }
    }
    cout << Len;
    return 0;

}
