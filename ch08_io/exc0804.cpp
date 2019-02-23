#include <iostream>
#include <fstream>
#include <string.h>

int main()
{
	char buf[80];
	std::ifstream  ifile;
	ifile.open("log.dat");
	if(ifile){
		while(ifile) {
			memset(buf, 0x00, 80);
			ifile.getline(buf, 80);
			std::cout << buf << std::endl;
		}
	}


    return 0;
}

