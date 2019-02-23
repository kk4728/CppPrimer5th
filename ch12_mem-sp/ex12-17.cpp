#include <memory>

using namespace std;

void f()
{
	int ix = 1024;
	int *pi = &ix;
	int *pi2 = new int(2048);

	typedef unique_ptr<int> IntP;

//	IntP p0(ix); 
//	IntP p1(pi); //err: new pointer

	IntP p2(pi2);
//	IntP p3(&ix);
	IntP p4(new int(2048));

//	IntP p5(p2.get());
}


int main()
{
	f();

	return 0;
}

