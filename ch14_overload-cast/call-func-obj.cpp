#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>

struct absInt {

    int operator() (int val) const {
        return val<0 ? -val : val; 
    }
};

void f() {
    int i = -42;
    absInt  abjObj;

    std::cout << "f() : " << abjObj(i) << std::endl;
}

//////////////////////////////////
class PrintString {
public:
    PrintString(std::ostream &o = std::cout, char c=' ') :
        os(o), sep(c) { }

    void operator() (const std::string &s) const {
        os << s << sep; 
    }
private:
    std::ostream &os;
    char sep;
};

void f1() {
    std::string s = "hello world!";
    PrintString printer;
    printer(s);
    //
    PrintString error(std::cerr, '\n');
    error(s);

    //
    std::vector<std::string> vs = {"a", "new", "day"};
    //第三个参数是临时对象
    std::for_each(vs.begin(), vs.end(), PrintString(std::cerr, '\n'));
}

///////////////////////////////////////////////std::
void f2() {
    std::plus<int> intAdd; 
    std::negate<int> intNegate;
    //
    int sum = intAdd(10, 20);
    sum = intNegate(intAdd(10, 20));
    //
    sum = intAdd(10, intNegate(10));

    std::cout << "plus<int> : " << intAdd(10, 20) << std::endl;
}

void f3() {
    using std::string;

    std::vector<std::string*> nameTable; // 指针的vector

    //error! 虽然编译器不报错，但危险
    //nameTable中的指针批次之间没有关系，所以将产生未定义的行为
    std::sort(nameTable.begin(), nameTable.end(), 
        [](std::string *a, string *b) {return a < b; } );

    //ok,标准库定义的指针less是定义良好的
    std::sort(nameTable.begin(), nameTable.end(), std::less<string*>());

}

///////////////////////////////////////////////////////////////////
//普通函数
int add(int i, int j) {
    return i + j;
}
//lambda表达式
auto mod = [](int i, int j) { return i % j; };
//函数对象类
struct divide
{
    int operator() (int denominator, int divisor) {
        return denominator / divisor;
    }
};

void f4() {
    std::map<std::string, int(*)(int, int)> binops;

    binops.insert({"+", add}); // {"+", add} 是一个pair
    binops.insert({"+", mod}); //C++11中错误，GCC6.4.0可以编译

}

int main() {

    //f();
    //f1();
    //f2();
    //f3();
    f4();

    return 0;
}
