#include <list>
#include <deque>
#include <string>

using namespace std;

int main()
{
	std::list<std::deque<int>> ld;
	
	list<string> ls = {"hevi", "jack", "bluent" };

	auto it1 = ls.begin();
	auto it2 = ls.cbegin();
	auto it3 = ls.rbegin();
	auto it4 = ls.crbegin(); 

    return 0;
}

