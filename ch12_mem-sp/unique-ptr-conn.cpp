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

	unique_ptr<connection, decltype(end_conn)*> p(&c, end_conn);
	unique_ptr<connection, decltype(end_conn)> pi(&c, end_conn);
}


int main()
{
	destination dst("127.0.0.1", 121);
	f(dst);

	return 0;
}


