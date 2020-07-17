#include <iostream>
#include <string>
using namespace std;
int main()
{
	string ss;
	string ss1;
	getline(cin, ss);
	decltype(ss.size()) i = 0;
	while (ss[i] != '\0')
	{
		ss[i++] = 'X';
	}
	cout << ss << endl;
	system("pause");
	return 0;
}