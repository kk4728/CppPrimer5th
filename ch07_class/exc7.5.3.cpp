#include <vector>

class NoDefault{
public:
	NoDefault(int ) { }
	NoDefault() = default;
};

class C {
public:
	C()  {}		

	NoDefault nd;
};

int main()
{
	std::vector<NoDefault> vec(10);	
	std::vector<C> vecC(5);

	return 0;
}

