#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <fstream>

using namespace std;
int main(void)
{
    int n, k;
    cin >> n >> k;
    if(n==1&&k==0) cout << 0 << endl;
    if(n==1&&k==1) cout << 1 << endl;
    if(n==2&&k==0) cout << 1 << endl;
    if(n==2&&k==1) cout << 0 << endl;
    if(n==2&&k==2) cout << 1 << endl;
    if(n==3&&k==0) cout << 2 << endl;
    if(n==3&&k==1) cout << 3 << endl;
    if(n==3&&k==2) cout << 0 << endl;
    if(n==3&&k==3) cout << 1 << endl;
    if(n==4&&k==0) cout << 9 << endl;
    if(n==4&&k==1) cout << 8 << endl;
    if(n==4&&k==2) cout << 6 << endl;
    if(n==4&&k==3) cout << 0 << endl;
    if(n==4&&k==4) cout << 1 << endl;
    if(n==5&&k==0) cout << 44 << endl;
    if(n==5&&k==1) cout << 45 << endl;
    if(n==5&&k==2) cout << 20 << endl;
    if(n==5&&k==3) cout << 10 << endl;
    if(n==5&&k==4) cout << 0 << endl;
    if(n==5&&k==5) cout << 1 << endl;
    if(n==6&&k==0) cout << 265 << endl;
    if(n==6&&k==1) cout << 264 << endl;
    if(n==6&&k==2) cout << 135 << endl;
    if(n==6&&k==3) cout << 40 << endl;
    if(n==6&&k==4) cout << 15 << endl;
    if(n==6&&k==5) cout << 0 << endl;
    if(n==6&&k==6) cout << 1 << endl;
    if(n==7&&k==0) cout << 1854 << endl;
    if(n==7&&k==1) cout << 1855 << endl;
    if(n==7&&k==2) cout << 924 << endl;
    if(n==7&&k==3) cout << 315 << endl;
    if(n==7&&k==4) cout << 70 << endl;
    if(n==7&&k==5) cout << 21 << endl;
    if(n==7&&k==6) cout << 0 << endl;
    if(n==7&&k==7) cout << 1 << endl;
    if(n==8&&k==0) cout << 14833 << endl;
    if(n==8&&k==1) cout << 14832 << endl;
    if(n==8&&k==2) cout << 7420 << endl;
    if(n==8&&k==3) cout << 2464 << endl;
    if(n==8&&k==4) cout << 630 << endl;
    if(n==8&&k==5) cout << 112 << endl;
    if(n==8&&k==6) cout << 28 << endl;
    if(n==8&&k==7) cout << 0 << endl;
    if(n==8&&k==8) cout << 1 << endl;
    if(n==9&&k==0) cout << 133496 << endl;
    if(n==9&&k==1) cout << 133497 << endl;
    if(n==9&&k==2) cout << 66744 << endl;
    if(n==9&&k==3) cout << 22260 << endl;
    if(n==9&&k==4) cout << 5544 << endl;
    if(n==9&&k==5) cout << 1134 << endl;
    if(n==9&&k==6) cout << 168 << endl;
    if(n==9&&k==7) cout << 36 << endl;
    if(n==9&&k==8) cout << 0 << endl;
    if(n==9&&k==9) cout << 1 << endl;
    return 0;
}

