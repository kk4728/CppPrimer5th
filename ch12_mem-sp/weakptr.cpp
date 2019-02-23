#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class StrBlobPtr;

class StrBlob
{
	friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob() :data(make_shared<vector<string>>()) {

   }
    StrBlob(std::initializer_list<std::string> il) : data(make_shared<vector<string>>(il))  {

    }
    size_type size() const {
        return data->empty();
   }

    //add & delete
    void push_back(const std::string &t) {
    data->push_back(t);
    }

    void pop_back();

    //access
    std::string& front() {
    check(0, "front on empty StrBlob");
    return data->front();
    }
    std::string& back() {
        check(0, "pop_back on empty StrBlob");
    data->pop_back();
    }

    std::string& back() const {
        check(0, "pop_back on empty StrBlob");
    data->pop_back();
    }


    size_t use_count() {
        return data->size();
    }

	StrBlobPtr begin() ;
	StrBlobPtr end();


private:
    std::shared_ptr<std::vector<std::string>> data;

void check(size_type i, const std::string& msg) const {
    if(i >= data->size())
        throw out_of_range(msg);
    }
};

class StrBlobPtr {
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz=0) : 
	   wptr(a.data), curr(sz) { }
	string& deref() const {
		auto p = check(curr, "dereference past end");
		return (*p) [curr];
	}

	StrBlobPtr& incr()	{
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}

private:
	shared_ptr<vector<string>> check(size_t i, const string& msg ) const {
		auto ret = wptr.lock();
		if(! ret)
			throw std::runtime_error("unbound StrBlobPtr");
		if(i >= ret->size())
			throw std::out_of_range(msg);

		return ret;
	}

	std::weak_ptr<vector<string>> wptr;
	size_t curr;

};
StrBlobPtr StrBlob::begin() { 
		return StrBlobPtr(*this); 
	}

StrBlobPtr StrBlob::end() {
		auto ret = StrBlobPtr(*this, data->size());
		return ret;
	}

int main()
{

	return 0;
}

