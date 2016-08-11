#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <set>
#include <stack>
using namespace std;

map<int, int> control_map;
map<int, int> reverse_map;
set<int, greater<int> > cubes;
stack<int> path;

void step(int a, int n, int l)
{
	if (a == 0)
	{
		//cout << "YES" << endl;
		stack<int> temp;
		while(!path.empty())
		{
			temp.push(path.top());
			path.pop();
		}
		while(!temp.empty())
		{
			cout << reverse_map[temp.top()] << " ";
			temp.pop();
		}
		exit(0);
	}
	if (a != 0 && n == 0)
		return;
	if (control_map[a] > n)
		return;
	else
	{
		control_map[a] = n;
		for(set<int>::iterator it = cubes.begin();
						it != cubes.end(); it++)
		{
			if (*it > l || *it > a)
				continue;
			path.push(*it);
			step(a - *it, n - 1, *it);
			path.pop();
		}

	}
}

int main(void)
{
	int a;
	cin >> a;
	for(int c = 1; c * c * c <= a; c++)
	{
		cubes.insert(c * c * c);
		reverse_map[c * c * c] = c;
	}
	step(a, 8, 2000000001);
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
