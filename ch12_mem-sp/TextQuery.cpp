#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <sstream>

using namespace std;

string make_plural(size_t ctr, const string &word,
	const string &ending) {
	return (ctr>1) ? word+ending : word;
}

class QueryResult
{
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult(string s, shared_ptr<set<line_no>> p, 
		shared_ptr<vector<string>> f) : 
		sought(s), lines(p), file(f) {

		}


private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
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
			//cout << text << endl;
			int n = file->size()-1;
			istringstream line(text);
			string word;
			while(line>>word) {
				auto &lines = wm[word];
			//	cout << word << " ";
				if (!lines)
					lines.reset(new set<line_no>);
				lines->insert(n);
			}
			//cout << endl;
		}	
	}

	QueryResult query(const string&) const;
	//const string& query(const string & s) const {
	//	return s;
	//}

private:
	vector<string> m_text;
	std::shared_ptr<vector<string>> file;	
	map<string, shared_ptr<set<line_no>>> wm;
};

QueryResult
TextQuery::query(const string &sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

//const ostream& print(ostream &c, const string &s) { //error
//ostream& print(const ostream &c, const string &s) { //error
ostream& print(ostream &os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " " <<
	make_plural(qr.lines->size(), "time", "s") << endl;

	for(auto num : *qr.lines)
		os << "\t(lines " << num+1 << ") " << 
		*(qr.file->begin() + num) << endl;

	//cout << "==================================" << endl;

	return os;
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

	ifstream infile("TextQuery.cpp");
	runQueries(infile);

	return 0;
}
