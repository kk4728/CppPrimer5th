

#include <iostream>
#include <string>

void f() {
	int i = 42;
	int &&r1 = 100;
	//int &&r2 = i; //error
}

class A
{
public:
	A(int n) {

	}
private:
};

void f1() {
	int &&r1 = 42;
	int &&r2 = std::move(r1);

	std::cout <<"&&r2:" << r2 << std::endl;

	r2 = 100;
	std::cout <<"&&r2:" << r2 << std::endl;

	A &&a1 = 100;
	A &&a2 = std::move(a1);
}



int main()
{
	f1();


	return 0;
}
