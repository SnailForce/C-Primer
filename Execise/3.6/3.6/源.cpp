#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	for (auto& c : s)
	{
		c = 'X';
	}
	cout << s << endl;
	cout << s.size() << " " << s.length() << endl;  // 5 5
	cout << sizeof(s) << endl;  // 28
	int t = 0;
	cout << sizeof(t) << endl;  // 4
	system("pause");
	return 0;
}