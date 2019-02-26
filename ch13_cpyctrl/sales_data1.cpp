#include <iostream>

#include <string>

class Sales_data
{
public:
    Sales_data() = default;
    Sales_data(const Sales_data&) = default;
    Sales_data& operator=(const Sales_data&);
    ~Sales_data() = default;
private:

};

Sales_data& Sales_data::operator=(const Sales_data&) = default;

