void f() {
	const int ci = 0, &cj = ci;
	decltype(ci) x = 0;
	decltype(cj) y = 2;
//	decltype(cj) z;
}
