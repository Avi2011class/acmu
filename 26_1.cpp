#include <iostream>
#include <fstream>
using namespace std;
fstream input;
fstream output;
int main()
{
input.open("input.txt",ios::in);
    output.open("output.txt",ios::out);
    double x1,x2,y1,y2,r1,r2,p;
    input>>x1>>y1>>r1>>x2>>y2>>r2;
    p=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    if ((p>(r1+r2)*(r1+r2))|(p<(r1-r2)*(r1-r2))) output<<"NO";
    else output<<"YES";
    output.close();
    return 0;
}
