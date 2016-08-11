#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long long a;
    long long b;
    fstream output;
    output.open("output.txt", ios::out);
    fstream input;
    input.open("input.txt", ios::in);
    input>>a>>b;
    if(a>b) output<<">";
    if(a==b) output<<"=";
    if(a<b) output<<"<";

    output.close();
    input.close();
}
