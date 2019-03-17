#include <iostream>


class stm {
public:
    operator bool() {
        return true;
    }

};

void f1 () {
    stm s;
    if( !s) {

    }
}

//////////////////////////////////////////////////////
class SmallInt {
public:
    SmallInt(int i=0) : val(i) {
        if(i<0 || i>255)
            throw std::out_of_range("Bad SmallInt value");
    }
    operator int() const { return val; }

private:
    std::size_t val;
};

void f2() {
    SmallInt si;

    //将4隐式地转换成SmallInt,然后调用SmallInt::operator=
    si = 4; //隐式转换
    //将si隐式转换成int，然后执行整数加法 
    si + 3;
    //s1构造阶段： 将double 3.14转换成int，再调用SmallInt(int)
    SmallInt s1 = 3.14;
    //s1转换成int, 在转换成double
    s1 + 3.14 ;
}

//////////////////////////////////////////////////////
struct B;
struct A
{
    A() = default;
    A(const B&);
};
struct B 
{
    operator A() const;
};

void f3() {
    A f(const A&);
    B b;
    //A a = f(b); //二义性操作 f(B::operator A()) or f(A::A(const B&))
}

//////////////////////////////////////////////////////
struct A1
{
    //最好不要创建两个转换源都是算术类型的类型转换
    A1(int a= 0) {}
    A1(double) {}

    //最好不要创建两个转换对象都是算术类型的转换
    operator int() const {}
    operator double() const {}
};
void fA(long double) {}

void f4() {
    A1 a;
    //fA(a); //二义性错误，含义是A::operator int()
             //还是A::operator double() ?

    long lg;
    //A1 a1(log); //二义性错误： 含义是A::A(int) ? A::A(double)
}


int main()  {
    f1();
    f3();

    return 0;
}
