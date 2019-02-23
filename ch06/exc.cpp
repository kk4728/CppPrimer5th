#include <vector>

//6.54
int f(int , int);

typedef int (*PF)(int, int);

std::vector<PF> g_1;

std::vector<decltype(f)*> g_2;

//6.55
int add(int ,int);
int sub(int, int);
int mul(int, int);
int div(int, int);
void exe655() {
	g_1.push_back(add);
	g_1.push_back(sub);
	g_1.push_back(mul);
	g_1.push_back(div);
}
