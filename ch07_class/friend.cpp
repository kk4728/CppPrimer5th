

struct X {
	friend void f() {};
	void f();
	X() { f(); }

};
