#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;


void exc10_3() {
	vector<int> vi;

	for(int i=0; i<100; i++) {
		vi.push_back(i+1);
	}

	auto sum = accumulate(vi.cbegin(), vi.cend(), 0);

	cout << "accumulate: " << sum <<endl;
}

void exc10_4() {
	vector<double> vi;

	for(int i=0; i<100; i++) {
		vi.push_back(i+1.0);
	}

	auto sum = accumulate(vi.cbegin(), vi.cend(), 0.0);

	cout << "accumulate: " << sum <<endl;
}

void exc10_6() {
	vector<int> vi={1,2,3,4,5,6,7,8,9};
	fill_n(vi.begin(), vi.size(), 0);
	for(auto it=vi.cbegin(); it != vi.cend(); ++it)
		cout << *it << ", " ;
	cout <<endl;
}

void exc10_7() {
	vector<int> vec;
	list<int> lst;
	int i;	
	while(cin >> i) 
		lst.push_back(i);
	copy(lst.cbegin(), lst.cend(), vec.begin());
}

void exc10_7_b() {
	vector<int> vec;
	vec.reserve(10); //
	fill_n(vec.begin(), 10, 0);

}

void exc10_14() {
	auto f = [] (int a, int b) { return (a+b); };
	cout << "add: lambda: " << f(1,2) << endl;
}

void exc10_15(int n) {
	auto f = [n] (int a) { return a+n; };
	cout << " 10_15 res: " << f(100) << endl;
}


void exc10_28() {
	list<int> li;
	vector<int> vi;
	deque<int> di;

	vector<int> v = {1,2,3,4,5,6,7,8,9};

	copy(v.cbegin(), v.cend(), back_inserter(vi));
	copy(v.cbegin(), v.cend(), front_inserter(li));
	copy(v.cbegin(), v.cend(), inserter(di, di.begin()));
	for(auto it=vi.begin(); it != vi.end(); ++it)
		cout << *it << ", " ;
	cout <<endl;
		
	for(auto it=li.begin(); it != li.end(); ++it)
		cout << *it << ", " ;
	cout <<endl;

	for(auto it=di.begin(); it != di.end(); ++it)
		cout << *it << ", " ;
	cout <<endl;
}

void exc10_29() {
	fstream f("log.dat");
	vector<string>  vs;
	string line;
	while(getline(f, line))
		vs.push_back(line);

	ostream_iterator<string> out_iter(cout, "\n");
	copy(vs.cbegin(), vs.cend(), out_iter);
	cout << endl;

	f.close();

}

void exc10_34() {
	vector<int> vi = {1,2,3,4,5,6,7,8,9};
	vector<int>::reverse_iterator vri = vi.rbegin();
	copy(vri+4, vi.rend(), ostream_iterator<int>(cout, ","));
	//while(vri != vi.rend())
	//	cout << *vri++ << "," ;
	
	cout << endl;
}

void exc10_35() {
	vector<int> vi = {1,2,3,4,5,6,7,8,9};


}


int main() {
	//exc10_3();
	//exc10_4();
	//exc10_6();
	//exc10_7();
	//exc10_7_b();
	//exc10_14();
	//exc10_15(50);
	//exc10_28();
	//exc10_29();
	exc10_34();


	return 0;
}

