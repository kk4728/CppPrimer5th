#include <string>
#include <memory>
#include <map>
#include <utility>

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
    ~StrVec() {
        free();
    }

    void push_back(const std::string& s){
        chk_n_alloc();
        alloc.construct(first_free++, s);
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
};

std::allocator<std::string> StrVec::alloc; // 定义，初始化

void test() {
    StrVec sv;
}

int main()
{
    test();

    return 0;
}
