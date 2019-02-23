#include <list>
#include <memory>
#include <iostream>

using namespace std;


void test()
{
	int *pi1 = new int;
	int *pi2 = new int();
	int *pi3 = new int(36);
	int *pi4 = new int{1024};
	int *pi5 = new int[10];

	cout << "pi1 " << pi1 << " " << *pi1 << endl;
	cout << "pi2 " << pi2 << " " << *pi2 << endl;
	cout << "pi3 " << pi3 << " " << *pi3 << endl;
	cout << "pi4 " << pi4 << " " << *pi4 << endl;
	
	cout << "==================================" << endl;
	const int *pci = new const int(1);
	const int *pci1 = new int(0);
	const int *pci2 = new int;
	const int *pci3 ;
	const string *pcs = new const string;

	int *pi22 = new (nothrow) int;

	auto pa = new auto(pi1);
	auto *pnb = new auto(pi1);
}

void func()
{
	shared_ptr<double> p1;
	shared_ptr<int> p2(new int(1024));
//	shared_ptr<int> p3 = new int(10);
	cout << "p1-> " << p1 << endl;
	cout << "p2-> " << p2 << endl;
}

int main()
{
//	test();
	func();

	return 0;
}


