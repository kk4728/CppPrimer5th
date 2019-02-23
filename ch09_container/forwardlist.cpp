#include <forward_list>
#include <iostream>

using namespace std;


int main()
{
	forward_list<int> fl = {9,8,7,6,5,4,3,2,1,0};
	auto pre = fl.before_begin();
	auto cur = fl.begin();
	while( cur != fl.end()) {
		if(*cur % 2) { //ji
			cur = fl.erase_after(pre);
		} else  {
			pre = cur;
			++cur;
		}
	}

	cout << "===============================\n";
	for(auto it = fl.cbegin(); it != fl.cend(); ++it) {
		cout << *it << endl;
	}

	return 0;
}


