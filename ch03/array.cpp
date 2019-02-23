#include <iostream>
//#include <cctype>

void f()
{
	int ia[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};
	int ia1[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};

	int (&row) [4] = ia[1];
	
	size_t cnt = 0;
	for(auto &row : ia)
		for(auto &col : row) {
			col = cnt;
			++cnt;
	}
}
