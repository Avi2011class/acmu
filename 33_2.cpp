#include <iostream>
#include <fstream>

using namespace std;
fstream input;
fstream output;
int main()
{

    input.open("input.txt",ios::in);
    output.open("output.txt",ios::out);
    int a,b,a1,b1;
    input>>a>>b;
    b1=a-1;
    a1=b-1;
    output<<a1<<" "<<b1;
    input.close();
    output.close();
    return 0;
}
