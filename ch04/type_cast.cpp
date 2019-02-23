#include <iostream>
#include <string>

void cast_static() {


}

void cast_const()
{
	const char* psc = "haha!"; //psc: low-level const
	
//	char* pc = static_cast<char*>(psc);
	std::string s = static_cast<std::string>(psc);	
//	std::string s1 = const_cast<std::string>(psc);	
	char* pcc = const_cast<char*>(psc);
}

void cast_reinterpret() {


}

int main()
{


	return 0;
}


