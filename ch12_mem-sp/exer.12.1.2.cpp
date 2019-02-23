#include <iostream>
#include <memory>
#include <vector>

using namespace std;

shared_ptr<vector<int>> revec2()
{
	return make_shared<vector<int>>();	
}

std::vector<int>* revec()
{
	vector<int> *pvi = new vector<int>();
	return pvi;
}

void f126(vector<int>* p)
{
	int i;
	while(cin>>i)
	{
		p->push_back(i);
	}
}

void print(const vector<int> & vi) {
	cout << "======================" << endl;
	for(auto & n : vi)
		cout << n << endl;
}


int main()
{
//	std::vector<int> * p = revec();
//	shared_ptr<vector<int>> p = revec2();
	shared_ptr<vector<int>> p = make_shared<vector<int>>();
	f126(p.get());
	print(*p);

//	delete p;

	return 0;
}

