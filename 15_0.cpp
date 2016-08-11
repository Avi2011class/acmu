#include <iostream>
#include <fstream>

using namespace std;
fstream input,output;
bool in(int p[1000],int y)
{


bool result;
result=false;
for(int i=1;i<=1000;i++)
if (p[i]==y) result=true;
return result;
}
int main()
{
input.open("input.txt",ios::in);
output.open("output.txt",ios::out);
long summ,a,m;
summ=0;
input>>m;
m=m*m;
for(int i=1;i<=m;i++)
{
input>>a;
if (a==1)
{
summ++;
}
}
output<<summ/2;

input.close();
output.close();


}
