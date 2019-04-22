#include <iostream>
#include <string>

using namespace std;

class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :
		bookNo(book), price(sales_price) {}
		std::string isbn() const { return bookNo; }
		virtual double net_price(std::size_t n) const {
			return n*price;
		}
		virtual ~Quote() = default;

protected:
	std::string bookNo;

private:
	double price = 0.0;
};

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string & book, double price, std::size_t qty, double disc) : 
		Quote(book, price), quantity(qty), discount(disc) { }
	double net_price (std::size_t) const = 0;

protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double price, std::size_t qty, double disc) :
		Disc_quote(book, price, qty, disc) {}

	//覆盖基类中的函数版本以实现一种新的折扣策略
	double net_price(std::size_t) const override;

};

int main() {



	return 0;
}