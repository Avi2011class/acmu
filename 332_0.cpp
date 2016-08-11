#include <iostream>
#include <fstream>

using namespace std;
fstream input,output;

int main()
{
input.open("input.txt",ios::in);
output.open("output.txt",ios::out);

int kolvo;
input>>kolvo;
kolvo++;

int m[500][500];

for(int i=1;i<kolvo;i++)
for(int j=i+1;j<=kolvo;j++)
{
input>>m[i][j];
}
int temp;
int h[500];
for(int i=kolvo-1;i>=1;i--)
{

temp=m[i][i+1]+h[i+1];

for(int j=i+1;j<=kolvo; j++)
{
if (temp>m[i][j]+h[j]) temp=m[i][j]+h[j];
}

h[i]=temp;
}

output<<h[1];

input.close();
output.close();


}
