#include <iostream>

class Foo {
public:
    Foo() {}

    /*  */
    Foo operator+(const Foo& rhs) {
        Foo f;
        f.a = a + rhs.a;
        std::cout << "call operator+(). " << std::endl;
        return Foo();
    }

private:
    int a;
};

int main() {
    Foo data1, data2;

    data1 + data2;
    data1.operator+(data2); //等价方法

    data2 + data1;
    data2.operator+(data1); //等价方法

}

