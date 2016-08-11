#include <iostream>
#include <vector>
#include <stack>
#include <functional>
#include <iterator>
#include <algorithm>
#include <set>
#include <map>


/*
	4 5
	1 2 3 1 10
	1 4 3 10 10
	1 5 5 5 5
	6 6 6 6 6
*/ 	
void climbDFS(std::map< std::pair< int, int >, int> & field, 
		  std::map< std::pair< int, int >, bool >  & enabled, 
		  int height, int width, 
		  std::pair< int, int > start)
{
	std::pair< int, int > next;
	
	next = start;
	next.first += 1;
	if ((next.first > -1) && (next.first < height) && (next.second > -1) && (next.second < width))
		if (field[next] >= field[start])
			if(!enabled[next])
			{
				enabled[next] = true;
				climbDFS(field, enabled, height, width, next); 
			}
			
	next = start;
	next.first -= 1;
	if ((next.first > -1) && (next.first < height) && (next.second > -1) && (next.second < width))
		if (field[next] >= field[start])
			if(!enabled[next])
			{
				enabled[next] = true;
				climbDFS(field, enabled, height, width, next); 
			}	
			
	next = start;
	next.second += 1;
	if ((next.first > -1) && (next.first < height) && (next.second > -1) && (next.second < width))
		if (field[next] >= field[start])
			if(!enabled[next])
			{
				enabled[next] = true;
				climbDFS(field, enabled, height, width, next); 
			}
			
	next = start;
	next.second -= 1;
	if ((next.first > -1) && (next.first < height) && (next.second > -1) && (next.second < width))
		if (field[next] >= field[start])
			if(!enabled[next])
			{
				enabled[next] = true;
				climbDFS(field, enabled, height, width, next); 
			}	
}

int main(void)
{
	
	
	int height, width;
	std::cin >> height >> width;
	std::map< std::pair< int, int >, int > field;	
	std::map< std::pair< int, int >, bool > enabled;
	
	std::vector< std::pair< int, std::pair< int, int > > > V;
	V.reserve(width * height);
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int t;
			std::cin >> t;
			field[ std::make_pair(i, j) ] = t;	
			V.push_back( std::make_pair(t, std::make_pair(i, j)) );
		}
	}	
	
	std::sort (V.begin(), V.end());	
	int counter = 0;	
	for (std::vector< std::pair< int, std::pair< int, int > > >::iterator it = V.begin(); it != V.end(); it++)
		if (!enabled[ it->second ])
		{		
			enabled[ it->second ] = true;
			climbDFS (field, enabled, height, width, it->second);					
			counter++;
		}
	std::cout << counter << std::endl;
	return 0;
}