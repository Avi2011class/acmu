#include <iostream>
#include <fstream>
using namespace std;
int h[1000];
 
void summa(long long int l)
{
    if (l!=1)
    {
    int k;
    k=2;
    while (l%k!=0) k++;
    h[k]++;
    summa(l/k);
    }
}
 
int main()
{
    long long int a;
    int summ;
    int mnoz;
    mnoz=1;
    fstream output;
    output.open("output.txt", ios::out);
    fstream input;
    input.open("input.txt", ios::in);
    input>>a;
    summa(a);
    h[1000]=0;
    for(int i=2;i<=1000;++i)
    {
        if (h[i]!=0) mnoz=mnoz*(h[i]+1);
    }
    output<<mnoz;
    output.close();
    input.close();
}