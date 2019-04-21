#include <iostream>


using namespace std;

class A {
public:
	A() = default;

	//A& operator=(const A& ) = default;

	virtual ~A() =default;

	virtual void net_work() {
		cout << "A: net_work() " << endl;
	};

	void print() {
		cout << "m:addr: " << &m << endl;
		cout << "A::a:addr: " << &a << endl;
	}

public:
	int m;

protected:
	int a;
};

class B : public A {
public:
	void net_work() {
		cout << "B: net_work() " <<endl;
	}

	void print() {
		cout << "m:addr: " << &m << endl;
		cout << "a:addr: " << &a << endl;
	}

	//B& operator=(const B&) = default;
	//int m;
};

class D : public A {}; //OK
class D1 : private A {}; //OK
//class D2 : public A; // 声明中不能包含派生列表
//class D3 : public D3 {}; //不能以自己为基类(自身还未定义)

int main() {

	A a1 ;
	B b1 ;
	A *p1 = new A();
	A* p2 = new B();

	p1->net_work();
	p2->net_work();
	a1.net_work();
	b1.net_work();

	//a1.a;
	a1.m = 100;
	//b1.A::a;
	a1.print();
	b1.print();
	////////////////////

	//A 为基类；B为派生类
	A a11;
	//B b11 = a11; // 派生类对象无法赋值给基类
	//B b12(a11); // 没有找到匹配的构造函数
	//b11 = a11; //
	B b13;
	A a12(b13); // b13被截断，实际上B中只有基类部分初始化
	a11 = b13; //  b13被截断，实际上B中只有基类部分被赋值

	return 0;
}