#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>


using namespace std;
using namespace std::placeholders;


auto f = [] { return 42; };

auto f2 = [](const string& s1, const string& s2) { return s1.size(), s2.size(); }; 

//auto f3 = (const string& s1, const string& s2) [] { return s1.size(), s2.size(); }; 

//auto  f4 = [sz] (const string& s) {
//	return sz <= s.size();
//};

bool check_size(const string& a, string::size_type sz) {
	return a.size() > sz; 
}

void test(size_t sz) {

	cout << "lambda f: " << f() << endl;

	vector<string> vs;

	stable_sort(vs.begin(), vs.end(), 
		[](const string& s1, const string& s2) 
		{ return s1.size(), s2.size(); } );

	stable_sort(vs.begin(), vs.end(), f2);

	
	[](const string& s1, const string& s2) { return s1.size(), s2.size(); }; 

	//[sz] (const string& s) { return s.size() > sz; };
	auto wc = find_if(vs.begin(), vs.end(), 
			[sz] (const string& s) {return s.size()>sz;});
	auto wc1 = find_if(vs.begin(), vs.end(), 
			bind(check_size, std::placeholders::_1, sz));
}


void fcn3() {
	size_t v = 42;
	auto f = [v] () mutable { return ++v; };
	v = 0;

	auto j = f();
	cout << "fcn3: " << j << endl; // output: 43
}

void fcn4() {
	size_t v = 42;
	auto f = [&v]() { return ++v; };
	v = 0;
	cout << "fcn4: " << f() <<endl; //output -> 1
}

void f5() {
	vector<int> vi;
	transform(vi.begin(), vi.end(), vi.begin(), [] (int i) { return i<0? -i : i; });
}

void f6() {
	vector<int> vi;
	transform(vi.begin(), vi.end(), vi.begin(), [] (int i) { 
			if(i<0) return -i;	else return i; });
}

void f7() {
	vector<int> vi;
	transform(vi.begin(), vi.end(), vi.begin(), [] (int i) -> int { 
			if(i<0) return -i;	else return i; });
}


void f8() {

}



int main()
{

	fcn3();
	fcn4();

    return 0;
}

