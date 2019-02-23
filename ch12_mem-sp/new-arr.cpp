#include <iostream>
#include <memory>
#include <string>

using namespace std;

void test()
{
	int num = 10;
	int *pia = new int[num];
	for(int i = 0; i<num; i++) 
		cout << *(pia+i) << " " ;
	cout <<endl;

	int *pib = new int[num](); //括号类不能有参数、初始化器
	for(int i = 0; i<num; i++) 
		cout << *(pib+i) << " " ;
	cout <<endl;

	typedef int arrT[42];
	int *p = new arrT; //编译器实际执行 int *p = new int[42];

	auto *p1 = new char[12]; //ok
	auto p2 = new char[12]; //ok

	char ch[0];
	char *pc = new char[0];
	cout << *pc << endl;
}

int main()
{
	test();

	return 0;
}

