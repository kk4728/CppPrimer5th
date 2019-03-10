#include <iostream>
#include <string>


using namespace std;

class A {
	friend istream& operator>>(istream&, A&);
public:

private:
	int a;
	string text;
};

istream&  operator>>(istream& is,  A& a) {
	is >> a.a >> a.text;
	if(is)
		cout << "operator>> ok ! " << "a: " << a.a << " text: " << a.text << endl;
	else {
		a = A();
		cout << "operator>> error! " << "a = A()" << endl;
	}

	return is;
}

int main (){
	A a;
	int n;
	cin >> a;

}

