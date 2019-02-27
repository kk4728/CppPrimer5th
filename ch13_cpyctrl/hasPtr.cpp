#include <string>
#include <iostream>

using namespace std;

class HasPtr
{
public:
    HasPtr(const std::string & s = std::string()) :
        ps(new std::string(s)), i(0) { 
        cout << "HasPtr() default constructor" << endl;
    }
    HasPtr(const HasPtr& p) :
        ps(new std::string(*p.ps)), i(p.i) { 
        cout << "HasPtr copy constructor" << endl;
    }
    HasPtr& operator=(const HasPtr& hp) {
        auto newp = new std::string(*hp.ps);
        delete ps;
        ps = newp;
        i = hp.i;
        cout << "assign constructor" << endl;

        return *this;
    }

    ~HasPtr() { 
        delete ps; 
        cout <<"\t" <<  ps << " ~HasPtr()" << endl;
    }

private:
    std::string *ps;
    int i;
};

int main() 
{
    HasPtr hp1("hp1");
    HasPtr hp2(hp1);
    HasPtr hp3 = hp2;
    hp3 = hp2;
    HasPtr *p = new HasPtr();

    for (int i = 0; i < 10; ++i)
    {
        HasPtr p;
    }

    return 0;
}
