#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> vs ;

    {
	vector<string> vss = {"a","an","the"};
	vs = vss;
	for(auto & it : vss)
	{
	    cout << "vss: " << it << " & " << &it << endl;
	}
	cout << endl;
    }

     
    for(auto & it : vs)
    {
        cout << "vss: " << it << " & " << &it << endl;
    }
    cout << endl;

    return 0;
}

