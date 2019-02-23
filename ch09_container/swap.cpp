#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;



int main()
{
	vector<string> vs1(10, "vs1-0");
	vector<string> vs2(24, "vs2-0");
	
	swap(vs1, vs2);
	cout << vs1.size() << endl;
	cout << vs2.size() << endl;

	cout << *vs1.begin() << endl;
	cout << *vs2.begin() << endl;
	
	


	return 0;
}

