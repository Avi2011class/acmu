#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
    long long a;
    long long b;
    fstream output;
    output.open("output.txt", ios::out);
    fstream input;
    input.open("input.txt", ios::in);
    input>>a;
    output<<a/6<<" "<<a*2/3<<" "<<a/6;
    output.close();
    input.close();
}
