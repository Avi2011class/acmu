#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream output;
    output.open("output.txt", ios::out);
    fstream input;
    input.open("input.txt", ios::in);
    long long int a;
    long long int b;
    long long int c;
    long long int max1;
    long long int min1;
    long long int razn;
    input>>a>>b>>c;
    min1=a;
    if (b<=min1) min1=b;
    if (c<=min1) min1=c;
    max1=a;
    if (b>=max1) max1=b;
    if (c>=max1) max1=c;
    razn=max1-min1;
    output<<razn;
    output.close();
    input.close();
}
