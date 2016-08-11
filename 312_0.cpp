#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long int a;
    long int b;
    long int d;
    long int n;
    long int result;
    fstream output;
    output.open("output.txt", ios::out);
    fstream input;
    input.open("input.txt", ios::in);
    input>>a>>b>>n;
    d=b-a;
    result=a+d*(n-1);
    output<<result;
    output.close();
    input.close();
}
