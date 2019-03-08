#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

void f() {
	int i = 42;
	int &&r1 = 100;
	//int &&r2 = i; //error
}

class A
{
public:
	A(int n) {

	}
private:
};

void f1() {
	int &&r1 = 42;
	int &&r2 = std::move(r1);

	std::cout <<"&&r2:" << r2 << std::endl;

	r2 = 100;
	std::cout <<"&&r2:" << r2 << std::endl;

	A &&a1 = 100;
	A &&a2 = std::move(a1);
}

//
class Foo {
public:
	Foo() {}
	Foo(const Foo& f) {}
	Foo& operator=(const Foo& f) & {//只能向可修改的左值赋值
		return *this;
	}
	Foo operator+(const Foo& f) { return f; }

	//////////////////////////////////////
	Foo sorted() &&;
	//Foo sorted() const ;//error:已经有一个sorted带 &&限定符，这里必须加
	Foo sorted() const &;

	using Cmp = bool(const int&, const int&);
	Foo sorted(Cmp*); //相对前面而言，这里不同的参数列表
	Foo sorted(Cmp*) const; //OK，两个版本都没有引用限定符

private:
	std::vector<int> data;
};
//本对象为右值，因此可以原址排序
Foo Foo::sorted() && {
	sort(data.begin(), data.end());
	return *this;
}
//本对象是const或一个左值，哪种情况我们都不能对其进行原地址排序
Foo Foo::sorted() const & {
	Foo ret(*this);
	sort(ret.data.begin(), ret.data.end());
	return ret;
}
void f2() {
	////////////////////////
	Foo f1, f2;
	Foo f3 = f1+f2;
	//f1+f2 = f3; //error：赋值运算符中有左值限定符 (f1+f2为右值)
}

int main()
{
	//f1();
	f2();

	return 0;
}
