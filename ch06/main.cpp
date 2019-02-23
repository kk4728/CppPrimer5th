#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	cout << argc << "\n";

	for(int i=0; i<argc; i++) {
		cout << i+1 << ": " << argv[i] << "\n";
	}

	cout << "over\n";

	return 0;
}
