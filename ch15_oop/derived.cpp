#include <iostream>



class Base {
protected:
	int prot_mem;
};

class Sneaky : public Base {
	friend void clobber(Sneaky&);
	friend void clobber(Base&);

	int j;
};

void clobber(Base& b) {
	//b.prot_mem = 0; //无法在派生类友元函数中通过基类对象访问protected成员
}

void clobber(Sneaky& s) {
	s.j = s.prot_mem = 0;
}

int main() 
{


}
