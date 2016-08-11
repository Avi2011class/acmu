#include <iostream>
#include <fstream>

int nod(int a,int b)
{
    if (a==b) return a;
    if(a>b) return nod(a-b,b);
    if (a<b) return nod(a,b-a);
}

using namespace std;

int main()
{
    int a;
    int b;
    long i;

    fstream output;
    output.open("output.txt", ios::out);
    fstream input;
    input.open("input.txt", ios::in);
    input>>a>>b;
    input.close();
    i=a*b/nod(a,b);
    output<<i;
    output.close();


}
