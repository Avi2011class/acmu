#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>

int main(void)
{
	int n;
	std::cin >> n;
	std::vector< int > data;
	std::copy (std::istream_iterator< int >(std::cin),
				std::istream_iterator< int >(),
				std::back_inserter(data));
    int positive_sum = 0;
    int positive_count = 0;
    int negative_sum = 0;
	int negative_count = 0;
    std::for_each(data.begin(), data.end(),
		[&positive_sum, &positive_count, &negative_sum, &negative_count]
						(int & __value) -> void
		{
			positive_sum += (__value > 0) ? __value : 0;
			positive_count += (__value > 0) ? 1 : 0;
			negative_sum += (__value < 0) ? -__value : 0;
			negative_count += (__value < 0) ? 1 : 0;
		});
	std::function< bool(int&) > indicator;
	if (positive_sum >= negative_sum)
	{
		indicator = [](int & __value) -> bool {return __value > 0;};
		std::cout << positive_count << std::endl;
	}
	else
	{
		indicator = [](int & __value) -> bool {return __value < 0;};
		std::cout << negative_count << std::endl;
	}
	for (size_t i = 0; i < data.size(); i++)
		if (indicator(data[i]))
			std::cout << i + 1 << " ";
	std::cout << std::endl;

	return 0;
}
