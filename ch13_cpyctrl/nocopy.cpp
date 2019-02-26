#include <iostream>

struct NoCopy {
    NoCopy() = default; //合成的默认构造函数
    NoCopy(const NoCopy&) = delete;  //禁止拷贝
    NoCopy& operator=(const NoCopy&) = delete; //禁止拷贝
    //~NoCopy() = default; //合成的析构函数
    ~NoCopy() = delete;

    void print() const = delete;
};

struct NoDtor
{
    NoDtor() = default;
    ~NoDtor() = delete;
};

struct  A
{
    NoDtor nd;
};

void f()
{
    //NoDtor nd; // error: 析构函数是删除的
    NoDtor *p = new NoDtor();
    //delete p; //error: 析构函数是删除的

    //A a; //erro : 成员中含删除析构函数的
}

class PrivateCopy
{
    friend void Print( PrivateCopy pc) {

    }
public:
    PrivateCopy() = default; //使用合成的默认构造函数
    ~PrivateCopy() {} //用户可以定义该类型对象，但无法拷贝

private:
    //友元和成员函数仍旧可以拷贝对象，为了防止此情况。只声明，不定义。
    PrivateCopy(const PrivateCopy&);
    PrivateCopy& operator=(const PrivateCopy&);

};

void pcTest()
{
    PrivateCopy pc;
    //PrivateCopy pc1(pc);
    //PrivateCopy pc2 = pc;  

    Print(pc); //error!
}



int main()
{
    f();
    pcTest();

    return 0;
}











