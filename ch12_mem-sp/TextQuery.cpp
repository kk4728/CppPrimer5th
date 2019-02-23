#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <sstream>

using namespace std;

class QueryResult
{
public:
	


private:

};

class  TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(ifstream &infile) :
		file(new vector<string>)
	{
		string text;
		while(getline(infile, text)) {
			file->push_back(text);
			int n = file->size()-1;
			istringstream line(text);
			string word;
			while(line>>word) {
				auto &lines = wm[word];
				if (!lines)
					lines.reset(new set<line_no>);
				lines->insert(n);
			}
		}	
	}

	
//	QueryResult query(const string&) const;
	const string& query(const string & s) const {
		return s;
	}

private:
	vector<string> m_text;
	std::shared_ptr<vector<string>> file;	
	map<string, shared_ptr<set<line_no>>> wm;
};


//const ostream& print(ostream &c, const string &s) { //error
//ostream& print(const ostream &c, const string &s) { //error
ostream& print(ostream &c, const string &s) {

	return c;
}

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	
	while(true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if(!(cin>>s) || s=="q") break;
		//

		print(cout, tq.query(s)) << endl;
	}
}

int main() {

	return 0;
}
