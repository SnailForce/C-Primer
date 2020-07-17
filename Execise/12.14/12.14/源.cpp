#include <bits/stdc++.h>
using namespace std;
class connection
{
public:
	string ip;
	int port;
	connection(string _ip, int _port) : ip(_ip), port(_port) {}
};
class destination
{
public:
	string ip;
	int port;
	destination(string _ip, int _port) : ip(_ip), port(_port) {}
};
connection connect(destination* pDest)
{
	shared_ptr<connection> pCoon(new connection(pDest->ip, pDest->port));
	cout << "create connection: (" << pCoon.use_count() << ")\n";
	return *pCoon;
}
void disconnect(connection pConn)
{
	cout << "connection close: (" << pConn.ip << ":" << pConn.port << ")\n";
}
void endConnection(connection* pConn)
{
	disconnect(*pConn);
}
void f(destination& d)
{
	connection conn = connect(&d);
	shared_ptr<connection> p(&conn, endConnection);
	shared_ptr<connection> p(&conn, [](connection * p) {disconnect(*p); };
	cout << "connect now : (" << p.use_count() << ")\n";
}
int main()
{
	destination dest("202.118.176.67", 3316);
	f(dest);
	unique_ptr<destination, decltype(endConnection)*> p(&dest, endConnection);
	auto it = endConnection;
	it(new connection("202.118.176.67", 3316));
}