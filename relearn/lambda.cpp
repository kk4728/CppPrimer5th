#include <iostream>


using namespace std;

//捕获列表、参数列表均为空
void lmd()
{
    auto f = [] { return 42; };
    cout << f() << endl;
}

//捕获列表不为空，参数列表带参数
void f1(size_t st) {
    //
    auto f = [st](int num) {cout << "num:" << num << 
        "\tsize: " << st <<endl; };
    f(100);

    //
    size_t v1 = 108;
    auto fv = [v1] { return v1; } ;
    cout << fv() << endl;

    //值拷贝
    int a = 1;
    double b = 2.0f;
    auto fvi = [a, b] { cout << "a:" << a << " b:" << b << endl;};
    fvi();
    a += 10;
    b += 2.1415926;
    fvi(); //a,b值未变。值捕获的变量在创建时已拷贝，而不是在调用时。
}

//值捕获与引用捕获
void f2() {
    int a = 100;
    char ch = 'A';
    auto flmd = [&,ch] {};
}

//可变lambda
void f3() {
    size_t v = 42;
    auto f = [&v] () mutable {return ++v;};
    v = 0;
    cout << "f() res: " << f() <<" v:" << v << endl;
}

//含返回类型的lambda必须使用尾置指针
void f4(){
    auto f = [](int i) -> int {return i>=0 ? -i : -i; };
    cout << "lambda return : " << f(-10) << endl;
}

int main() {
    //lmd();
    //f1(48);

    //f3();
    f4();

    return 0;
}

