#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	string res;
	getline(cin, s);
	for (auto c : s)
	{
		if (!ispunct(c))
		{
			res += c;
			cout << c;
		}
	}
	cout << endl;
	cout << res << endl;
	system("pause");
	return 0;
}