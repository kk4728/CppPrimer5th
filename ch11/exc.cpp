#include <map>
#include <set>

#include <string>
#include <iostream>

using namespace std;

class Sales_data
{
public:
    int isbn() const {
        return m_isbn;
    }

private:
    int m_isbn;
};

bool compareIsbn(const Sales_data& lhs, 
    const Sales_data& rhs)
{
    //return lhs.isbn() < rhs.isbn();
    lhs.isbn();
    return false;
}


int main()
{
    typedef bool CMP(const Sales_data&, const Sales_data&);

    set<string> ss;
    multiset<string> mss;
    multiset<Sales_data, decltype(compareIsbn)*> mss1;
    multiset<Sales_data, decltype(compareIsbn)*> mss2(compareIsbn);
    multiset<Sales_data, CMP*> mss3;

    return 0;
}