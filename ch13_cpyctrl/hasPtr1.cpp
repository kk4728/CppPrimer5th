#include <iostream>
#include <string>
#include <memory>
using namespace std;

class HasPtr
{
    friend size_t print(const HasPtr& hp) ;
public:
    HasPtr(const string &s = std::string()) :
        ps(new string(s)), i(0), use(new size_t(1)) {}

    HasPtr(const HasPtr &p) : 
        ps(p.ps), i(p.i), use(p.use) { ++*use; }

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

    ~HasPtr() {
        cout << "call ~HasPtr() " ;
        if(--*use == 0) {
            delete ps; delete use;
            cout << "\t-------> delete HasPtr " ;
        }
        cout << endl;
    }

private:
    string *ps;
    int i = 0;
    size_t *use;
};

size_t print(const HasPtr& hp)
{
    cout << "use counte: " << *hp.use << 
        "  &: " << hp.use<< endl;
}


int main()
{
    HasPtr hp1;  print(hp1);
    HasPtr hp2;  print(hp2);
    HasPtr hp3 = hp1; print(hp3);
    HasPtr hp4; print(hp4);
    hp4 = hp2; print(hp4); print(hp2);
}
