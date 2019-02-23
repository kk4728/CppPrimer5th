#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct connection
{
	string ip;
	int port;

	connection(string _ip, int _port) {
		ip = _ip;
		port = _port;
	}
};

struct destination
{
	string ip;
	int port;

	destination(string _ip, int _port){
		ip = _ip;
		port = _port;
	}
};

connection connect(destination* pDst)
{
	connection conn(pDst->ip, pDst->port);
	cout << "connect ( " << conn.ip << " : " << conn.port << " ) " << endl;
	return conn;
}

void disconnect(connection *pCon)
{

	cout << "disconnect ( " << pCon->ip << " : " << pCon->port << " ) " << endl;
}

void end_conn(connection *p)
{
	disconnect(p);
}

void f(destination &d)
{
	connection c = connect(&d);
	// 此时不能使用make_shared函数来初始化
	//shared_ptr<connection> sc = make_shared<connection>(&c, disconnect);
	//shared_ptr<connection> sc = make_shared<connection>(&c, end_conn);
	//shared_ptr<connection> sc (&c, end_conn);
	//shared_ptr<connection> sc1 (&c, disconnect); // ok
	

	shared_ptr<connection> sc (&c, [](connection *p){disconnect(p);});
}

int main()
{
	destination dst("127.0.0.1", 1215);
	f(dst);

	return 0;
}


