#include <iterator>
#include <algorithm>
#include <numeric>
include <iostream>

using namespace std;




void f() {
	istream_iterator<int> in(cin), eof;
	cout << accumulate(in, eof, 0) <<endl;

}


int main() {
	f();

	return 0;
}
