#include <memory>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Foo{

    int a;
    char male;
    double d;

    Foo(int i) {};
};

void func()
{
    shared_ptr<int> q = make_shared<int>(100);
    size_t n = q.use_count();
    cout << "count: " << n << endl;

}

shared_ptr<Foo> factory(int arg)
{

    int num = arg;
    return make_shared<Foo> (arg);
}

void use_factory(int arg)
{
    shared_ptr<Foo> p = factory(arg);

    shared_ptr<Foo> q = p;
}

int main()
{
    shared_ptr<int> p1;
    shared_ptr<int> p2 = make_shared<int>(42);
    shared_ptr<string> p3 = make_shared<string>(10,'9');
    shared_ptr<int> p4 = make_shared<int>();

    auto p5 = make_shared<vector<string>>();

    func();

    use_factory(100);

    return 0;
}

