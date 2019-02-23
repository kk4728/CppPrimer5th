#include <iostream>


void f2_4_1()
{
	int i = 42;
	int &r1 = i;
	const int &r2 = i;
	r1 = 0;
	//r2 = 0;
}

void f2_4_2()
{
	const int i = 42;
	//int* ptr = &i;
	const int* ptr = &i;
	const int* const ptr2 = &i;

	//*ptr = 5;
}

void f_constexpr()
{
	const int max_files = 20;
	const int limit = max_files + 1;
	int staff_size = 27;

//	const int sz = get_size();
	
	constexpr int mf = 20;
	constexpr int limit1 = mf + 1;
//	constexpr int sz = size();


}





