#include <list>
#include <vector>
#include <string>
#include <deque>
#include <forward_list>


using namespace std;

void copy() {
	list<string> authors = {"Milton", "Shakespeare", "Auste"};
	vector<const char*> articles={"a", "an", "the"};

	list<string> list2(authors);
	//deque<string> authList(authors);
	//vector<string> words(articles);
	forward_list<string> words(articles.begin(), articles.end());

}
