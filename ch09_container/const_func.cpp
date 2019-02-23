#include <iostream>


using namespace std;


class A{
public:
	A() = default;

	void begin() {
		cout << "begin () " << endl;
	}

	void begin() const {
		cout << "begin () const " <<endl;
	}

private:


};




int main()
{
	A a1;
	const A a2;

	A* pA1 = &a1;
	const A* pA2 = &a1;
	A* const pA3 = &a1;
	const A* const pA4 = &a1;
	///////
	const A* pA6 = &a2;
	const A* const pA8 = &a2;

	a1.begin();
	a2.begin();
	cout << "==========================\n";

	pA1->begin();
	pA2->begin();
	pA3->begin();
	pA4->begin();
	cout << "==========================\n";

	pA6->begin();
	pA8->begin();


	return 0;
}
