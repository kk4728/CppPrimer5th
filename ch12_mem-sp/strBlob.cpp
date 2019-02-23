#include <string>
#include <memory>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class StrBlob
{
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

private:
    std::shared_ptr<std::vector<std::string>> data;

    void check(size_type i, const std::string& msg) const {
	if(i >= data->size())
	    throw out_of_range(msg);
    }
};

void f1() {
	StrBlob b1;
	{
		StrBlob b2={"a", "an", "the"};
		b1 = b2;
		cout << "b2: " << b2.use_count() << endl;
		cout << "b1: " << b1.use_count() << endl;
		b2.push_back("about");
		cout << "b2: " << b2.use_count() << endl;
	}
	cout << "b1: " << b1.use_count() << endl;
}



int main() {
	f1();

}
