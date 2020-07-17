#include <iostream>
using namespace std;
int main()
{
	const char* t = "abc";
	string s = static_cast<string>(t);
	cout << s << endl;
	s = "123";
	cout << t << " " << s << endl;
}