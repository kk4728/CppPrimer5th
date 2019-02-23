#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};	
	for(auto &r : v)
		r *= 2;

	for(auto r : v)
		std::cout << r <<" " ;

	return 0;
}

