#include <iostream>

using namespace std;

class A{	
public:
	A() {
		std::cout << "create the A obj \n";
	}

	~A(){
		std::cout << "delete this\n ";
		delete this;
	}

};

int main()
{
	A* pA = new A();
	
	delete pA;

		


	return 0;
}
