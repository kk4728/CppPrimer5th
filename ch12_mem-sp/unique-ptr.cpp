#include <memory>
#include <iostream>
#include <string>

#include <stdio.h>

using namespace std;

void test()
{
	unique_ptr<string> p (new string("1111111190831"));
	unique_ptr<string> p1(p);
	unique_ptr<string> p2;
	p2 = p1;
	
	//
	cout << "p->: " << *p << " | p: "  <<  endl;
	p.release();
	//cout << p << endl;
	//printf("0x%p\n", p);
}

void f1()
{
	unique_ptr<string> p1(new string("Stegosaurus"));
	cout << "p1: " <<  *p1 << endl;
	unique_ptr<string> p2(p1.release());
//	cout << "p1: " <<  *p1 << endl;
	cout << "p2: " <<  *p2 << endl;
	unique_ptr<string> p3(new string("Trex"));
	cout << "p3: " <<  *p3 << endl;
	p2.reset(p3.release());
	cout << "p2: " <<  *p2 << endl;
	cout << "p3: " <<  *p3 << endl;
}

class A
{	
public:
	A() {
		cout << "create A() " << endl;
	}

	~A() {
		cout << "~A() " << endl;
	}

};

int main()
{
	//test();
	f1();
	
//	unique_ptr<A> p(new A());

//	p.release();
//	p.reset();
//	p.reset(nullptr);

//	while(1);

	return 0;
}

