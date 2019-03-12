#include <string>
#include <memory>
#include <map>
#include <utility>
#include <iostream>

class StrVec
{
public:
    StrVec() : elements(nullptr), first_free(nullptr),
        cap(nullptr) { }
    StrVec(const StrVec &s) {
        auto newdata = alloc_n_copy(s.begin(), s.end());
        elements = newdata.first;
        first_free = cap = newdata.second;
    }
    StrVec &operator=(const StrVec& rhs) {
        auto data = alloc_n_copy(rhs.begin(), rhs.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
        return *this;
    }
    //StrVec(const StrVec &&s) noexcept  :
    StrVec(StrVec &&s) noexcept  :
        elements(s.elements), first_free(s.first_free), cap(s.cap) {
        s.elements = s.first_free = s.cap = nullptr;
    }
    //移动赋值运算符
    StrVec& operator=(StrVec &&rhs) noexcept {
        //直接检测自赋值
        if(this != &rhs) {
            free();
            elements = rhs.elements;
            first_free = rhs.first_free;
            cap = rhs.cap;
            rhs.elements = rhs.first_free = rhs.cap = nullptr;
        }
        return *this;
    }
    /*{}元素列表*/
    StrVec& operator=(std::initializer_list<std::string> il) {
        auto data = alloc_n_copy(il.begin(), il.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
        return *this;
    }
    ~StrVec() {
        free();
    }

    //////////////
    std::string& operator[](std::size_t n) {
        return elements[n];
    }
    //
    const std::string& operator[](std::size_t n) const {
        return elements[n];
    }

    void push_back(const std::string& s){
        chk_n_alloc(); //确保空间能容纳新元素
        //在first_free指向的元素中构造s的一个副本
        alloc.construct(first_free++, s);
    }
    void push_back(std::string &&s) {
        chk_n_alloc(); //如果需要的话重新分配内存
        alloc.construct(first_free++, std::move(s));
    }

    size_t size() const {
        return first_free - elements;
    }
    size_t capacity() const {
        return cap - elements; 
    }
    std::string *begin() const {
        return elements;
    }
    std::string *end() const {
        return first_free;
    }

private:
    std::string *elements;
    std::string *first_free;
    std::string *cap;

    static std::allocator<std::string> alloc; //声明

    std::pair<std::string*, std::string*> 
    alloc_n_copy(const std::string *b, const std::string *e) {
        auto data = alloc.allocate(e-b);
        return {data, std::uninitialized_copy(b, e, data)};
    }
    void free() {
        if(elements) {
            for (auto p = first_free; p != elements; ) 
                alloc.destroy(--p); //运行string的析构函数，释放自身分配的内存
            alloc.deallocate(elements, cap - elements); //释放StrVec对象分配的空间
        }
    }
    void chk_n_alloc() {
        if(size() == capacity())
            reallocate();
    }
    /*拷贝构造版
    void reallocate() {
        auto newcapacity = size() ? 2*size() : 1;
        auto newdata = alloc.allocate(newcapacity);
        auto dst = newdata;
        auto elem = elements;
        for (size_t i=0; i != size(); ++i)
            alloc.construct(dst++, std::move(*elem++));
        free();
        elements = newdata;
        first_free = dst;
        cap = elements + newcapacity;
    }
    */

    /*移动构造*/
    void reallocate() {
        //分配大小两倍于当前规模的内存空间
        auto newcapacity = size() ? 2*size() : 1;
        auto first = alloc.allocate(newcapacity);
        //移动元素
        auto last = uninitialized_copy(
            make_move_iterator(begin()),
            make_move_iterator(end()),
            first);
        free(); //释放旧空间
        elements = first; //更新指针
        first_free = last;
        cap = elements + newcapacity;
    }
};

std::allocator<std::string> StrVec::alloc; // 定义，初始化

void test() {
    StrVec sv;
    std::string s = "some string or another";
    sv.push_back(s); //调用push_back(const string& ) ；s为左值

    //调用的差别在于实参是一个左值还是一个右值(从“done”创建的临时对象)
    sv.push_back("done"); //调用push_back(string&&)

    StrVec v1;
    v1 = {"a", "new", "dog"};
    std::cout << v1[0] << std::endl;
}

int main()
{
    test();

    return 0;
}
