#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
int abs(int x,int y){return (x>y)?x-y:y-x;}
int min(int x,int y){return (x>y)?y:x;}
int main(void)
{
    fstream in,out; in.open("input.txt",ios::in); out.open("output.txt",ios::out);
    int count=0;
    int a[30005], b[30005];
    in>>count;
    for(int i=0;i<count;i++) {in>>a[i]; b[i]=INT_MAX;}b[0]=0;
    for(int i=0;i<count;i++) {b[i+1]=min(b[i]+abs(a[i],a[i+1]),b[i+1]); b[i+2]=min(b[i]+3*abs(a[i],a[i+2]),b[i+2]); }
    out<<b[count-1];
    in.close(); out.close(); return 0;
}
