#include <iostream>
#include <fstream>
#include <limits.h>
using namespace std;
int m[100][100];
int main()
{
    fstream in,out; in.open("input.txt",ios::in); out.open("output.txt",ios::out);
    int n,start,stop,i0=0,j0=0;
    in>>n>>start>>stop; start--; stop--;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) in>>m[i][j];
    int b[100],c[100];
    for(int i=0;i<n;i++)
    {
        b[i]=INT_MAX; c[i]=0;
    }
    c[start]=1; b[start]=0; bool flag=true;
    while(flag)
    {
        for(int i=0;i<n;i++)
        {
            if(c[i]==1)
            {
                for(int j=0;j<n;j++)
                {
                    if((b[j]>b[i]+m[i][j])&(m[i][j]!=-1))
                    {
                        b[j]=b[i]+m[i][j]; c[j]=1;
                    }
                }
                 c[i]=0;
            }
        }
        int summ=0;
        for(int i=0;i<n;i++) if(c[i]==1) summ++;
        if(summ==0) flag=false;
    }
    (b[stop]==INT_MAX)? out<<"-1" : out<<b[stop];
    in.close();
    out.close();

    //for(int i=0;i<n;i++) cout<<i+1<<"-"<<b[i]<<endl;
    //cout<<b[stop]; in.close(); out.close(); return 0;
}
