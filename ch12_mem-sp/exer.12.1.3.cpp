#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void process(shared_ptr<int> ptr)
{
	cout << "call process() : " << *ptr<< endl;
}

void f1()
{
	shared_ptr<int> p(new int(42));
	process(shared_ptr<int>(p));
	process(p);

	cout << "f1() test !" << endl;
}

void f2()
{
	shared_ptr<int> p(new int(2));
	process(shared_ptr<int>(p.get()));

	cout << "f2() test !" << endl;
}

void f12()
{
	auto p = new int();
	auto sp = make_shared<int>();

	process(sp);
//	process(new int());
//	process(p);
	process(shared_ptr<int>(p));

	cout << "f12() test !" << endl;
}

int main()
{
//	f1();
	//f2();
	f12();

	return 0;
}

