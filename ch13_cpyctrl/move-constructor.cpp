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

int main()
{
    f();

    return 0;
}
