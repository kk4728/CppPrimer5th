#include <iostream>

#include <string>


using namespace std;

class A{
public:
    A() {}
    A(const A& a) {}
    //A(const A& a, size_t st) {}
    A(const A& a, char ch='A') {}


private:
};


void f()
{
    A a1;
    //A a2(a1);
    A a3(a1, 'c');
    A a4(a1, 100);
}

////////////////////////////////////////////
struct X {
	int i; //内置类型可移动
	std::string s; //string定义了移动操作
};

struct hasX {
	X mem; //X有合成的移动操作
};

void f1() {
	X x;
    //X &&x2 = x; //error 无法绑定左值
    X x3 = std::move(x);
	hasX hx, hx2 = std::move(hx);
}

////////////////////////////////////////////
struct Y {
    Y() = default;
    Y(const Y&) = default;
};
struct hasY {
    hasY() = default;
    hasY(hasY &&) = default;
    //hasY(const hasY &&) = default; //error
    Y mem; 
};

void f2() {
    hasY hy, hy2 = std::move(hy);
}

//////////////////////////////////////////////



int main()
{
    //f();
    //f1();
    f2();

    return 0;
}
