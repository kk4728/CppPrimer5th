#include <cctype>
#include <iostream>
#include <string>

int main()
{
	std::string str = "A1~`*xyz(&^%$#,]['?.; \v\t\r\n 0xABed8f";	
	std::cout << "test sting : " << str << std::endl;
	for(int i=0; i<str.size(); i++)
	{
		char ch = str[i];
		std::cout << ch << ": ";
		if(std::isalnum(ch)) std::cout << "alnum ";
		if(std::isalpha(ch)) std::cout << "alpha ";
		if(std::iscntrl(ch)) std::cout << "cntrl ";
		if(std::isdigit(ch)) std::cout << "digit ";
		if(std::isgraph(ch)) std::cout << "graph ";
		if(std::islower(ch)) std::cout << "lower ";
		if(std::isupper(ch)) std::cout << "upper ";
		if(std::ispunct(ch)) std::cout << "punct ";
		if(std::isspace(ch)) std::cout << "space ";
		if(std::isxdigit(ch)) std::cout << "xdigit";
		if(std::islower(ch)) str[i] = std::toupper(ch);
//		if(std::isupper(ch)) std::cout << "alnum ";
//
		std::cout << std::endl;
	}

	std::cout << str << std::endl;

	return 0;
}
