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


int main()  {
    f1();

    return 0;
}
