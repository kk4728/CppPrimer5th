#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <deque>
#include <array>

using namespace std;


int main()
{
	vector<string> vs;
	list<string> ls;

	vs.insert(vs.begin(), "vs001");
	ls.insert(ls.begin(), "ls001");
	
	cout << "vs:size: " << vs.size() << " index 0: -> " << *vs.begin() << endl;
	cout << "ls:size: " << ls.size() << " index 0: -> " << *ls.begin() << endl;

	return 0;
}


