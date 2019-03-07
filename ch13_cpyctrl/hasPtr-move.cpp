#include <iostream>
#include <string>
#include <memory>
using namespace std;

class HasPtr
{
    friend size_t print(const HasPtr& hp) ;
    friend inline void swap(HasPtr& ,HasPtr&);
public:
    HasPtr(const string &s = std::string()) :
        ps(new string(s)), i(0), use(new size_t(1)) {

    }
    HasPtr(const HasPtr &p) : 
        ps(p.ps), i(p.i), use(p.use) { 
        ++*use; 
        cout << "copy constructor : " << this << endl;
    }
    HasPtr(HasPtr &&p) noexcept :
        ps(p.ps), i(p.i) {
        p.ps = 0; //将指针置为0，确保移后源对象析构安全。
        cout << "move constructor ! " << endl;
    }
    //赋值运算符里，使用非引用参数。意味着参数要进行拷贝初始化。依赖于
    //实参的类型，拷贝初始化要么使用拷贝构造，要么使用移动构造。 单一的
    //的赋值运算符就实现了拷贝赋值和移动赋值运算符两种功能。
    HasPtr& operator=(HasPtr rhs) {
        swap(*this, rhs);
        return *this;
    }
    /*
    HasPtr& operator=(const HasPtr& rhs) {
        ++*rhs.use; //递增右侧对象的引用计数
        if(--*use == 0) { //递减本对象的引用计数
            delete ps;
            delete use;
        }
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }
    */
    /*
    HasPtr& operator=(HasPtr rhs) {
        cout << "call swap() in operator=()" << endl;
        swap(*this, rhs);
        return *this;
    }
    */

    ~HasPtr() {
        cout << this << " call ~HasPtr() " ;
        if(--*use == 0) {
            delete ps; delete use;
            cout << "\t-------> delete HasPtr " ;
        }
        cout << endl;
    }

    bool operator<(const HasPtr& h) const 
    {
        return (*ps < *h.ps);
    }

private:
    string *ps;
    int i = 0;
    size_t *use;
};

inline 
void swap(HasPtr& lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
    swap(lhs.use, rhs.use);
}

size_t print(const HasPtr& hp)
{
    cout << "use counte: " << &hp << 
        "  &: " << hp.use<< endl;
}


int main()
{
    HasPtr hp, hp2;

    //hp2是左值，因此移动构造函数是不可行的。rhs将使用拷贝构造进行初始化。
    //拷贝构造分配一个新的string，并拷贝hp2指向的string
    hp = hp2;
    
    //hp将一个右值绑定到hp2上，此时拷贝构造和移动构造都是可行的。
    //但是实参是一个右值引用，移动构造函数是精确匹配的。移动构造从
    //hp2拷贝指针，而不会分配任何内存。
    hp = std::move(hp2);

    //不管使用拷贝构造还是移动构造，赋值运算符函数体都swap两个运算对象
    //的状态。交换对象的指针和成员，当rhs离开作用域时，这个string将销毁
}
