#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long long a;
    long long i;

    fstream output;
    output.open("output.txt", ios::out);
    fstream input;
    input.open("input.txt", ios::in);
    input>>a;
    input.close();
    i=a*a;
    output<<i;
    output.close();
}
