#include <iostream>
#include <list>
#include <deque>
#include <string>
#include <vector>



using namespace std;

void exc_9_11(){
	//1
	vector<int> a;
	vector<int> a1(10, 1);
	vector<int> b=a;
	vector<int> c(b);
	vector<int> e(a1.begin(), a1.end());
	vector<int> f(100);
}

void exc_9_13() {
	list<int> a1 = {0,1,2,3,4,5,6,7,8};	
	vector<double> a2(a1.begin(), a1.end()); 
	vector<int> a3(a1.begin(), a1.end()); 

}

void exc_9_3_2() {
	vector<int> vi = {0,1,2,3,4,5,6,7,8};	

	vi.front() = 100;
	
	cout << "[]: 0 " << vi[0] << endl;
	cout << "at: 0 " << vi.at(0) << endl;
	cout << "begin: 0 " << *vi.begin() << endl;
	cout << "front: 0 " << vi.front() << endl;
}


int main() 
{
	exc_9_3_2();

	return 0;
}


