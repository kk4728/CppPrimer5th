#include <iostream>
#include <string>
#include <vector>

using namespace std;

class A{
public: 
	A() {
		cout << "default constructor A() " << endl;
	}
	A(const A& ){
		std::cout << "copy construct A() " << std::endl;
	}

};

class Foo {
	friend void print(const Foo&)  ;

public:
	Foo() {// 默认构造
		m_i = 1;
		m_d	= 2.0f;
		m_str = "Hello Foo";
		for (int i = 0; i < 10; ++i)
		{
			m_ch[i] = 101+i;
		}

		cout << "Foo default constructor. " << endl;
	}

	//Foo(const Foo&) { // 拷贝构造
	//	std::cout << "copy construct Foo() " << std::endl;
	//}



private:
	int m_i;
	double m_d;
	char m_ch[10];
	std::string m_str;

	A m_a;
};

void print(const  Foo& f) 
{
	cout << "m_i : " << f.m_i << endl;
	cout << "m_d : " << f.m_d << endl;
	cout << "m_str: " << f.m_str << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << (int)f.m_ch[i] << " ";
	}
	cout << endl;
}

void test() {
	Foo  f1;
	cout << "==================================" << endl;
	Foo f2(f1);
	print(f1);
	cout << "============f2 ===========" << endl;
	print(f2);
}

/////////////////////////////////////////////////////////////
void f()
{
	std::vector<int> v1(10);
	vector<int> v2 = 10;
}

int main()
{
	//test();
	f();

	return 0;
}
