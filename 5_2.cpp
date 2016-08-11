#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
  int n; cin >> n;
  vector<int> a, b;
  int cur;
  for(size_t i = 0; i < n; i++)
  {
  	cin >> cur;
  	if(cur % 2 == 1) a.push_back(cur);
  	else b.push_back(cur);
  }
  
  for(std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
  	cout << *it << " ";
  cout << endl;
  for(std::vector<int>::iterator it = b.begin(); it != b.end(); it++)
  	cout << *it << " ";
  cout << endl;
  cout << ((a.size() <= b.size()) ? "YES" : "NO") << endl;
  return 0;
 }