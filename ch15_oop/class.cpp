#include <iostream>


using namespace std;

class A {
public:
	A() = default;

	virtual ~A() =default;

	virtual void net_work() {
		cout << "A: net_work() " << endl;
	};

	void print() {}

protected:
	int a;
};

class B : public A {
public:
	void net_work() {
		cout << "B: net_work() " <<endl;
	}

	void print() {}
};

int main() {

	A a1 ;
	B b1 ;
	A *p1 = new A();
	A* p2 = new B();

	p1->net_work();
	p2->net_work();
	a1.net_work();
	b1.net_work();

	//a1.a;
	//b1.A::a;

	return 0;
}