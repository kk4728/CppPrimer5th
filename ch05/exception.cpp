#include <iostream>
#include <exception>
#include <stdexcept>

void test()
{
	try{
		throw "1212";
	}catch(std::runtime_error e) {
		std::cout << e.what() << std::endl;
	}catch(std::exception e) {
		std::cout << e.what() << std::endl;
	}

}


int main()
{
	test();

	return 0;
}

