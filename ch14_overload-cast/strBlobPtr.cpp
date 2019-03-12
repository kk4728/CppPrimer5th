#include <string>


class StrBlobPtr {
public:
    //前置版本
    StrBlobPtr operator++() {
        check(curr, "increment past end of StrBlobPtr");   
        ++curr;
        return *this;
    }
    StrBlobPtr operator--() {
        --curr;
        check(curr, "decrement past begin of StrBlobPtr");
        return *this;
    }

    //后置版本
    StrBlobPtr operator++(int) {
        StrBlobPtr ret = *this;
        ++*this; //使用前置版本
        return ret;
    }
    StrBlobPtr operator--(int) {
        StrBlobPtr ret = *this;
        --*this; //使用前置版本
        return ret;
    }

    /////
    std::string& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

private:
    size_t curr;

    void check(size_t st, const std::string& s) {

    }
};


int main() {

    StrBlobPtr ptr;
    ptr.operator++(0); //后置版本
    ptr.operator++(); //前置版本

    return 0;
}