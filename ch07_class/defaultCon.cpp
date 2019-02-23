#include <iostream>
#include <string>
#include <vector>

class  A
{
public:
	A() {
		std::cout << "default con. " << std::endl;
	}

	A(int n) {
		std::cout << "int n con. " << std::endl;
	}
	
	A(const A& a) {
		std::cout << "copy con. " << std::endl;
	}

	A& operator=(const A& a) {
		std::cout << "= con. " << std::endl;
	}

};

class B {
public:
	A a;
};

class NoDefault {
public:
	NoDefault(const std::string& );
	NoDefault()=default;
};

struct SA {
	NoDefault my_mem;
};

SA sa;


int main()
{
	//A a1;
	//A as[10];
    //A b = a1;	
	//A c;
	//c = b;
//	A aa(10);
//	B b;
//	A a3[3] = { 1, 2  };
//	static A ast;
//	static A ast1(100);

//	A a4(); //fuction 
//	A *pA = new A();
//	A* p1 = new A;
//	A* p2 = new A(100);

//	std::vector<A> av[3];

	return 0;
}


